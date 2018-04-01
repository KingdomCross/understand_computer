import numpy as np
import matplotlib.pyplot as plt

''' 
plt.figure(1) 
plt.figure(2) 
ax1 = plt.subplot(211)
ax2 = plt.subplot(212) 
 
x = np.linspace(0, 3, 100)
for i in xrange(5):
    plt.figure(1)
    plt.plot(x, np.exp(i*x/3),'r*')
    plt.sca(ax1) 
    plt.plot(x, np.sin(i*x))
    plt.sca(ax2) 
    plt.plot(x, np.cos(i*x))

plt.xlabel('x')
plt.ylabel('exp')
plt.legend('12345') 
plt.show()

'''


plt.figure(1)
#fd = open('../DBSACN_cluster/cluster_1.data')
#try:
#	all_the_content = fd.read()
#finally:
#	fd.close

# Use numpy to load the data contained in the file
# '*.txt' into a 2-D array called data
data1 = np.loadtxt('/home/dean/projects/understand_computer/DBSCAN/TEST_data/C0.400000')
# data2 = np.loadtxt('../DBSCAN_cluster/cluster_2.txt')

# plot the first column as x, and second column as y
plt.scatter(data1[:, 0], data1[:, 1], c = 'r', s = 1)
plt.xlabel('x(m)')
plt.ylabel('y(m)')
#plt.xlim(0.0, 10.)

plt.grid() # == plt.grid(True)
#plt.grid(color='b' , linewidth='0.3' ,linestyle='--')

plt.show()
