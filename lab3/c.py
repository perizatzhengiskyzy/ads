import sys
from bisect import bisect_left, bisect_right

def cnt_in_range(arr, L, R):
    if L > R:
        return 0

    return bisect_right(arr, R) - bisect_left(arr, L)

def solve():
    data = sys.stdin.buffer.read().split()
    it = iter(map(int, data))
    n = next(it); q = next(it)
    a = [next(it) for _ in range(n)]
    a.sort()

    out_lines = []
    for _ in range(q):
        l1 = next(it); r1 = next(it); l2 = next(it); r2 = next(it)
        ans = cnt_in_range(a, l1, r1) + cnt_in_range(a, l2, r2)
        interL, interR = max(l1, l2), min(r1, r2)
        ans -= cnt_in_range(a, interL, interR)
        out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
