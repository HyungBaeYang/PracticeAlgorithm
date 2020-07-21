#include <vector>
#include <memory>

typedef unsigned int valueType;

const unsigned int		Invalid_Value = 0;
const unsigned int		BaseIndexLevel = 0;
const unsigned int		MaxRandomSize = 4;

class DataInfo;
class NodeInfo;
class Node;
class SkipList;

class DataInfo
{
public:
	virtual void InitDataInfo();

	const unsigned int value() const { return _value; };
	void setValue(valueType&& value) { _value = std::move(value); };

private:
	valueType	_value;
};

class NodeInfo
{
public:
	NodeInfo();
	~NodeInfo();

	void InitNodeInfo();

	const std::shared_ptr<Node> previous() const { return _previous; };
	const std::shared_ptr<Node> next() const { return _next; };

	void setPrevious(std::shared_ptr<Node>&& previous) { _previous = previous; };
	void setNext(std::shared_ptr<Node>&& next) { _next = next; };

private:
	std::shared_ptr<Node> _previous;
	std::shared_ptr<Node> _next;
};

class Node
{
public:
	void InitNode();
	std::shared_ptr<DataInfo>& dataInfo() { return _dataInfo; };
	std::vector<std::shared_ptr<NodeInfo>>& nodeInfo() { return _nodeInfo_vector; };
	
private:
	std::shared_ptr<DataInfo> _dataInfo;
	std::vector<std::shared_ptr<NodeInfo>> _nodeInfo_vector;
};

class SkipList
{
public:
	void InitSkipList();
	void InsertNode(std::shared_ptr<DataInfo>&& dataInfo);
	bool DeleteNode(valueType&& value);

	const std::vector<std::shared_ptr<Node>> skipList() const { return _index; };
private:
	std::shared_ptr<Node> FindNode(valueType&& value, std::shared_ptr<Node>&& indexNode,
		unsigned int&& indexLevel, unsigned int&& minIndexLevel, bool&& isFindForInsert);

	std::vector<std::shared_ptr<Node>> _index;
};