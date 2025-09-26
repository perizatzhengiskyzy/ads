import sys
from bisect import bisect_right

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)

    n = next(it)                     
    a = [next(it) for _ in range(n)] 
    a.sort()

    ps = [0] * (n + 1)
    for i in range(n):
        ps[i + 1] = ps[i] + a[i]

    p = next(it)                     
    out = []
    for _ in range(p):
        M = next(it)                 
        k = bisect_right(a, M)       
        s = ps[k]                    
        out.append(f"{k} {s}")

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()
