def recursive_activity_selector(s, f, k, n):
	'''
	s: the time of the start of the activity
	f: the time of the finish of the activity
	k: the number of the subquestion
	n: the number of the question
	tips:
		the algorithm aim to solve the max number 
	activities by the 'greedy algorithm'
		for detail informations, please see the 
	book <algorithm introduction> P239

	'''

	m = k + 1
	while m <= n and s[m] < f[k]:
		m += 1
	if m <= n:
		return [m] + recursive_activity_selector(s, f, m, n)
	else:
		return []

def greedy_activity_selector(s, f):
	n = len(s)
	A = [1]
	k = 1
	# range(m, n) express [m, n)
	for m in range(2, n):
		if s[m] >= f[k]:
			A += [m]
			k = m
	return A


#********************   main   ********************#

if __name__ == '__main__':
	s = [0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]

	# the f list should has a little order
	f = [0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]

	k = 0
	n = len(s) - 1
	print(recursive_activity_selector(s, f, k, n))
	print(greedy_activity_selector(s, f))
