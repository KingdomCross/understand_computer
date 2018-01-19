#---------------------------- class definition ---------------------------#

import math

class MST_node:
	def __init__(self, weight= {}, pi = []):
		self.weight = weight
		self.pi = pi

#---------------------------- class definition ---------------------------#


def MST_Prim(graph, u):
	graph[u].key = 0
	Q = [ch  for ch in graph.keys()]
	V_Q = []
	A = []
	while len(Q) - 1:
		V_Q += [u]
		Q.remove(u)
		temp_min = math.inf
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
	graph = {u:MST_node(weight = w, pi = [u]) for u, w in zip(graph_map.keys(), graph_map.values())}
	# for u in graph_map.keys():
	#	print(u, graph[u].pi)
	print(MST_Prim(graph, 'b'))











