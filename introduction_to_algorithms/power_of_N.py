import time
import sys

def power(x, n):
	'''
	sovle the x^n
	'''
	if n == 0:
		return 1
	elif n % 2 == 0:
		return power(x, n//2)*power(x, n//2)
	else:
		return power(x, n//2)*power(x, n//2) * x

def power2(x, n):
	re = 1;
	for i in range(1, n+1):
		re *= x

#********************   main   ********************#

if __name__ == '__main__':
	if len(sys.argv) == 3:
		now = time.time()
		print(power(int(sys.argv[1]), int(sys.argv[2])))
		print('spend time:', time.time() - now)

		now = time.time()
		print(power(int(sys.argv[1]), int(sys.argv[2])))
		print('spend time:', time.time() - now)

	else:
		print('no enough parameters')
		print('Ex: python3 power_of_N.py 2 100')
	
	
