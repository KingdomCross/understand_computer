import numpy as np
import scipy
import matplotlib.pyplot as pl
import skimage.transform as st
from skimage import feature

file_out = './data/T2L5G05.txt'
fout = open(file_out, 'w')

file_out2 = './data/T2L5G05_min.txt'
fout2 = open(file_out2, 'w')

# PATH = './data/C0.400000'
PATH = './data/obj1.txt'
data = np.loadtxt(PATH)
# print(data)

pic = np.zeros([600,600], dtype = np.double)

LEN = len(data)
# print(LEN)
XY = np.zeros([LEN,2],  dtype = np.int32)

for i in range(0, LEN):
	x = int((data[i][0] + 30)*10)
	y = int(((data[i][1] + 30)*10))
	pic[x][y] = 255
	# print(x,y)
	XY[i,0], XY[i,1] = x, y
# print(pic)
# pic = feature.canny(pic, sigma=2, low_threshold=1, high_threshold=25)
lines = st.probabilistic_hough_line(pic, threshold = 2, line_length= 50,line_gap = 200)
# print(lines)

dminL = 100
dminR = 100
# pl.figure(figsize=(8,6), dpi=100)
for line in lines:
    p0, p1 = line
    print(p0, p1)
    x0, y0 = p0[0] - 300, p0[1] - 300
    x1, y1 = p1[0] - 300, p1[1] - 300
    if x1 - x0 ==0:
    	k = 999999999
    	b = x0
    else:
    	k = (y1 - y0)*1.0/(x1 - x0)
    	b = y0 - k*x0
    print(k, b)
    pl. plot((y0, y1), (x0, x1), 'b--')
    fout.write(str(x0) + '\t' + str(x1) + '\t' + str(y0) + '\t' +str(y1) + '\n')
  
pl.plot((data[:,0] + 30)*10 - 300, (data[:,1] + 30)*10 - 300, 'kx') 
# pl.plot(XY[:, 0] - 3000, XY[:, 1] - 3000, 'kx') 
pl.xlabel('x(m)') 
pl.ylabel('y(m)')    
pl.grid() 
pl.show()

fout.close()
fout2.close()
  
