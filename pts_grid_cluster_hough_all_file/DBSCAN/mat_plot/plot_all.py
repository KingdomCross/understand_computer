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

for i in range(1,LEN):
	PATH = PATH_pre + str(i) +'.txt'
	try:
		data = np.loadtxt(PATH)
		size_data = len(data[:,0])
		xc = sum(data[:,0])/size_data
		yc = sum(data[:,1])/size_data
		# pl.plot(xc,yc,'kx', linewidth='2')
		print(xc,yc)
		pl.plot(data[:,0],data[:,1],'r.',linewidth='0.3')
	except:
		print('Error')
		

# plot the first column as x, and second column as y
#pl.xlim(0.0, 10.)

pl.grid() # == plt.grid(True)
#pl.grid(color='b' , linewidth='0.3' ,linestyle='--')

pl.show()


