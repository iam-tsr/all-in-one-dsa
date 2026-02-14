class HashMap:
    """
    Time Complexity:
    - Insert: O(1) on average, O(n) in worst case (when there are many collisions)
    - Search: O(1) on average, O(n) in worst case (when there are many collisions)
    - Delete: O(1) on average, O(n) in worst case (when there are many collisions)

    Space Complexity:
    - O(n) (because we need to store n key-value pairs in the hash table)
    """
    def __init__(self, size=10):
        self.size = size
        self.table = [None] * self.size

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        if self.table[index] is None:
            self.table[index] = [(key, value)]
        else:
            for i, (k, v) in enumerate(self.table[index]):
                if k == key:
                    self.table[index][i] = (key, value)
                    return
            self.table[index].append((key, value))

    def search(self, key):
        index = self._hash(key)
        if self.table[index] is not None:
            for k, v in self.table[index]:
                if k == key:
                    return v
        return None

    def delete(self, key):
        index = self._hash(key)
        if self.table[index] is not None:
            for i, (k, v) in enumerate(self.table[index]):
                if k == key:
                    del self.table[index][i]
                    return True
        return False
    
# Example usage
if __name__ == "__main__":
    ht = HashMap()
    ht.insert("name", "Alice")
    ht.insert("age", 30)
    print(ht.search("name"))  # Output: Alice
    print(ht.search("age"))   # Output: 30
    ht.delete("name")
    print(ht.search("name"))  # Output: None