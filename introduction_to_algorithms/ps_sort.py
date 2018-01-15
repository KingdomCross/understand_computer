import sys
import string
import math

'''

function : insertion_sort(data)
parameter: data, can be any type
output   : the order of data from small to big

function : merge_sort(data)
parameter: data, just int or long or double or float type
output   : the order of data from small to big

function : heap_sort(data)
parameter: data, just int or double or float type
output   : the order of data from small to big

function : quick_sort(data)
parameter: data, just int or long or double or float type
output   : the order of data from small to big

function : counting_sort(data, k)
parameter: data, just int or long type
		   k, express that the number in data are less than k
		   and more than 0
output   : the order of data from small to big

'''


#----------------- insertion_sort -----------------#

def insertion_sort(data):
	j_index = 0
	for key in data[1:]:
		j_index += 1
		i_index = j_index-1
		while i_index > -1 and data[i_index] > key:
			data[i_index + 1] = data[i_index]
			i_index -= 1
		data[i_index + 1] = key
	return data

#----------------- insertion_sort -----------------#

#-----------------   merge_sort   -----------------#

def merge(data, left, mid, right):
	# print(data)

	Left_list = data[left:mid+1]
	Right_list = data[mid + 1:right+1]
	# print(Left_list)
	# print(Right_list)

	Left_list.append(math.inf)
	Right_list.append(math.inf)
	# print(Left_list)
	# print(Right_list)
	
	i = 0
	j = 0

	for k in range(left, right + 1):
		if Left_list[i] <= Right_list[j]:
			data[k] = Left_list[i]
			i += 1	
		else:
			data[k] = Right_list[j]
			j += 1
	#print(data)	

def merge_sort_mid(data, left, right):
	if left < right:
		mid = ( left + right)//2
		merge_sort_mid(data, left, mid)
		merge_sort_mid(data, mid + 1, right)
		merge(data, left, mid, right)
	return data

def merge_sort(data):
	merge_sort_mid(data, 0, len(data)-1)
	return data

#-----------------   merge_sort   -----------------#


#-----------------   heap_sort    -----------------#

# the property of heap

def parent(var):
	return var//2

def left_child(var):
	return 2*var + 1

def right_child(var):
	return 2*var +2

# max heap
def max_heapify(data, var, heap_size):
	left = left_child(var)
	right = right_child(var)
	if left < heap_size and data[left] > data[var]:
		largest = left
	else:
		largest = var
	if right < heap_size and data[right] > data[largest]:
		largest = right
	if largest != var:
		data[largest], data[var] = data[var], data[largest]
		max_heapify(data, largest, heap_size)

# build max heap
def build_max_heap(data):
	heap_size = data_length = len(data)
	for i in range(data_length//2, -1, -1):
		max_heapify(data, i, heap_size)

	return data

# heap sort
def heap_sort(data):
	build_max_heap(data)
	heap_size = data_length = len(data)
	for i in range(data_length-1, 0, -1):
		data[0], data[i] = data[i], data[0]
		heap_size -= 1
		max_heapify(data, 0, heap_size)
	return data



#-----------------   heap_sort    -----------------#



#-----------------   quick_sort   -----------------#

# select pivot element (主元)
def partition(data, left, right):
	temp = data[right]
	i = left -1
	for j in range(left, right):
		if data[j] <= temp:
			i += 1
			data[i], data[j] = data[j], data[i]
	data[i+1], data[right] = data[right], data[i+1]
	return (i + 1)

# the random version of partition()
def randomized_partition(data, left, right):
	import random
	index = random.randint(left, right)
	data[index], data[right] = data[right], data[index]
	return partition(data, left, right)

# not use the randomized_partition function
def quick_sort_mid(data, left, right):
	if left < right:
		mid = partition(data, left, right)
		quick_sort_mid(data, left, mid -1 )
		quick_sort_mid(data, mid + 1, right)

def quick_sort(data):
	quick_sort_mid(data, 0, len(data)-1)
	return data


#-----------------   quick_sort   -----------------#


#----------------- counting_sort -----------------#

# the velocity of the program seem to slow a lot 
# than previous programs

def counting_sort(data, k):
	import numpy as np
	data_temp   = [int(num) for num in np.zeros(k+1)]
	data_output = [int(num) for num in np.zeros(len(data))]

	for j in range(1, len(data)):
		data_temp[data[j]] += 1

	for i in range(1, k + 1):
		data_temp[i] += data_temp[i - 1] 

	for j in range(len(data)-1, -1, -1):
		data_output[data_temp[data[j]]] = data[j]
		data_temp[data[j]] = data_temp[data[j]] - 1

	return data_output

#----------------- counting_sort -----------------#


#********************   main   ********************#

if __name__ == '__main__':
	import time
	print('XXXXXXXXXXXXXXXXX<insertion_sort>XXXXXXXXXXXXXXXXX')
	now = time.time()
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]

			insertion_sort(data2)
			# print(insertion_sort(data2))

		fin.close()
	except:
		print('No input file, select default input data')
		# data = [1,3,2,4,5]
		# data = ['2', '1', '3']
		data = ['you', 'are', 'girl']
		print(insertion_sort(data))
	print('spend time:', time.time() - now)

	print('XXXXXXXXXXXXXXXXXXXX<merge_sort>XXXXXXXXXXXXXXXXXXX')
	now = time.time()	
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]

			merge_sort(data2)
			# print(merge_sort(data2))

		fin.close()
	except:
		print('No input file, select default input data')
		data = [1,3,2,4,5]
		print(merge_sort(data))
	print('spend time:', time.time() - now)

	print('XXXXXXXXXXXXXXXXXXXXX<heap_sort>XXXXXXXXXXXXXXXXXXXX')
	now = time.time()
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]

			heap_sort(data2)
			# print(heap_sort(data2))

		fin.close()
	except:
		print('No input file, select default input data')
		data = [1,3,2,4,5]
		print(heap_sort(data))
	print('spend time:', time.time() - now)

	print('XXXXXXXXXXXXXXXXXXXXX<quick_sort>XXXXXXXXXXXXXXXXXXXX')
	now = time.time()
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]

			quick_sort(data2)
			# print(quick_sort(data2))

		fin.close()
	except:
		print('No input file, select default input data')
		data = [1,3,2,4,5]
		print(quick_sort(data))
	print('spend time:', time.time() - now)

	print('XXXXXXXXXXXXXXXXXXX<counting_sort>XXXXXXXXXXXXXXXXXXX')
	import numpy as np
	now = time.time()
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]

			counting_sort(data2, np.max(data2))
			# print(counting_sort(data2, np.max(data2)))
		fin.close()
	except:
		print('No input file, select default input data')
		data = [1,3,2,4,5]
		print(counting_sort(data, np.max(data)))
	print('spend time:', time.time() - now)


