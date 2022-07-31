class Node:
    def __init__(self, data) -> None:
        self.prev = None
        self.next = None
        self.data = data
        return

    def remove(self):
        if self.prev != None:
            self.prev.next = self.next
        if self.next != None:
            self.next.prev = self.prev

class DLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, node:Node):
        if self.head == None:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            node.prev = self.tail
            self.tail = node

    def remove(self, node:Node):
        if node is self.head:
            self.head = self.head.next
        if node is self.tail:
            self.tail = self.tail.prev
        node.remove()
    
    def toList(self):
        myList = []
        curr = self.head
        while curr != None:
            myList.append(curr.data)
            curr = curr.next
        return myList


myLinkedList = DLinkedList()
for i in range(100):
    myLinkedList.append(Node(i))

curr = myLinkedList.head
while curr is not None:
    next = curr.next
    if curr.data % 2 == 0 or curr.data > 40:
        myLinkedList.remove(curr)
    curr = next

print(myLinkedList.toList())