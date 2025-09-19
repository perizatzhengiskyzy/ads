import sys

data = list(map(int, sys.stdin.buffer.read().split()))
n = data[0]
a = data[1:1+n]
k = data[1+n]

best_i = 0
best_d = abs(a[0] - k)
for i in range(1, n):
    d = abs(a[i] - k)
    if d < best_d:
        best_d, best_i = d, i

print(best_i)
