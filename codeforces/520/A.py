n = int(input())
s = input()
freq = [0] * 26
for c in s:
    if (ord(c) >= 97):
        freq[ord(c) - 97] += 1
    else:
        freq[ord(c) - 65] += 1
pangram = bool(1)
for i in range(26):
    if freq[i] == 0:
        pangram = 0
        break
if pangram:
    print('YES')
else:
    print('NO')