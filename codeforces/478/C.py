r, g, b = map(int, input().split())
ans = min((r + g + b) // 3, (r + g + b) - max(r, g, b))
print(ans)