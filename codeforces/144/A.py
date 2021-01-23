n = int(input())
a = [int(ai) for ai in input().split()]
mx = a[0]
mn = a[0]
mx_idx = 0
mn_idx = 0 
for i in range(1, n):
    if (a[i] > mx):
        mx = a[i]
        mx_idx = i
    elif (a[i] <= mn):
        mn = a[i]
        mn_idx = i
print(mx_idx + n - 1 - mn_idx - (mx_idx > mn_idx))