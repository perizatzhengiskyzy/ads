import sys

class Node:
    __slots__ = ("val", "prev", "next")
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class Deque:
    __slots__ = ("head", "tail", "size")
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def add_front(self, x):
        node = Node(x)
        if self.head is None:
            self.head = self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node
        self.size += 1
        return "ok"

    def add_back(self, x):
        node = Node(x)
        if self.tail is None:
            self.head = self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
        self.size += 1
        return "ok"

    def erase_front(self):
        if self.head is None:
            return "error"
        v = self.head.val
        self.head = self.head.next
        if self.head is None:
            self.tail = None
        else:
            self.head.prev = None
        self.size -= 1
        return v

    def erase_back(self):
        if self.tail is None:
            return "error"
        v = self.tail.val
        self.tail = self.tail.prev
        if self.tail is None:
            self.head = None
        else:
            self.tail.next = None
        self.size -= 1
        return v

    def front(self):
        return "error" if self.head is None else self.head.val

    def back(self):
        return "error" if self.tail is None else self.tail.val

    def clear(self):
        self.head = self.tail = None
        self.size = 0
        return "ok"

def main():
    dq = Deque()
    out = []
    for line in sys.stdin.read().splitlines():
        if not line:
            continue
        parts = line.strip().split()
        cmd = parts[0]
        if cmd == "add_front":
            out.append(dq.add_front(parts[1]))
        elif cmd == "add_back":
            out.append(dq.add_back(parts[1]))
        elif cmd == "erase_front":
            out.append(dq.erase_front())
        elif cmd == "erase_back":
            out.append(dq.erase_back())
        elif cmd == "front":
            out.append(dq.front())
        elif cmd == "back":
            out.append(dq.back())
        elif cmd == "clear":
            out.append(dq.clear())
        elif cmd == "exit":
            out.append("bye")
            print("\n".join(map(str, out)))
            return
    print("\n".join(map(str, out)))

if __name__ == "__main__":
    main()
