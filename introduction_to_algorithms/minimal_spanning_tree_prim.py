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
	graph_map3 = {'N1':{'N2':47,'N3':47,'N4':71,'N5':108,'N6':84,'N7':96,'N8':186,'N9':134,'N10':114,'N11':73,'N15':38},
				  'N2':{'N1':47,'N3':44,'N4':85,'N5':86,'N6':97,'N15':64},
				  'N3':{'N1':47,'N2':44,'N6':59,'N7':148,'N8':109,'N9':137,'N10':89,'N11':111,'N15':64},
				  'N4':{'N1':71,'N2':85,'N5':70,'N6':51,'N15':43},
				  'N5':{'N1':108,'N2':86,'N4':70,'N6':43,'N15':26},
				  'N6':{'N1':84,'N2':97,'N3':59,'N4':51,'N7':74,'N8':69,'N9':61,'N10':28,'N11':34,'N15':41},
				  'N7':{'N1':96,'N3':148,'N6':74,'N8':82,'N9':20,'N10':59,'N11':73,'N12':178,'N15':114},
				  'N8':{'N1':186,'N3':109,'N6':69,'N7':82,'N9':76,'N10':73,'N11':109,'N12':239,'N15':91},
				  'N9':{'N1':134,'N3':137,'N6':61,'N7':20,'N8':76,'N10':64,'N11':87,'N12':169,'N13':204,'N15':101},
				  'N10':{'N1':114,'N3':89,'N6':28,'N7':59,'N8':73,'N9':64,'N11':49,'N12':254,'N15':59},
				  'N11':{'N1':73,'N3':111,'N6':34,'N7':73,'N8':109,'N9':87,'N10':49,'N12':227,'N13':247,'N15':81},
				  'N12':{'N7':178,'N8':239,'N9':169,'N10':254,'N11':227,'N13':28,'N14':56,'N16':73,'N17':24,'N18':29},
				  'N13':{'N9':204,'N11':247,'N12':28,'N14':80,'N16':44,'N17':56,'N18':38},
				  'N14':{'N12':56,'N13':80,'N16':106,'N17':87,'N18':81},
				  'N15':{'N1':38,'N2':64,'N3':64,'N4':43,'N5':26,'N6':41,'N7':114,'N8':91,'N9':101,'N10':59,'N11':81},
				  'N16':{'N12':73,'N13':44,'N14':106,'N17':104,'N18':87},
				  'N17':{'N12':24,'N13':56,'N14':87,'N16':104,'N18':76},
				  'N18':{'N12':29,'N13':38,'N14':81,'N16':87,'N17':76},
				  }

	# construct the dictory of the graph that has some properties
	graph = {u:MST_node(weight = w, pi = [u]) for u, w in zip(graph_map3.keys(), graph_map3.values())}
	# for u in graph_map.keys():
	#	print(u, graph[u].pi)
	
	# run the program of the MST_Prim
	print(MST_Prim(graph, 'N1'))











