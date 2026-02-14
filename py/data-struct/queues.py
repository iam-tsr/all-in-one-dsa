# Queue implementation in Python

from collections import deque

"""
We can implement a queue (FIFO data structure) using a deque (double-ended queue) from the collections module in Python or using a list, though deque is more efficient for this purpose because:

list: Removing the first element requires shifting every other element one position left in memory, making it an O(n).

deque: Designed as a doubly linked list, adding or removing elements from either end only requires updating the pointers of the neighboring elements, resulting in a consistent O(1) operation.
"""

class Queue:
    """
    Time Complexity:
    - Enqueue: O(1) (because we are adding to the end of the deque)
    - Dequeue: O(1) (because we are removing from the front of the deque)
    - Peek: O(1) (because we are accessing the front element of the deque)
    - Size: O(1) (because we are keeping track of the size of the queue)

    Space Complexity:
    - O(n) (because we need to store n elements in the queue)
    """
    def __init__(self):
        self.items = deque()

    def is_empty(self):
        return not self.items

    def enqueue(self, item):
        self.items.appendleft(item) # We use appendleft to add to the end of the queue (front of the deque)

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Dequeue from an empty queue")
        return self.items.pop()

    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from an empty queue")
        return self.items[0]

    def size(self):
        return len(self.items)
    
# Example usage
if __name__ == "__main__":
    queue = Queue()
    queue.enqueue(1)
    queue.enqueue(2)
    queue.enqueue(3)
    print(queue.dequeue())  # Output: 1
    print(queue.peek())     # Output: 2
    print(queue.size())     # Output: 2
    print(queue.is_empty()) # Output: False