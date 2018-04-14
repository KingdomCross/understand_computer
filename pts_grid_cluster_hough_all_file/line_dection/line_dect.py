
#coding=utf-8

import numpy as np
import scipy
import matplotlib.pyplot as pl
import skimage.transform as st
from skimage import feature
import os

PATH = '../data/cluster_point/'
files = os.listdir(PATH)

for file in files:
	if not os.path.isdir(file):
		data = np.loadtxt(PATH + file)
		print(PATH + file)
		LEN = len(data)
		# print(LEN)
		pic = np.zeros([600,500], dtype = np.double)
		XY = np.zeros([LEN,2],  dtype = np.int32)
		for i in range(0, LEN):
			x = int(data[i][0]*10)
			y = int(((data[i][1])*10)+ 300)
			if x >= 500:
				x = 499
			if y >= 600:
				y = 599
			pic[y][x] = 255
			XY[i,0], XY[i,1] = x, y
		# print(pic)	
						
		lines = st.probabilistic_hough_line(pic, threshold = 1, line_length= 20,line_gap = 250)
		
		dminL = 1000
		dminR = 1000
		Lstate = 0
		Rstate = 0
		
		# print(lines)
		for (p0, p1) in lines:
			print(p0, p1)
			x0, y0 = p0[0], p0[1] - 300
			x1, y1 = p1[0], p1[1] - 300
			# print(x0,y0,x1,y1)
			if x1 - x0 == 0:
				k = 99999999
				b = x0
			else:
				k = (y1 - y0)*1.0/(x1 - x0)
				b = y0 - k*x0
			# print(k, b)
			pl. plot((x0, x1), (y0, y1), 'b--')
			d = abs(b)  / (1 + k*k)**0.5
			# print(d)
		
			if abs(k) < 0.05 and b >= 0 and d < dminL:
				xl0, xl1 = x0, x1
				yl0, yl1 = y0, y1
				dminL = d
				Lstate = 1
			
			else:
				pass			
			if abs(k) < 0.05 and b < 0 and d < dminR:
				xr0, xr1 = x0, x1
				yr0, yr1 = y0, y1
				dminR = d
				Rstate = 1
			else:
				pass
				
		# print(Lstate, Rstate)			
		if Lstate == 1:
			# pass
			pl.plot((xl0, xl1), (yl0, yl1),'r')
		else:
			pass
		
		
		if Rstate == 1:
			# pass
			pl.plot((xr0, xr1), (yr0, yr1),'r')
		else:
			pass
						
		
		pl.plot(XY[:,0],XY[:,1] - 300, 'k.') 
		pl.xlabel('x') 
		pl.ylabel('y')    
		pl.grid() 
		pl.show()


    

