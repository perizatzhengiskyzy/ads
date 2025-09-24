import sys

class Node:
    __slots__ = ("val", "next")
    def __init__(self, val, nxt=None):
        self.val = val
        self.next = nxt

class LinkedList:
    __slots__ = ("head", "tail")
    def __init__(self):
        self.head = None
        self.tail = None
    def append(self, x):
        node = Node(x)
        if self.head is None:
            self.head = self.tail = node
        else:
            self.tail.next = node
            self.tail = node
data = list(map(int, sys.stdin.buffer.read().split()))
n = data[0]
vals = data[1:1+n]

ll = LinkedList()
for x in vals:
    ll.append(x)

freq = {}
mx = 0
cur = ll.head
while cur:
    v = cur.val
    c = freq.get(v, 0) + 1
    freq[v] = c
    if c > mx:
        mx = c
    cur = cur.next

modes = [v for v, c in freq.items() if c == mx]
modes.sort(reverse=True)
print(*modes)
