import sys
sys.setrecursionlimit(200000)
class Node():
    __slots__ = ['data' , 'left' , 'right']
    def __init__(self , data):
        self.data = data
        self.left = None
        self.right = None
def insert(root , val):
    if root is None:
        return Node(val)
    cur = root
    while True:
        if val<cur.data:
            if cur.left is None:
                cur.left = Node(val)
                break
            cur = cur.left
        else:
            if cur.right is None:
                cur.right = Node(val)
                break
            cur = cur.right
    return root
def find(root , data):
    cur = root
    while cur:
        if cur.data == data:
            return cur
        elif data < cur.data:
            cur = cur.left
        else:
            cur = cur.right
    return None
def preorder(root , res):
    if root is None:
        return
    res.append(str(root.data))
    preorder(root.left , res)
    preorder(root.right , res)
def main():
    n = int(input())
    nums = sys.stdin.readline().split()
    m = int(input())
    root = None
    for num in nums :
        root = insert(root , int(num))
    target_node = find(root , m) 
    if target_node is None:
        print(-1)
    else:
        res = []
        preorder(target_node , res)   
        print(" ".join(res))
if __name__ == "__main__":
    main()