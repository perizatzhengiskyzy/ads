import sys

def feasible(a, k, limit):

    blocks = 1
    cur = 0
    for x in a:
        if x > limit: 
            return False
        if cur + x <= limit:
            cur += x
        else:
            blocks += 1
            cur = x
            if blocks > k:
                return False
    return True

def solve():
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    n, k = data[0], data[1]
    a = data[2:2+n]

    lo = max(a)          
    hi = sum(a)         

    while lo < hi:
        mid = (lo + hi) // 2
        if feasible(a, k, mid):
            hi = mid
        else:
            lo = mid + 1

    print(lo)

if __name__ == "__main__":
    solve()
