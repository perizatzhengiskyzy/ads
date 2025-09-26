import sys

def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    n = data[0]
    a = data[1:1+n]
    x = data[1+n]

    l, r = 0, n - 1
    found = False
    while l <= r:
        m = (l + r) // 2
        if a[m] == x:
            found = True
            break
        elif a[m] < x:
            l = m + 1
        else:
            r = m - 1

    print("Yes" if found else "No")

if __name__ == "__main__":
    main()
