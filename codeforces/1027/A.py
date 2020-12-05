t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    possible = bool(1)
    for i in range(n // 2):
        d = abs(ord(s[i]) - ord(s[len(s) - 1 - i]))
        if (d != 2 and d != 0):
            possible = 0
            break
    print('YES' if possible else 'NO')