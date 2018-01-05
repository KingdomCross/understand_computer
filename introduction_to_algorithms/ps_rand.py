import random 
import sys
if len(sys.argv) == 4:
	try:
		output_number	= int(sys.argv[1])
		range_left		= int(sys.argv[2])
		range_right		= int(sys.argv[3])
	except:
		print(' the type of parameters is error')

	for i in range(0, output_number):
		print(random.randint(range_left, range_right))

elif len(sys.argv) == 5:
	try:
		output_number	= int(sys.argv[1])
		range_left		= int(sys.argv[2])
		range_right		= int(sys.argv[3])
	except:
		print(' the type of parameters is error')

	fin = open(sys.argv[4], 'w')
	for i in range(0, output_number):
		print(random.randint(range_left, range_right), file = fin)
	fin.close()

else:
	print('the system parameter should have 3 or 4.')
	print('the first parameter is the number of output,')
	print('the second parameter is the range of left,')
	print('the third parameter is the range of right')
	print('the fourth parameter is output file name')
	print('example 1: $ python3 ps_rand.py 10 0 20')
	print('example 2: $ python3 ps_rand.py 10 0 20 data.dean')

