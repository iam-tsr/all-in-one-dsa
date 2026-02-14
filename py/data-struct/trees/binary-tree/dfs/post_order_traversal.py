class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# Insert node
def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    return root


# DFS Search
def dfs_search(root, key):
    if root is None:
        return False

    if root.key == key:
        return True
    elif key < root.key:
        return dfs_search(root.left, key)
    else:
        return dfs_search(root.right, key)


# Post-order Traversal (Left -> Right -> Root)
def postorder(root):
    if root:
        postorder(root.left)
        postorder(root.right)
        print(root.key, end=" ")


# Find minimum value node (for delete)
def min_value_node(node):
    current = node
    while current.left:
        current = current.left
    return current


# Delete node
def delete_node(root, key):
    if root is None:
        return root

    if key < root.key:
        root.left = delete_node(root.left, key)
    elif key > root.key:
        root.right = delete_node(root.right, key)
    else:
        # Case 1: Leaf node
        if root.left is None and root.right is None:
            return None

        # Case 2: One child
        if root.left is None:
            return root.right
        elif root.right is None:
            return root.left

        # Case 3: Two children
        successor = min_value_node(root.right)
        root.key = successor.key
        root.right = delete_node(root.right, successor.key)

    return root


if __name__ == "__main__":
    root = None
    values = [50, 30, 70, 20, 40, 60, 80]

    for v in values:
        root = insert(root, v)

    print("Post-order traversal:")
    postorder(root)

    search_key = 60
    print(f"\n\nSearching for {search_key}:",
          dfs_search(root, search_key))

    delete_key = 50
    root = delete_node(root, delete_key)

    print(f"\n\nPost-order traversal after deleting {delete_key}:")
    postorder(root)