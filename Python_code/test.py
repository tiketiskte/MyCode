n, m = (int)input().split()
l = pow(2, n)
r = pow(2, m)
ans = 0
for i in range(l, r):
    if i % 7 == 1:
        ans += 1
print(ans)