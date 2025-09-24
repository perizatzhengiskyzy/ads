from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedLists:
    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def print_list(self):
        if self.head is None:
            print(-1)
            return
        current = self.head
        values = []
        while current:
            values.append(str(current.value))
            current = current.next
        print(" ".join(values))

    def insert(self, x, p):
        count = 0
        current = self.head
        if p == 0:
            new_node = Node(x)
            new_node.next = self.head
            self.head = new_node
            return
        while current and count < p - 1:
            current = current.next
            count += 1
        new_node = Node(x)
        new_node.next = current.next
        current.next = new_node

    def remove(self, p):
        count = 0
        current = self.head
        if p == 0:
            self.head = self.head.next
            return
        while current and count < p - 1:
            current = current.next
            count += 1
        current.next = current.next.next

    def replace(self, p1, p2):
        if self.head is None or self.head.next is None or p1 == p2:
            return self.head
        prev1 = None
        curr1 = self.head
        for _ in range(p1):
            prev1 = curr1
            curr1 = curr1.next
        node_to_move = curr1
        if prev1 is None:
            self.head = curr1.next
        else:
            prev1.next = curr1.next
        if p2 == 0:
            node_to_move.next = self.head
            self.head = node_to_move
        else:
            prev2 = None
            curr2 = self.head
            for _ in range(p2):
                prev2 = curr2
                curr2 = curr2.next
            prev2.next = node_to_move
            node_to_move.next = curr2

    def reverse(self):
        prev = None
        current = self.head
        while current:
            nextnode = current.next
            current.next = prev
            prev = current
            current = nextnode
        self.head = prev

    def cyclic_left(self, k):
        if self.head is None or k == 0:
            return
        length = 1
        tail = self.head
        while tail.next:
            tail = tail.next
            length += 1
        k %= length
        if k == 0:
            return
        prev = self.head
        for _ in range(k - 1):
            prev = prev.next
        new_head = prev.next
        tail.next = self.head
        prev.next = None
        self.head = new_head

    def cyclic_right(self, k):
        if self.head is None or k == 0:
            return
        length = 1
        tail = self.head
        while tail.next:
            tail = tail.next
            length += 1
        k %= length
        if k == 0:
            return
        steps_to_new_head = length - k
        prev = None
        current = self.head
        for _ in range(steps_to_new_head):
            prev = current
            current = current.next
        prev.next = None
        tail.next = self.head
        self.head = current

if __name__ == "__main__":
    ll = LinkedLists()
    while True:
        try:
            command = list(map(int, input().split()))
        except EOFError:
            break
        if not command:
            continue
        cmd = command[0]
        if cmd == 0:
            break
        elif cmd == 1:
            n, m = command[1], command[2]
            ll.insert(n, m)
        elif cmd == 2:
            n = command[1]
            ll.remove(n)
        elif cmd == 3:
            ll.print_list()
        elif cmd == 4:
            n, m = command[1], command[2]
            ll.replace(n, m)
        elif cmd == 5:
            ll.reverse()
        elif cmd == 6:
            n = command[1]
            ll.cyclic_left(n)
        elif cmd == 7:
            n = command[1]
            ll.cyclic_right(n)