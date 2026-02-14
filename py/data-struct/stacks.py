# Stack implementation in Python

from collections import deque

"""We can implement a stack (LIFO data structure) using a deque (double-ended queue) from the collections module in Python or using a list, though deque is more efficient for this purpose because of the reason mentioned in the queue implementation."""

class Stack:
    """
    Time Complexity:
    - Push: O(1) (because we are adding to the end of the deque)
    - Pop: O(1) (because we are removing from the end of the deque)
    - Peek: O(1) (because we are accessing the last element of the deque)
    - Size: O(1) (because we are keeping track of the size of the stack)

    Space Complexity:
    - O(n) (because we need to store n elements in the stack)
    """
    def __init__(self):
        self.items = deque()

    def is_empty(self):
        return not self.items

    def push(self, item):
        self.items.append(item) # We use append to add to the end of the stack

    def pop(self):
        if self.is_empty():
            raise IndexError("Pop from an empty stack")
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from an empty stack")
        return self.items[-1]

    def size(self):
        return len(self.items)
    

# Example usage
if __name__ == "__main__":
    stack = Stack()
    stack.push(1)
    stack.push(2)
    stack.push(3)
    print(stack.pop())     # Output: 3
    print(stack.peek())    # Output: 2
    print(stack.size())    # Output: 2
    print(stack.is_empty())# Output: False