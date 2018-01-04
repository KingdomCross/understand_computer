import sys
import string
import math


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

def merge_sort(data, left, right):
	if left < right:
		mid = ( left + right)//2
		merge_sort(data, left, mid)
		merge_sort(data, mid + 1, right)
		merge(data, left, mid, right)
	return data

#-----------------   merge_sort   -----------------#


if __name__ == '__main__':
	print('XXXXXXXXXXXXXXXXX<insertion_sort>XXXXXXXXXXXXXXXXX')
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]
			print(insertion_sort(data2))
		fin.close()
	except:
		print('No input file, select default input data')
		# data = [1,3,2,4,5]
		# data = ['2', '1', '3']
		data = ['you', 'are', 'girl']
		print(insertion_sort(data))

	print('XXXXXXXXXXXXXXXXXXXX<merge_sort>XXXXXXXXXXXXXXXXXXX')	
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]
			print(merge_sort(data2, 0, len(data2) - 1))
		fin.close()
	except:
		print('No input file, select default input data')
		data = [1,3,2,4,5]
		print(merge_sort(data, 0, len(data) - 1))
	
		
