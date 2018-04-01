import skimage.transform as st
from skimage import feature
from line_func import *


PATH = './data/obj1.txt'
data = np.loadtxt(PATH)

file_out =  './static_data/static_data2.txt'
fout = open(file_out, 'w')

pic = np.zeros([60,75], dtype = np.double)
LEN = len(data)
XY = np.zeros([LEN,2],  dtype = np.int32)

for i in range(0, LEN):
	x = int(data[i][0]*1)
	y = int((data[i][1] + 30)*1)
	pic[y][x] = 255
	XY[i,0], XY[i,1] = x, y

for TH in range(1, 7):
	for LL in range(5, 31):
		for LG in range(1, 31):
			lines = st.probabilistic_hough_line(pic, threshold = TH, line_length= LL,line_gap = LG)
			if len(lines) > 0:
				re = line_func(lines, XY)
				out =  bytes(TH) +'\t' +bytes(LL) + '\t' + bytes(LG) + '\t' + bytes(len(lines)) + '\t' +re + '\n'
				fout.write(out)
			else:
				re2 = '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t' + '0' + '\t'
				out2 = bytes(TH) +'\t' +bytes(LL) + '\t' + bytes(LG) + '\t' + bytes(len(lines)) + '\t' +  re2 + '\n'
				fout.write(out2)

fout.close()




  
