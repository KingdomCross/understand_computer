import time
import sys

def fibonacci(x):
	F = [0, 1]
	if x == 0:
		return 0
	elif x == 1:
		return 1
	else:
		if len(F) == x:
			return F[x-1] + F[x-2]
		else:
			temp = fibonacci(x-1) + fibonacci(x-2)
			F.append(temp)
			return temp

def fibonacci2(x):
	F = [0, 1]
	if x == 0:
		return 0
	elif x == 1:
		return 1
	else:
		return fibonacci(x-1) + fibonacci(x-2)

def fibonacci3(x):
	F = [0, 1]
	if x == 0:
		return 0
	elif x == 1:
		return 1
	else:
		for i in range(2, x + 1):
			F.append(F[i-1] + F[i -2])

	return F[x]
		
		


#********************   main   ********************#

if __name__ == '__main__':
	if len(sys.argv) == 2:
		now = time.time()
		print(fibonacci2(int(sys.argv[1])))
		print('spend time:', time.time() - now)
		
		now = time.time()
		print(fibonacci3(int(sys.argv[1])))
		print('spend time:', time.time() - now)

	else:
		print('no enough parameters')
		print('Ex: python3 fibonacci.py 20')
		print('now, run the test example')
		print('compute fibonacci[1, 10, 20, 30]')
		print('the first program is recursive, the second program is loop')
		for i in [1, 10, 20, 30]:
			now1 = time.time()
			fibonacci2(i)
			now2 = time.time()
			fibonacci3(i)
			now3 = time.time()
			print('the first faster than second:', now3 - 2*now2 + now1, 's')
