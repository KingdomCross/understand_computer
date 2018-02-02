#!python3
# coding: UTF-8

NIL = 'NIL'

class red_black_tree:
	def __init__(self, color = 'black', key = 0, left = NIL, right = NIL, parent = NIL):
		self.color = color
		self.key = key
		self.left = left
		self.right = right
		self.parent = parent
def print_RBT(T):
	if T != NIL:
		print_RBT(T.left)
		print(T.key)
		print_RBT(T.right)
				
def left_rotate(T, x):
	y = x.right
	y.parent = x
	
	x.right = y.left
	x.right.parent = y
	print('\nrotating')
	
	
	if y.left != NIL:
		y.left.parent = x
	y.parent = x.parent
	print_RBT(T)	
	if x.parent == NIL:
		T = y
	elif x == x.parent.left:
		x.parent.left = y
	else:
		x.parent.right = y
			
	y.left = x
	x.parent = y
		

		
		



if __name__ == '__main__':
	# testing the address of x, y, z
	# and which address are equal
	# x = NIL
	# y = NIL
	# z = NIL
	# print(x.__str__,'\n', y.__str__, '\n', z.__str__)
	
	T = red_black_tree(key = 26)
	T1l = T.left = red_black_tree(color = 'red', key = 17, parent = T)
	T1r = T.right = red_black_tree(key = 41, parent = T)
	
	T1l.left = red_black_tree(key = 14, parent = T1l)
	T1l.right = red_black_tree(key = 21, parent = T1l)
	
	T1r.left = red_black_tree(color = 'red', key = 30, parent = T1r)
	T1r.right = red_black_tree(key = 47, parent = T1r)
	
	print('\nbefore rotate')
	print_RBT(T)
	left_rotate(T, T)
	print('\nrotated')
	print_RBT(T)
	
			
