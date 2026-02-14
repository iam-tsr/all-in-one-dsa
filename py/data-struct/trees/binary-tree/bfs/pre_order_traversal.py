from collections import deque

class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


class BST:
    def __init__(self):
        self.root = None

    # Insert
    def insert(self, value):
        if not self.root:
            self.root = Node(value)
            return

        cur = self.root
        while True:
            if value < cur.value:
                if cur.left:
                    cur = cur.left
                else:
                    cur.left = Node(value)
                    return
            elif value > cur.value:
                if cur.right:
                    cur = cur.right
                else:
                    cur.right = Node(value)
                    return
            else:
                return

    # Pre-order traversal
    def preorder(self):
        def dfs(node):
            if not node:
                return
            print(node.value, end=" ")
            dfs(node.left)
            dfs(node.right)

        dfs(self.root)
        print()

    # Delete (all cases)
    def delete(self, value):
        def remove(node, value):
            if not node:
                return None

            if value < node.value:
                node.left = remove(node.left, value)
            elif value > node.value:
                node.right = remove(node.right, value)
            else:
                # no child
                if not node.left and not node.right:
                    return None
                # one child
                if not node.left:
                    return node.right
                if not node.right:
                    return node.left
                # two children
                temp = node.right
                while temp.left:
                    temp = temp.left
                node.value = temp.value
                node.right = remove(node.right, temp.value)

            return node

        self.root = remove(self.root, value)

    # BFS search
    def bfs_search(self, value):
        if not self.root:
            return False

        q = deque([self.root])
        while q:
            node = q.popleft()
            if node.value == value:
                return True
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

        return False


# Example
if __name__ == "__main__":
    bst = BST()
    for v in [50, 30, 70, 20, 40, 60, 80]:
        bst.insert(v)

    bst.preorder() # 50 30 20 40 70 60 80
    bst.delete(50)
    bst.preorder() # 60 30 20 40 70 80
    print(bst.bfs_search(60)) # True
    print(bst.bfs_search(100)) # False