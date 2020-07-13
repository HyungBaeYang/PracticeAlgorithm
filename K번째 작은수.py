t = int(input())

for i in range(t):
    n, s, e, k = map(int, input().split())
    # print(n, s, e, k)  # 6, 2, 5, 3 각각 차례대로 들어간다.
    a = list(map(int, input().split()))
    a = a[s-1:e]  # index 번호로 출력되기 때문에 -1 해줘야함.
    a.sort()
    print("#" + str(i+1), a[k-1])


