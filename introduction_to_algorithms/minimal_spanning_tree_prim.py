'''

Name: 		minimal spanning tree(MST)
Method: 	Prim
descripe:	use the the algorithm to solve the MST problem

'''

#---------------------------- class definition ---------------------------#

import math

class MST_node:
	def __init__(self, weight= {}, pi = []):
		self.weight = weight
		self.pi = pi

#---------------------------- class definition ---------------------------#


def MST_Prim(graph, u):
	
	# all the vertex of the graph
	Q = [ch  for ch in graph.keys()]

	# store the points of minimal spanning tree and its equal to V - Q  
	V_Q = []
 	# store the path of minimal spanning tree in every two characters
	A = [] 
	
	# judge for len(Q) - 1 because of just use all the points in Q 
	# and not the initial value of input u, so judge it
	while len(Q) - 1: 
		V_Q += [u]
		Q.remove(u)
		temp_min = math.inf
		
		# for every points in V_Q, find the minimal weight of r and v
		# and log the minimal weight in r0 and v0
		for r in V_Q: 
			for v in graph[r].weight.keys():
				if graph[r].weight[v] < temp_min and v not in V_Q:
					temp_min = graph[r].weight[v]
					r0 = r
					v0 = v
		u = v0
		A += [r0,v0]
		graph[v0].pi += [r0]
		
		
					
	return A



#********************   main   ********************#

if __name__ == '__main__':

	# the map of the graph
	graph_map = {	'a':{'b':4, 'h':8}, 
				 	'b':{'c':8, 'h':11}, 
					'c':{'i':2, 'f':4, 'd':7, 'b':8}, 
					'd':{'c':7, 'e':9, 'f':14}, 
					'e':{'d':9, 'f':10}, 
					'f':{'g':2, 'c':4, 'e':10, 'd':14}, 
					'g':{'h':1, 'f':2, 'i':6}, 
					'h':{'g':1, 'i':7, 'a':8, 'b':11}, 
					'i':{'c':2, 'g':6, 'h':7}, 
				}
	# just the weight of 'b' and 'c' has difference
	graph_map2 = {	'a':{'b':4, 'h':8}, 
				 	'b':{'c':7, 'h':11}, 
					'c':{'i':2, 'f':4, 'd':7, 'b':7}, 
					'd':{'c':7, 'e':9, 'f':14}, 
					'e':{'d':9, 'f':10}, 
					'f':{'g':2, 'c':4, 'e':10, 'd':14}, 
					'g':{'h':1, 'f':2, 'i':6}, 
					'h':{'g':1, 'i':7, 'a':8, 'b':11}, 
					'i':{'c':2, 'g':6, 'h':7}, 
				}

	# construct the dictory of the graph that has some properties
	graph = {u:MST_node(weight = w, pi = [u]) for u, w in zip(graph_map.keys(), graph_map.values())}
	# for u in graph_map.keys():
	#	print(u, graph[u].pi)
	
	# run the program of the MST_Prim
	print(MST_Prim(graph, 'b'))











