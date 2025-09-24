from collections import deque
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
    def print_list(self):
        current = self.head
        while current:
            print(current.value , end = " ")
            current = current.next
    def uniqu(self):
        count = [0]*26 
        q = deque()
        result = []
        current = self.head
        while current:
            indx = ord(current.value)- ord('a')
            count[indx]+=1
            q.append(current.value)
            while q and count[ord(q[0])- ord('a')] > 1:
                q.popleft()
            if q:
                result.append(q[0])
            else:
                result.append(-1)
            current = current.next
        print(" ".join(map(str,result)))
if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        a = int(input())
        b = input().strip().split()
        ll = LinkedLists()
        for j in b:
            ll.append(j)
        ll.uniqu()
        