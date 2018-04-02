import numpy as np
import matplotlib.pyplot as pl
import math
import os

#fd = open('../DBSACN_cluster/cluster_1.data')
#try:
#	all_the_content = fd.read()
#finally:
#	fd.close

# Use numpy to load the data contained in the file
# '*.txt' into a 2-D array called data
LEN = len(os.listdir('../DBSCAN_cluster')) - 2
PATH_pre = '../DBSCAN_cluster/cluster_'

PATH_OUT_CEN = './centers_cluster.txt'
fout_center = open(PATH_OUT_CEN,'w')

PATH_OUT_P = './points_cluster.txt'
fout_point = open(PATH_OUT_P,'w')

for i in range(1,LEN):
	PATH = PATH_pre + str(i) +'.txt'
	try:
		data = np.loadtxt(PATH)
		for (x, y) in data: 
			fout_point.write(str(x) + '\t' + str(y) + '\n')
		size_data = len(data[:,0])
		xc = sum(data[:,0])/size_data
		yc = sum(data[:,1])/size_data
		fout_center.write(str(xc)  + '\t' + str(yc) + '\n')
		
	except:
		print('Error')
		

fout_center.close()
fout_point.close()

