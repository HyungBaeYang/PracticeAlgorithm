n = int(input())
a = list(map(int, input().split()))

def reverse(x):
    resNumber = 0
    while x > 0:
        temp = x % 10
        resNumber = resNumber * 10 + temp
        x = x // 10

    return resNumber


def isPrime(x):
    if x != 1:
        for n in range(2, x):
            if x % n == 0:
                return False
    else:
        return False
    return True
