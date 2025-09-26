import sys
from bisect import bisect_left, bisect_right

def count_in_range(arr, L, R):
    if L > R:   
        return 0
    return bisect_right(arr, R) - bisect_left(arr, L)

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    n = next(it)  
    q = next(it)  
    a = [next(it) for _ in range(n)]
    a.sort() 

    answers = []
    for _ in range(q):
        l1 = next(it); r1 = next(it); l2 = next(it); r2 = next(it)

        cnt1 = count_in_range(a, l1, r1)
        cnt2 = count_in_range(a, l2, r2)

        interL = max(l1, l2)
        interR = min(r1, r2)
        cnt_inter = count_in_range(a, interL, interR)

        answers.append(str(cnt1 + cnt2 - cnt_inter))

    print("\n".join(answers))

if __name__ == "__main__":
    main()
