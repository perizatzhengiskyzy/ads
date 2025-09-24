class Node:
    def __init__(self , value):
        self.value = value
        self.next = None
class LinkedLists:
    def __init__(self):
        self.head = None
    def append(self , value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    def delete(self):
        if not self.head:
            return
        if not self.head.next:
            self.head = None
            return
        current = self.head
        while current and current.next:
            current.next = current.next.next
            current = current.next
    def print_list(self):
        current = self.head
        while current :
            print(current.value , end = " ")
            current = current.next
        print()
if __name__ == "__main__":
    n = int(input())
    nums = map(int , input().split())
    ll = LinkedLists()
    for num in nums:
        ll.append(num)

    ll.delete()
    ll.print_list()

        