class Node():
    def __init__(self , value):
        self.value= value
        self.next = None
class LinkedLists():
    def __init__(self):
        self.head = None
    def append(self , value):
        new_node = Node(value)
        if not self.head :
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node 
    def put_position(self , value , pos):
        new_node = Node(value)
        if pos == 0 :
            new_node.next = self.head
            self.head = new_node
            return
        else:
            current = self.head 
            prev = None
            current_pos = 0
            while current and current_pos <= pos :
                if current_pos == pos:
                    prev.next = new_node
                    new_node.next = current
                    return
                prev = current 
                current = current.next
                current_pos += 1             
    def print_list(self):
        current = self.head
        while current:
            print(current.value , end = " ")
            current = current.next
if __name__ == "__main__":
    n = int(input())
    ll = LinkedLists()
    for i in range(n):
        a = int(input())
        ll.append(a)
    a = int(input())
    pos = int(input())
    ll.put_position(a, pos)
    ll.print_list()