import sys

def ok(K, bags, H):
  
    hours = 0
    for x in bags:
        hours += (x + K - 1) // K
        if hours > H:          
            return False
    return True

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    N = next(it); H = next(it)
    bags = [next(it) for _ in range(N)]

    lo, hi = 1, max(bags)
    while lo < hi:
        mid = (lo + hi) // 2
        if ok(mid, bags, H):
            hi = mid
        else:
            lo = mid + 1
    print(lo)

if __name__ == "__main__":
    main()
