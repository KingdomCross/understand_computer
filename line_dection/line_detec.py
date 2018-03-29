import numpy as np
import scipy
import matplotlib.pyplot as pl
import skimage.transform as st
from skimage import feature

# PATH = './data/C0.400000'
PATH = './data/obj.txt'
data = np.loadtxt(PATH)
# print(data)

pic = np.zeros([60,75], dtype = np.double)

LEN = len(data)
# print(LEN)
XY = np.zeros([LEN,2],  dtype = np.int32)

for i in range(0, LEN):
	x = int(data[i][0]*1)
	y = int((data[i][1] + 30)*1)
	pic[y][x] = 255
	# print(x,y)
	XY[i,0], XY[i,1] = x, y

# pic = feature.canny(pic, sigma=2, low_threshold=1, high_threshold=25)
lines = st.probabilistic_hough_line(pic, threshold = 5, line_length= 20,line_gap = 10)
# print(lines)

for line in lines:
    p0, p1 = line
    print(p0, p1)
    pl.plot((p0[0], p1[0]), (p0[1], p1[1]),'r')
'''

h, theta, d = st.hough_line(pic)

row1, col1 = pic.shape
for _, angle, dist in zip(*st.hough_line_peaks(h, theta, d)):
    y0 = (dist - 0 * np.cos(angle)) / np.sin(angle)
    y1 = (dist - col1 * np.cos(angle)) / np.sin(angle)
    pl.plot((0, col1), (y0, y1), '-r')
 
'''	 
    
pl.plot(XY[:,0],XY[:,1], 'kx')    
pl.grid() 
pl.show()
