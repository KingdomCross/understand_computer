import numpy as np
import matplotlib.pyplot as pl

#fd = open('../DBSACN_cluster/cluster_1.data')
#try:
#	all_the_content = fd.read()
#finally:
#	fd.close

# Use numpy to load the data contained in the file
# '*.txt' into a 2-D array called data
data1 = np.loadtxt('../DBSCAN_cluster/cluster_1.txt')
data2 = np.loadtxt('../DBSCAN_cluster/cluster_2.txt')
data3 = np.loadtxt('../DBSCAN_cluster/cluster_3.txt')
data4 = np.loadtxt('../DBSCAN_cluster/cluster_4.txt')
data5 = np.loadtxt('../DBSCAN_cluster/cluster_5.txt')
data6 = np.loadtxt('../DBSCAN_cluster/cluster_6.txt')
data7 = np.loadtxt('../DBSCAN_cluster/cluster_7.txt')
data8 = np.loadtxt('../DBSCAN_cluster/cluster_8.txt')
data9 = np.loadtxt('../DBSCAN_cluster/cluster_9.txt')
data10 = np.loadtxt('../DBSCAN_cluster/cluster_10.txt')
data11 = np.loadtxt('../DBSCAN_cluster/cluster_11.txt')
data12 = np.loadtxt('../DBSCAN_cluster/cluster_12.txt')
data13 = np.loadtxt('../DBSCAN_cluster/cluster_13.txt')
data14 = np.loadtxt('../DBSCAN_cluster/cluster_14.txt')
data15 = np.loadtxt('../DBSCAN_cluster/cluster_15.txt')
data16 = np.loadtxt('../DBSCAN_cluster/cluster_16.txt')
data17 = np.loadtxt('../DBSCAN_cluster/cluster_17.txt')
data18 = np.loadtxt('../DBSCAN_cluster/cluster_18.txt')
data19 = np.loadtxt('../DBSCAN_cluster/cluster_19.txt')
data20 = np.loadtxt('../DBSCAN_cluster/cluster_20.txt')
data21 = np.loadtxt('../DBSCAN_cluster/cluster_21.txt')


# plot the first column as x, and second column as y
pl.plot(data1[:, 0], data1[:, 1],'r.',
		data2[:, 0], data2[:, 1],'g.',
		data3[:, 0], data3[:, 1],'b.',
		data4[:, 0], data4[:, 1],'r.',
		data5[:, 0], data5[:, 1],'g.',
		data6[:, 0], data6[:, 1],'b.',
		data7[:, 0], data7[:, 1],'r.',
		data8[:, 0], data8[:, 1],'g.',
		data9[:, 0], data9[:, 1],'b.',
		data10[:, 0], data10[:, 1],'r.',
		data11[:, 0], data11[:, 1],'r.',
		data12[:, 0], data12[:, 1],'g.',
		data13[:, 0], data13[:, 1],'b.',
		data14[:, 0], data14[:, 1],'r.',
		data15[:, 0], data15[:, 1],'g.',
		data16[:, 0], data16[:, 1],'b.',
		data17[:, 0], data17[:, 1],'r.',
		data18[:, 0], data18[:, 1],'g.',
		data19[:, 0], data19[:, 1],'b.',
		data20[:, 0], data20[:, 1],'r.',
		data21[:, 0], data21[:, 1],'r.',
		
		)

#pl.xlim(0.0, 10.)

pl.grid() # == plt.grid(True)
#pl.grid(color='b' , linewidth='0.3' ,linestyle='--')

pl.show()



'''
data22 = np.loadtxt('../DBSCAN_cluster/cluster_22.txt')
data23 = np.loadtxt('../DBSCAN_cluster/cluster_23.txt')
data24 = np.loadtxt('../DBSCAN_cluster/cluster_24.txt')
data25 = np.loadtxt('../DBSCAN_cluster/cluster_25.txt')
data26 = np.loadtxt('../DBSCAN_cluster/cluster_26.txt')
data27 = np.loadtxt('../DBSCAN_cluster/cluster_27.txt')
data28 = np.loadtxt('../DBSCAN_cluster/cluster_28.txt')
data29 = np.loadtxt('../DBSCAN_cluster/cluster_29.txt')
data30 = np.loadtxt('../DBSCAN_cluster/cluster_30.txt')
data31 = np.loadtxt('../DBSCAN_cluster/cluster_31.txt')
data32 = np.loadtxt('../DBSCAN_cluster/cluster_32.txt')
data33 = np.loadtxt('../DBSCAN_cluster/cluster_33.txt')
data34 = np.loadtxt('../DBSCAN_cluster/cluster_34.txt')
data35 = np.loadtxt('../DBSCAN_cluster/cluster_35.txt')
data36 = np.loadtxt('../DBSCAN_cluster/cluster_36.txt')
data37 = np.loadtxt('../DBSCAN_cluster/cluster_37.txt')
data38 = np.loadtxt('../DBSCAN_cluster/cluster_38.txt')
data39 = np.loadtxt('../DBSCAN_cluster/cluster_39.txt')
data40 = np.loadtxt('../DBSCAN_cluster/cluster_40.txt')





data22[:, 0], data22[:, 1],'g.',
		data23[:, 0], data23[:, 1],'b.',
		data24[:, 0], data24[:, 1],'r.',
		data25[:, 0], data25[:, 1],'g.',
		data26[:, 0], data26[:, 1],'b.',
		data27[:, 0], data27[:, 1],'r.',
		data28[:, 0], data28[:, 1],'g.',
		data29[:, 0], data29[:, 1],'b.',
		data30[:, 0], data30[:, 1],'r.',
		data31[:, 0], data31[:, 1],'r.',
		data32[:, 0], data32[:, 1],'g.',
		data33[:, 0], data33[:, 1],'b.',
		data34[:, 0], data34[:, 1],'r.',
		data35[:, 0], data35[:, 1],'g.',
		data36[:, 0], data36[:, 1],'b.',
		data37[:, 0], data37[:, 1],'r.',
		data38[:, 0], data38[:, 1],'g.',
		data39[:, 0], data39[:, 1],'b.',
		data40[:, 0], data40[:, 1],'r.',
		
'''

