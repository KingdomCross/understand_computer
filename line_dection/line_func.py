import numpy as np
import scipy
import matplotlib.pyplot as pl

def line_func(lines, XY):
	dminL = 100
	dminR = 100
	Lstate = 0
	Rstate = 0
	
	for (p0, p1) in lines:
		# print(p0, p1)
		x0, y0 = p0[0], p0[1] - 30
		x1, y1 = p1[0], p1[1] - 30
		# print(x0,y0,x1,y1)
		if x1 - x0 == 0:
			k = 99999
			b = 0
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
		pass
		# pl.plot((xl0, xl1), (yl0, yl1),'r')
	else:
		xl0, xl1 = 10000.0, 10000.0
		yl0, yl1 = 10000.0, 10000.0
		
		
	if Rstate == 1:
		pass
		# pl.plot((xr0, xr1), (yr0, yr1),'r')
	else:
		xr0, xr1 = 10000.0, 10000.0
		yr0, yr1 = 10000.0, 10000.0
	'''
	pl.plot(XY[:,0],XY[:,1] - 30, 'kx') 
	pl.xlabel('x(m)') 
	pl.ylabel('y(m)')    
	pl.grid() 
	pl.show()
	'''
	return bytes(Lstate) + '\t' + str(xl0)  + '\t' + str(xl1)  + '\t' + str(yl0)  + '\t' + str(yl0)  + '\t' + bytes(Rstate) + '\t' + str(xr0)  + '\t' + str(xr1)  + '\t' + str(yr0)  + '\t' + str(yr0)  + '\t'
	
