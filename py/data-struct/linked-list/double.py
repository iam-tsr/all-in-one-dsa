# Double Linked List Implementation in Python

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoubleLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
        new_node.prev = last

    def prepend(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        self.head.prev = new_node
        new_node.next = self.head
        self.head = new_node

    def delete(self, key):
        current = self.head
        while current:
            if current.data == key:
                if current.prev:
                    current.prev.next = current.next
                else:
                    self.head = current.next  # Deleting the head node
                if current.next:
                    current.next.prev = current.prev
                return
            current = current.next

    def display(self):
        elements = []
        current = self.head
        while current:
            elements.append(current.data)
            current = current.next
        print(elements)

# Example Usage
if __name__ == "__main__":
    dll = DoubleLinkedList()
    dll.append(10)
    dll.append(20)
    dll.append(30)
    dll.display()  # Output: [10, 20, 30]

    dll.prepend(5)
    dll.display()  # Output: [5, 10, 20, 30]

    dll.delete(20)
    dll.display()  # Output: [5, 10, 30]