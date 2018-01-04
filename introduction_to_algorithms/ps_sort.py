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

	print('XXXXXXXXXXXXXXXXX<insertion_sort>XXXXXXXXXXXXXXXXX')	
	
		
