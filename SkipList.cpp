#include"pch.h"
#include "SkipList.h"
#include <time.h>

///////////////////////////////////////////////////////////////////////////////
//DataInfo
void DataInfo::InitDataInfo()
{
	_value	= Invalid_Value;
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//NodeInfo
NodeInfo::NodeInfo() : _previous(nullptr), _next(nullptr)
{
}

NodeInfo::~NodeInfo()
{
}

void NodeInfo::InitNodeInfo()
{
	_previous.reset();
	_next.reset();
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//Node
void Node::InitNode()
{
	_dataInfo->InitDataInfo();
	_dataInfo.reset();

	for (auto nodeInfo : _nodeInfo_vector)
	{
		nodeInfo->InitNodeInfo();
		nodeInfo.reset();
	}

	_nodeInfo_vector.clear();
}
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//SkipList
void SkipList::InitSkipList()
{
	srand(static_cast<unsigned int>(time(NULL)));

	for (auto node : _index)
	{
		node->InitNode();
		node.reset();
	}

	_index.clear();
}

void SkipList::InsertNode(std::shared_ptr<DataInfo>&& dataInfo)
{
	auto node = std::make_shared<Node>();
	auto& node_dataInfo = node->dataInfo();
	auto& node_nodeInfo = node->nodeInfo();

	node_dataInfo = std::move(dataInfo);

	//////////////////////////////////////////
	auto IsAddIndexLevel = [](unsigned int& indexLevel)->bool
	{
		if (0 == (rand() % MaxRandomSize))
		{
			++indexLevel;
			return true;
		}

		return false;
	};
	//////////////////////////////////////////
	unsigned int indexLevel = BaseIndexLevel;

	if (_index.empty() == false)
	{
		unsigned int maxIndexLevel = _index.size() > 0 ? _index.size() - 1 : 0;
		valueType value = node_dataInfo->value();

		do {
			if (maxIndexLevel < indexLevel)
				maxIndexLevel = indexLevel;


			while (_index.size() > maxIndexLevel && _index[maxIndexLevel] == nullptr)
			{
				--maxIndexLevel;
				if (maxIndexLevel < BaseIndexLevel)
					break;
			}

			auto nodeInfo = std::make_shared<NodeInfo>();

			if (_index.size() == maxIndexLevel)
			{
				//해당레벨에 노드가 존재하지 않으므로 신규 추가
				node_nodeInfo.emplace_back(nodeInfo);
				_index.emplace_back(node);
			}
			else
			{
				auto targetNode = FindNode(std::move(value), std::move(_index[maxIndexLevel]),
					std::move(maxIndexLevel), std::move(indexLevel), true);

				if (targetNode != nullptr)
				{
					auto nextNode = targetNode->nodeInfo()[BaseIndexLevel]->next();
					nodeInfo->setNext(std::move(nextNode));

					targetNode->nodeInfo()[BaseIndexLevel]->setNext(std::move(node));
					nodeInfo->setPrevious(std::move(targetNode));

					node_nodeInfo.emplace_back(nodeInfo);
				}
				else
				{
					nodeInfo->setNext(std::move(_index[indexLevel]));

					node_nodeInfo.emplace_back(nodeInfo);

					if (indexLevel >= _index.size())
						_index.emplace_back(node);
					else
						_index[indexLevel] = node;
				}
			}
		} while (IsAddIndexLevel(indexLevel));
	}
	else
	{
		do {
			auto nodeInfo = std::make_shared<NodeInfo>();

			node_nodeInfo.emplace_back(nodeInfo);
			_index.emplace_back(node);

		} while (IsAddIndexLevel(indexLevel));
	}
}

bool SkipList::DeleteNode(valueType&& value)
{
	//중복된 value처리에 대해 고민
	unsigned int maxIndexLevel = _index.size() - 1;
	unsigned int minIndexLevel = BaseIndexLevel;

	auto targetNode = FindNode(std::move(value), std::move(_index[maxIndexLevel]), 
							std::move(maxIndexLevel), std::move(minIndexLevel), false);
	if (targetNode == nullptr)
	{
		//삭제할 노드가 존재하지 않는다.
		return false;
	}

	//연결된 모든 곳에서 대상을 가르키는 모든것을 제거한다.
	unsigned int indexLevel = targetNode->nodeInfo().size() - 1;

	for (auto index = BaseIndexLevel; index <= indexLevel; ++index)
	{
		auto previousNode = targetNode->nodeInfo()[index]->previous();
		auto nextNode = targetNode->nodeInfo()[index]->next();

		previousNode->nodeInfo()[index]->setNext(std::move(nextNode));
	}

	targetNode->InitNode();
	targetNode.reset();

	return true;
}

std::shared_ptr<Node> SkipList::FindNode(valueType&& value, std::shared_ptr<Node>&& indexNode,
	unsigned int&& indexLevel, unsigned int&& minIndexLevel, bool&& isFindForInsert)
{
	if (indexNode == nullptr)
		return nullptr;

	if (value > indexNode->dataInfo()->value())
	{
		auto targetNode = indexNode->nodeInfo()[indexLevel]->next();
		auto returnNode = FindNode(std::move(value), std::move(targetNode),
			std::move(indexLevel), std::move(minIndexLevel), std::move(isFindForInsert));

		if (returnNode != nullptr)
			return std::move(returnNode);

		if (indexLevel > minIndexLevel)
			return FindNode(std::move(value), std::move(indexNode),
				indexLevel - 1, std::move(minIndexLevel), std::move(isFindForInsert));
		else
			return indexNode;
	}
	else if(value < indexNode->dataInfo()->value())
	{
		return nullptr;
	}
	else
	{
		return indexNode;
	}
}

///////////////////////////////////////////////////////////////////////////////
