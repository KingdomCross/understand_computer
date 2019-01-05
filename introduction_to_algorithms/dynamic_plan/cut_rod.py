#!/usr/bin/python3
import math

def cut_rod(price, length):
	if length == 0:
		return 0

	temp = -math.inf
	for i in range(1, length + 1):
		temp = max(temp, price[i] + cut_rod(price ,length -i ))

	return temp


if __name__ == '__main__':
	price = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 37, 
			 45, 55, 67, 80, 85, 95, 100, 110, 115, 118,
			 119, 123, 135, 148, 159, 179]

	optimal = cut_rod(price, 20)
	print(optimal)
