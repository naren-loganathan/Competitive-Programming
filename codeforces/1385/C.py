t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    i = n - 1
    while (a[i] <= a[i - 1] and i > 0):
        i -= 1
    while (a[i] >= a[i - 1] and i > 0):
        i -= 1
    print(i)