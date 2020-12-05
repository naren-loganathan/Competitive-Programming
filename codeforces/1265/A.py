t = int(input())
for _ in range(t):
    s = list(input())
    possible = bool(1)
    characters = {'a', 'b', 'c'}
    if (len(s) == 1 and s[0] == '?'):
        s[0] = 'a'
    for i in range(len(s)):
        if (s[i] == '?'):
            if (i == 0):
                for c in characters:
                    if (c != s[i + 1]):
                        s[i] = c
                        break
            elif (i == len(s) - 1):
                for c in characters:
                    if (c != s[i - 1]):
                        s[i] = c
                        break
            else:
                for c in characters:
                    if (c != s[i - 1] and c != s[i + 1]):
                        s[i] = c
                        break
    for i in range(1, len(s)):
        if (s[i] == s[i - 1]):
            possible = 0
            break
    if (possible):
        print(*s, sep = '')
    else:
        print('-1')