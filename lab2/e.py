import sys

class Node:
    __slots__ = ("value", "next")
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    __slots__ = ("head", "tail", "size")
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0


    def append(self, value):
        node = Node(value)
        if self.head is None:
            self.head = self.tail = node
        else:
            self.tail.next = node
            self.tail = node
        self.size += 1

    def delete_consecutive_duplicates(self):
        cur = self.head
        while cur and cur.next:
            if cur.value == cur.next.value:
                cur.next = cur.next.next
                self.size -= 1
                if cur.next is None:   
                    self.tail = cur
            else:
                cur = cur.next

    def print_reversed(self):
        stack = []
        cur = self.head
        while cur:
            stack.append(cur.value)
            cur = cur.next
        while stack:
            print(stack.pop())

if __name__ == "__main__":
    lines = sys.stdin.read().splitlines()
    n = int(lines[0])

    ll = LinkedList()
    for i in range(1, n + 1):
        ll.append(lines[i])

    ll.delete_consecutive_duplicates()

    print(f"All in all: {ll.size}")
    print("Students:")
    ll.print_reversed()
