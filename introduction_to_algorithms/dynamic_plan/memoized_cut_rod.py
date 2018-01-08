import math
import numpy as np

def memoized_cut_rod_aux(price, length, array):
	if array[length] >= 0:
		return array[length]

	if length == 0:
		temp = 0
	else:
		temp = -math.inf
		for i in range(1, length + 1):
			temp = max(temp, price[i] + memoized_cut_rod_aux(price, length - i, array))
	array[length] = temp
	return temp

def memoized_cut_rod(price, length):
	array = []
	for i in range(0, length + 1):
		array.append(-math.inf)
	
	return memoized_cut_rod_aux(price, length, array)

if __name__ == '__main__':
	price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 37, 
			 45, 55, 67, 80, 85, 95, 100, 110, 115, 118,
			 119, 123, 135, 148, 159, 179]

	optimal = memoized_cut_rod(price, 20)
	print(optimal)
