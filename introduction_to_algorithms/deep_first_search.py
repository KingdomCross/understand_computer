#!python3
'''
深度优先搜索算法
'''
#全局访问时间
time = 0


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
	DFS(graph)
	for key in graph_list:
		print(key, graph[key].deep, graph[key].final, graph[key].pi	)






















