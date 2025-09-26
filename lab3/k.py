import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    n = next(it); k = next(it)
    a = [next(it) for _ in range(n)]

    left = 0
    cur = 0
    best = n + 1  

    for right in range(n):
        cur += a[right]
    
        while cur >= k:
            best = min(best, right - left + 1)
            cur -= a[left]
            left += 1

    print(best)

if __name__ == "__main__":
    main()
