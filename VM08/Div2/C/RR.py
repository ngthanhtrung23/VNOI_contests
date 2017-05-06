n = int(raw_input())

f = [0] * (n + 2)
f[1] = 1

for i in xrange(2, n+1):
    f[i] = f[i-1] * (n - i)

print sum(f)
