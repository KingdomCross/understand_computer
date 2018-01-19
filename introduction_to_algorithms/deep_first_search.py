#!python3
'''
深度优先搜索算法
'''
#全局访问时间
time = 0

#---------------------------- class definition ---------------------------#

# color：节点颜色，有white，gray，black三种选择
# deep：#第一次访问到该节点的时间
# final：最后一次访问到该节点的时间
# pi：该节点的前驱列表
class DFS_node:
	def __init__(self, color = 'white', deep = 0, final = 0, pi = []):
		self.color = color
		self.deep = deep
		self.final = final
		self.pi = pi

#---------------------------- class definition ---------------------------#


#---------------------------- deep first search ---------------------------#

def DFS(graph, graph_map):
	global time
	# print(time)
	for u in [key for key in graph.keys()]:
		if graph[u].color == 'white':
			DFS_visit(graph, u, graph_map)

def DFS_visit(graph, u, graph_map):
	global time
	time += 1
	graph[u].deep = time
	graph[u].color = 'gray'
	for v in graph_map[u]:
		if graph[v].color == 'white':
			graph[v].pi.append(u)
			DFS_visit(graph, v, graph_map)
	graph[u].color = 'black'
	time += 1
	graph[u].final = time

#---------------------------- deep first search ---------------------------#

#---------------------------- topological sort ---------------------------#

def topological_sort(topo_graph, topo_graph_map):
	
	DFS(topo_graph, topo_graph_map)

	for key in topo_graph_list:
		print(key, '\t\t', topo_graph[key].deep, '\t\t', topo_graph[key].final)
	
	#
	print('\nTopological sort')
	sort_list = []
	topo_graph_copy = topo_graph.copy()
	for key in topo_graph_list:
		sort_list += [topo_graph[key].final]
	
	import ps_sort
	sort_list = ps_sort.insertion_sort(sort_list)
	# print(sort_list)
	for v in sort_list:
		for u in topo_graph_list:
			if topo_graph[u].final == v:
				print(u)
				topo_graph.pop(u)
				topo_graph_list.remove(u)

#---------------------------- topological sort ---------------------------#



#********************   main   ********************#

if __name__ == '__main__':

	#---------------------------- deep first search example ---------------------------#
	# 这是图节点，后面讲用类初始化
	graph_list = ['u', 'v', 'w', 'x', 'y', 'z']
	# 这是节点之间的映射关系，这是有向图
	graph_map = {'u':['v', 'x'], 
				 'v':['y'], 
				 'w':['z', 'y'], 
				 'x':['v'], 
				 'y':['x'], 
				 'z':['z']}
	# print(graph_map['u'])

	graph = {key:DFS_node(pi = [key]) for key in graph_list}
	# print(graph['v'].color)
	DFS(graph, graph_map)
	for key in graph_list:
		print(key, '\t', graph[key].deep, '\t', graph[key].final)



	#---------------------------- topological sort example---------------------------#
	time = 0

	topo_graph_list = [ 'knickers', 'pants', 'belt', 'shirt', 'tie', 'jacket','socks', 'shoes', 'watch']
	topo_graph_map = {
				 'pants':['belt', 'shoes'],
				 'knickers':['pants', 'shoes'],
				 'belt':['jacket'], 
				 'shirt':['tie', 'belt'], 
				 'tie':['jacket'], 
				 'jacket':[],
				 'socks':['shoes'], 
				 'shoes':[], 
				 'watch':[]
				}
	topo_graph = {key:DFS_node(pi = [key]) for key in topo_graph_list}
	
	topological_sort(topo_graph, topo_graph_map)






















