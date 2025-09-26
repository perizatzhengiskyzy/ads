import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    it = iter(data)
    n = next(it)      
    k = next(it)      

    needs = []
    for _ in range(n):
        x1 = next(it); y1 = next(it); x2 = next(it); y2 = next(it)
        needs.append(max(x2, y2))

    needs.sort()
    print(needs[k - 1])

if __name__ == "__main__":
    main()
