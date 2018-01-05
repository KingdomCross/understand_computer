#! /usr/bin/python3.5

import sys

'''

purpose  : find the N small number in input data
function : randomized_select(data, N)
parameter: data, can be number
output   : the N small number

'''

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

def randomized_select(data, left , right , N):
	if left == right:
		return data[left]
	mid = randomized_partition(data, left, right)
	temp = mid - left +1 
	if N == temp:		# the pivot value is the answer
		return data[mid]
	elif N < temp:
		return randomized_select(data, left, mid -1, N)
	else:
		return randomized_select(data,mid + 1, right, N - temp)


#XXXXXXXXXXXXXXXXX < main > XXXXXXXXXXXXXXXXX#

if __name__ == '__main__':
	import time
	now = time.time()
	try:
		if sys.argv[1]:
			data = ''
			fin = open(sys.argv[1], 'r')
			for data_in in fin:
				data += data_in
			data2 = [int(num) for num in data.split()]
			print('data = \n', data2)
			print('the', len(data)//4, 'small number is:')
			print(randomized_select(data2, 0, len(data2)-1, len(data2)//4))

		fin.close()
	except:
		print('No input file, select default input data')
		data = [1,3,2,4,5,45,5,6,7,12,34,56,7,43,21,15,16,27,23,78]
		print('data = \n', data)
		print('the', len(data)//4, 'small number is:')
		print(randomized_select(data, 0, len(data)-1, len(data)//4))
	print('spend time:', time.time() - now)

