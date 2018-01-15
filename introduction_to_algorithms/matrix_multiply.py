import time
import sys
from numpy import *

'''
	data1=mat(zeros((3,3)));
	#创建一个3*3的零矩阵，矩阵这里zeros函数的参数是一个tuple类型(3,3)
	data2=mat(ones((2,4)));
	#创建一个2*4的1矩阵，默认是浮点型的数据，如果需要时int类型，可以使用dtype=int
	data3=mat(random.rand(2,2));
	#这里的random模块使用的是numpy中的random模块，random.rand(2,2)创建的是一个二维数组，需要将其转换成	
	#matrix
	data4=mat(random.randint(10,size=(3,3)));
	#生成一个3*3的0-10之间的随机整数矩阵，如果需要指定下界则可以多加一个参数
	data5=mat(random.randint(2,8,size=(2,5));
	#产生一个2-8之间的随机整数矩阵
	data6=mat(eye(2,2,dtype=int));
	#产生一个2*2的对角矩阵

	a1=[1,2,3];
	a2=mat(diag(a1));
	#生成一个对角线为1、2、3的对角矩阵
	'''

def matrix_multiply(A, B):
	try:
		length1_row = len(A)
		length1_col = len(A[0])
	except:
		print('the dimension of matrix A has a problem')
		return
	
	try:
		length2_row = len(B)
		length2_col = len(B[0])
	except:
		print('the dimension of matrix B has a problem')
		return

	if length1_col != length2_row:
		print("the matrix A and B can't multiply")
		return

	# must attention to how to build a matrix
	# error: C = [[ 0 for i in range(0, length1_row)]] *length2_col 
	# right:
	
	C = [[ 0 for i in range(0, length1_row)] for i in range(length2_col)]  

	print(C)
	for i in range(0, length1_row):
		for j in range(0, length2_col):
			C[i][j] = 0
			for k in range(0, length1_col):
				C[i][j] += A[i][k] * B[k][j]

	return C


#********************   main   ********************#

if __name__ == '__main__':
	A = [[1, 2, 3],
		 [3, 4, 5],
		 [5, 6, 7]]
	B = [[1, 2, 3],
		 [3, 4, 5],
		 [5, 6, 7]]

	now1 = time.time()
	print(matrix_multiply(A, B))
	now2 = time.time()
	print(array(A)*array(B))
	now3 = time.time()
	print('the first faster than second:', now3 - 2*now2 + now1, 's')



'''
一次偶然的机会，发现python中list非常有意思。

先看一段代码

[py]
array = [0, 0, 0]
matrix = [array*3]
print matrix
## [[0,0,0,0,0,0,0,0,0]][/py]

这段代码其实没有新建一个二维数组

再看一段代码

[py]
array = [0, 0, 0]
matrix = [array] * 3
print matrix
## [[0, 0, 0], [0, 0, 0], [0, 0, 0]][/py]

咋一看这段代码应该创建一个二维数组了

测试一下

[py]
matrix[0][1] = 1
print matrix
## [[0, 1, 0], [0, 1, 0], [0, 1, 0]][/py]

照理matrix[0][1]修改的应该只是二维数组中的一个元素，但是测试结果表明，修改的是每个List的第二个元素。
有问题看文档，然后我找到了The Python Standard Library
其中5.6. Sequence Types是这样描述的：

Note also that the copies are shallow; nested structures are not copied. This often haunts new Python programmers; consider:
>>> lists = [[]] * 3
>>> lists
[[], [], []]
>>> lists[0].append(3)
>>> lists
[[3], [3], [3]]

What has happened is that [[]] is a one-element list containing an empty list, so all three elements of [[]] * 3 are (pointers to) this single empty list. Modifying any of the elements of lists modifies this single list. You can create a list of different lists this way:

>>>
>>> lists = [[] for i in range(3)]
>>> lists[0].append(3)
>>> lists[1].append(5)
>>> lists[2].append(7)
>>> lists
[[3], [5], [7]]
也就是说matrix = [array] * 3操作中，只是创建3个指向array的引用，所以一旦array改变，matrix中3个list也会随之改变。

那如何才能在python中创建一个二维数组呢？
例如创建一个3*3的数组
方法1 直接定义

[py]matrix = [[0, 0, 0], [0, 0, 0], [0, 0, 0]][/py]

方法2 间接定义

matrix = [[0 for i in range(3)] for i in range(3)]
'''
