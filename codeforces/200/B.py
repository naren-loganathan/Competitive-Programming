n = int(input())
p = [int(i) for i in input().split()]
sum = 0
for i in range(0, n):
    sum += p[i]
print(float(sum) / float(n))