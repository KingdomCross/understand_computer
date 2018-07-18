
#coding=utf-8

import numpy as np
import scipy
import matplotlib.pyplot as pl
import skimage.transform as st
from skimage import feature
import os

PATH = '../data/cluster/005/'

folders = os.listdir(PATH)
i = 0
for folder in folders:
		PATH = '../data/cluster/005/'
		OUT_PATH = '../data/cluster_point/'
		i =  i + 1
		if not os.path.isdir(folder):
			PATH = PATH + folder + '/'
			OUT_PATH = OUT_PATH + str(i) + '.txt'
			fout = open(OUT_PATH, 'w')
			files = os.listdir(PATH)
			for file in files:
				if not os.path.isdir(file):
					data = np.loadtxt(PATH + file)
					for (x,y) in data:
						fout.write(str(x) + '\t' + str(y) + '\n')
					
					
			
						
		
