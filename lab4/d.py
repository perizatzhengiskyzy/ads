import sys
from collections import deque   
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
def level_sum(root):
    if not root:
        return 0 , []
    q = deque([(root , 0)])
    level_sums = []
    while q:
        node , level = q.popleft()
        if level == len(level_sums):
            level_sums.append(0)
        level_sums[level]+=node.data
        if node.left:
            q.append((node.left , level+1))
        if node.right:
            q.append((node.right , level+1))
    return len(level_sums) , level_sums
def main():
    n = int(input())
    nums = sys.stdin.readline().split()
    root = None
    for num in nums:
        root = insert(root , int(num))
    h , sums = level_sum(root)
    print(h)
    print(" ".join(map(str, sums)))
if __name__ == "__main__":
    main()