import sys
sys.setrecursionlimit(200000)

class Node():
    __slots__ = ['data' , 'left' , 'right' ]
    def __init__(self , data):
        self.data = data
        self.left = None
        self.right = None
def insert(root , val ):
    if root is None:
        return Node(val)
    cur = root
    while True:
        if val < cur.data:
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
def count_nodes(root):
    if root is None:
        return 0
    return 1 + count_nodes(root.left)+count_nodes(root.right)
def main():
    n = int(input())
    nums = sys.stdin.readline().split()
    m = int(input())
    root = None
    for num in nums:
        root = insert(root , int(num))
    target_node = find(root , m)
    if target_node is None:
        print(0)
    else:
        print(count_nodes(target_node))
if __name__ == "__main__":
    main()