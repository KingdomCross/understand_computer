import numpy as np
import scipy
import matplotlib.pyplot as pl
import skimage.transform as st
from skimage import feature

# PATH = './data/C0.400000'
PATH = './data/obj1.txt'
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
# print(pic)
# pic = feature.canny(pic, sigma=2, low_threshold=1, high_threshold=25)
lines = st.probabilistic_hough_line(pic, threshold = 1, line_length= 2,line_gap = 10)
# print(lines)

dminL = 100
dminR = 100

for line in lines:
    p0, p1 = line
    print(p0, p1)
    x0, y0 = p0[0], p0[1] - 30
    x1, y1 = p1[0], p1[1] - 30
    k = (y1 - y0)*1.0/(x1 - x0)
    b = y0 - k*x0
    print(k, b)
    pl. plot((x0, x1), (y0, y1), 'b--')
    d = abs(b)  / (1 + k*k)**0.5
    print(d)
    if abs(k) < 0.05:
    	if b >= 0 and d < dminL:
    		xl0, xl1 = x0, x1
    		yl0, yl1 = y0, y1
    		dminL = d
    		
    	if b < 0 and d < dminR:
    		xr0, xr1 = x0, x1
    		yr0, yr1 = y0, y1
    		dminR = d
			
pl.plot((xl0, xl1), (yl0, yl1),'r')
pl.plot((xr0, xr1), (yr0, yr1),'r')
pl.plot(XY[:,0],XY[:,1] - 30, 'kx') 
pl.xlabel('x(m)') 
pl.ylabel('y(m)')    
pl.grid() 
pl.show()

  
