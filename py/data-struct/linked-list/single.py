# Single Linked List Implementation in Python

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SingleLinkedList:
    """
    Time Complexity:
    - Append: O(n) (because we need to traverse to the end of the list)
    - Prepend: O(1) (because we just need to update the head pointer)
    - Delete with value: O(n) (because we may need to traverse the list to find the node to delete)
    - Print list: O(n) (because we need to traverse the list to print all nodes)

    Space Complexity:
    - O(n) (because we need to store n nodes in the linked list)
    """

    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete_with_value(self, data):
        if not self.head:
            return
        if self.head.data == data:
            self.head = self.head.next
            return
        current_node = self.head
        while current_node.next:
            if current_node.next.data == data:
                current_node.next = current_node.next.next
                return
            current_node = current_node.next

    def print_list(self):
        current_node = self.head
        while current_node:
            print(current_node.data, end=' ')
            current_node = current_node.next
        print()


# Example usage
if __name__ == "__main__":
    linked_list = SingleLinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(3)
    linked_list.prepend(0)
    print("Linked List after appending and prepending:")
    linked_list.print_list()

    linked_list.delete_with_value(2)
    print("Linked List after deleting value 2:")
    linked_list.print_list()