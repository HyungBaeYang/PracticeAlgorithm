# 10 3          n, k
# 13 15 34 23 45 65 33 11 26 42     tempList

n, k = map(int, input().split())
tempList = list(map(int, input().split()))
res = set()
for i in range(n):
    for j in range(i+1, n):
        for g in range(j+1, n):
            res.add(tempList[i] + tempList[j] + tempList[g])

res = list(res)
res.sort(reverse=True)
print(res[k-1])

