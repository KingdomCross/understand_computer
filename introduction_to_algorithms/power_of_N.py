import time
import sys

def power(x, n):
	'''
	sovle the x^n
	'''
	if n == 0:
		return 1
	elif n % 2 == 0:
		f0 = power(x, n//2)
		return f0 * f0 
	else:
		f1 = power(x, n//2)
		return f1 * f1 * x

def power2(x, n):
	re = 1;
	for i in range(1, n+1):
		re *= x
	return re

#********************   main   ********************#

if __name__ == '__main__':
	if len(sys.argv) == 3:
		now = time.time()
		print(power(int(sys.argv[1]), int(sys.argv[2])))
		print('spend time:', time.time() - now)

		now = time.time()
		print(power2(int(sys.argv[1]), int(sys.argv[2])))
		print('spend time:', time.time() - now)

	else:
		print('no enough parameters')
		print('Ex: python3 power_of_N.py 2 100')
		print('now, run the test example')
		print('compute 2^[1, 10, 100, 1000, 10000, 100000]')
		print('the first program is recursive, the second program is loop')
		for i in [1, 10, 100, 1000, 10000, 100000]:
			now1 = time.time()
			power(2, i)
			now2 = time.time()
			power2(2, i)
			now3 = time.time()
			print('the first faster than second:', now3 - 2*now2 + now1, 's')
	
	
