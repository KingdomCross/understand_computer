#!python3
'''
shen度优先搜索算法
'''

time = 0

class DFS_node:
	def __init__(self, color = 'white', deep = 0, final = 0, pi = []):
		self.color = color
		self.deep = deep
		self.final = final
		self.pi = pi


def DFS(graph):
	global time
	# print(time)
	for u in [key for key in graph.keys()]:
		if graph[u].color == 'white':
			DFS_visit(graph, u)

def DFS_visit(graph, u):
	global time
	time += 1
	graph[u].deep = time
	graph[u].color = 'gray'
	for v in graph_map[u]:
		if graph[v].color == 'white':
			graph[v].pi.append(u)
			DFS_visit(graph, v)
	graph[u].color = 'black'
	time += 1
	graph[u].final = time





if __name__ == '__main__':
	graph_list = ['u', 'v', 'w', 'x', 'y', 'z']
	graph_map = {'u':['v', 'x'], 
				 'v':['y'], 
				 'w':['z', 'y'], 
				 'x':['v'], 
				 'y':['x'], 
				 'z':['z']}
	# print(graph_map['u'])

	graph = {key:DFS_node(pi = [key]) for key in graph_list}
	# print(graph['v'].color)
	DFS(graph)
	for key in graph_list:
		print(key, graph[key].deep, graph[key].final, graph[key].pi	)






















