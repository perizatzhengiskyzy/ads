import sys

def binary_search_desc(a, x):
    left, right = 0, len(a) - 1
    while left <= right:
        mid = left + (right - left) // 2
        if a[mid] == x:
            return mid
        elif a[mid] < x:   
            right = mid - 1
        else:
            left = mid + 1
    return -1

data = list(map(int, sys.stdin.read().strip().split()))
it = iter(data)

t = next(it)
queries = [next(it) for _ in range(t)]

n, m = next(it), next(it)

matrix = []
for i in range(n):
    row = [next(it) for _ in range(m)]
    if i % 2 == 1:  
        row.reverse()
    matrix.extend(row)

for q in queries:
    idx = binary_search_desc(matrix, q)
    if idx == -1:
        print(-1)
        continue
    x = idx // m
    y = idx % m
    if x % 2 == 1:          
        y = m - y - 1
    print(x, y)
