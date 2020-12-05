t = int(input())
for _ in range(t):
    s = list(input())
    iseven = bool(0)
    sum_of_digits = 0
    cnt_zero = 0
    for i in range(len(s)):
        sum_of_digits += ord(s[i])
        if (s[i] == '0'):
            cnt_zero += 1
        if ((ord(s[i]) % 2 == 0 and s[i] != '0') or (s[i] == '0' and cnt_zero > 1)):
            iseven = 1
    possible = bool(0)
    if (cnt_zero and iseven and sum_of_digits % 3 == 0):
        possible = 1
    if (len(s) == 1 and s[0] == '0'):
        possible = 1
    print('red' if possible else 'cyan')