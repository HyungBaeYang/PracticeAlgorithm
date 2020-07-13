def solution(bridge_length, weight, truck_weights):
    answer = 0              # 시간으로 책정.
    bridgeTruck_List = []   #
    time_List = []

    while (truck_weights or bridgeTruck_List):
        answer += 1
        if(time_List):
            if (time_List[0] + bridge_length == answer):
                bridgeTruck_List.pop(0)
                time_List.pop(0)

        if(truck_weights):
            if(sum(bridgeTruck_List) + truck_weights[0] <= weight):
                bridgeTruck_List.append(truck_weights.pop(0))
                time_List.append(answer)

    return answer

bridge_length = 2
weight = 10
truck_weight = [7, 4, 5, 6]
answer = solution(bridge_length, weight, truck_weight)
print(answer)
