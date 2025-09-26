import sys

def enough(cap, counts, f):

    trips = 0

    for x in counts:
        trips += (x + cap - 1) // cap
        if trips > f:  
            return False
    return trips <= f

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    n = next(it); f = next(it)
    c = [next(it) for _ in range(n)]

    lo, hi = 1, max(c)
    while lo < hi:
        mid = (lo + hi) // 2
        if enough(mid, c, f):
            hi = mid
        else:
            lo = mid + 1
    print(lo)

if __name__ == "__main__":
    main()
