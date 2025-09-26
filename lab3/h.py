import sys
from bisect import bisect_left

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    n = next(it); m = next(it)

    a = [next(it) for _ in range(n)]

    pref = [0]
    s = 0
    for x in a:
        s += x
        pref.append(s)  

    out = []
    for _ in range(m):
        b = next(it)
        
        block = bisect_left(pref, b, lo=1, hi=len(pref))
        out.append(str(block))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
