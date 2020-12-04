t = int(input())
for _ in range(0, t):
    a, b = map(int, input().split())
    result = 0
    if (a % b):
        result = b - (a % b)
    print(result)