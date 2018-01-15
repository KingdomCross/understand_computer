class TreeNode(object):
	def __init__(self, left = 0, right = 0, data = 0):
		self.left = left
		self.right = right
		self.data = data

class BTree(object):
	def __init__(self, root = 0):
		self.root = root

	def is_empty(self):
		if self.root is 0:
			return True
		else:
			return False
	
	def preorder(self, treenode):
		'前序（pre-order，NLR）遍历'
		if treenode is 0:
			return
		print (treenode.data)
		self.preorder(treenode.left)
		self.preorder(treenode.right)

	def inorder(self, treenode):
		'中序（in-order，LNR'
		if treenode is 0:
			return
		self.inorder(treenode.left)
		print(treenode.data)
		self.inorder(treenode.right)

	def postorder(self, treenode):
		'后序（post-order，LRN）遍历'
		if treenode is 0:
			return
		self.postorder(treenode.left)
		self.postorder(treenode.right)
		print(treenode.data)
	
	# attention: just use to the search binary tree
	def search(self, key, treenode):
		if treenode is 0 or treenode.data  is key:
			return treenode
		
		if key < treenode.data:
			return self.search(key, treenode.left)
		else:
			return self.search(key, treenode.right)



	
#********************   main   ********************#

if __name__ == '__main__':
	node1 = TreeNode(data = 1)
	node2 = TreeNode(node1, 0, 2)
	node3 = TreeNode(data = 3)
	node4 = TreeNode(data = 4)
	node5 = TreeNode(node3, node4, 5)
	node6 = TreeNode(node2, node5, 6)
	node7 = TreeNode(node6, 0, 7)
	node8 = TreeNode(data=8)
	root = TreeNode(node7, node8, 56)

	bt = BTree(root)

	print('前序（pre-order，NLR）遍历')
	bt.preorder(root)
	# bt.inorder(root)
	# bt.postorder(root)
	print()
	
	search_value = 34
	search_return = bt.search(search_value, root)
	if search_return is not 0:
		print('search the key value:', search_return.data)
	else:
		print('not search the key value:', search_value)
	print()


