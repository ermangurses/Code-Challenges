class Node:

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
    def insert(self, data):

        # If root is not empty
        if self.data:
            if data < self.data:
                if self.left is None:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if self.right is None:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data
    def inOrderTraversal(self, root):
        if root:
            self.inOrderTraversal(root.left)
            print(root.data)
            self.inOrderTraversal(root.right)
    def preOrderTraversal(self, root):
        if root:
            print(root.data)
            self.preOrderTraversal(root.left)
            self.preOrderTraversal(root.right)
    def postOrderTraversal(self, root):
        if root:
            self.postOrderTraversal(root.left)
            self.postOrderTraversal(root.right)
            print(root.data)