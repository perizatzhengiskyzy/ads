import sys 
class Node():
    def __init__(self , value):
        self.value = value
        self.next = None

    
def build_ll(words):
    head = None
    tail = None
    for w in words:
        node = Node(w)
        if not head:
            head = node
            tail = node
        else:
            tail.next = node
            tail = node
    return head , tail
def shift_ll(head , k):
    if head is None :
        return None
    length = 1
    tail = head 
    while tail.next:
        tail = tail.next 
        length +=1
    k = k%length
    if k == 0:
        return head
    new_tail = head
    for _ in range(k-1):
        new_tail = new_tail.next
    new_head = new_tail.next
    new_tail.next = None
    tail.next = head
    return new_head
def print_ll(head):
    current = head
    res = []
    while current:
        res.append(current.value)
        current = current.next
    print(' '.join(res))
t = sys.stdin.read().split()
n = int(t[0])
k = int(t[1])
words = t[2:2+n]
head , tail = build_ll(words)
head = shift_ll(head , k)
print_ll(head)