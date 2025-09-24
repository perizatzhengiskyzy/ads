import sys

class Node:
    __slots__ = ("val", "next")
    def __init__(self, val, nxt=None):
        self.val = val
        self.next = nxt

def build_linked_list(values):
    head = tail = None
    for v in values:
        node = Node(v)
        if head is None:
            head = tail = node
        else:
            tail.next = node
            tail = node
    return head

def findMaxSum(*args):
    head = args[-1]  
    cur = head
    cur_sum = 0
    max_sum = -10**18  
    while cur:
        cur_sum = cur.val if cur_sum + cur.val < cur.val else cur_sum + cur.val
        if cur_sum > max_sum:
            max_sum = cur_sum
        cur = cur.next
    return max_sum

if __name__ == "__main__":
    data = list(map(int, sys.stdin.buffer.read().split()))
    n = data[0]
    vals = data[1:1+n]
    head = build_linked_list(vals)
    print(findMaxSum(head))
