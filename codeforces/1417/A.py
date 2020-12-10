t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    cnt = 0
    for i in range(1, n):
        cnt += ((k - a[i]) // a[0])
    print(cnt)