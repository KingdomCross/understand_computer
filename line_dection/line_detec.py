import numpy as np
# import scipy


PATH = './data/C0.400000'
data = np.loadtxt(PATH)
# print(data)

pic = np.zeros([6000,7500], dtype = np.int8)

LEN = len(data)
# print(LEN)

for i in range(0, LEN):
	x = int(data[i][0]*100)
	y = int((data[i][1] + 30)*100)
	# print(data[i][0], x)
	# print(data[i][1], y)
	pic[y][x] = 255

import skimage.transform as st


# x = np.random.random((600,800,3))
# scipy.misc.imsave('meelo.jpg', x)
