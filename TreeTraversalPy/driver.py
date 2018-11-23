from node import Node

root = Node(-2)
root.insert(-34)
root.insert(23)
root.insert(54)
root.insert(2332)
root.insert(43)
root.insert(0)

print ("Inorder Traversal")
root.inOrderTraversal(root)
print ("\n")

print ("Preorder Traversal")
root.preOrderTraversal(root)
print ("\n")

print("Post Order Traversal")
root.postOrderTraversal(root);
print ("\n")