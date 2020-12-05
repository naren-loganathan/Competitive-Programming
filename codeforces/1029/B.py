n = int(input())
a = [int(i) for i in input().split()]
result = 0
cnt = 1
for i in range(1, n):
    if (a[i] <= 2 * a[i - 1]):
        cnt += 1
    else:
        result = max(result, cnt)
        cnt = 1
result = max(result, cnt)
print(result)