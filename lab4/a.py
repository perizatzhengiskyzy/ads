import sys
input = sys.stdin.readline
class Node():
    __slots__ = ['data' , 'left' , 'right' ]
    def __init__(self , data):
        self.data = data
        self.left = None
        self.right = None
def insert(root , data):
    if root is None:
        return Node(data)
    curr = root
    while True:
        if data < curr.data:
            if curr.left is None:
                curr.left = Node(data) 
                break
            curr = curr.left
        else:
            if curr.right is None:
                curr.right = Node(data)
                break
            curr = curr.right
    return root
def check(path , root):
    cur = root
    for p in path:
        if cur is None:
            return False
        if p=='L':
            cur = cur.left
        else:
            cur = cur.right
    return cur is not None
n , m = map(int , input().split())
nums = list(map(int , input().split()))
root = None
for num in nums :
    root = insert(root , num)
for i in range(m):
    s = input().strip()
    print("YES" if check(s , root) else "NO")
        