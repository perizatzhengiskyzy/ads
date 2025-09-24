def difference(n , lisst):
    difference = []
    a = 100000000000
    index = -1
    for i in range(len(lisst)):
        count = abs(n-lisst[i])
        difference.append(count)
        if count<a:
            a = count
            index = i
    return index
def main():
    n = int(input())
    lisst = list(map(int, input().split()))
    a = int(input())
    print(difference(a , lisst))
if __name__=="__main__":
    main()