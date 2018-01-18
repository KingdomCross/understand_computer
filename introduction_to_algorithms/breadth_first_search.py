import math
from queue import Queue

class BFS_node:
	def __init__(self, data = 0, color = 'white', deep = 0, pi = []):
		self.data = data
		self.color = color
		self.deep = deep
		self.pi = pi


def BFS(graph, graph_map, graph_source):

	graph_source.color = 'gray'

	Q = Queue()
	Q.put(graph_source)
	while Q.qsize():
		u = Q.get()

		for v in graph_map[u.data][1:]:
			if graph[v].color == 'white':		
				graph[v].color = 'gray'
				graph[v].deep = graph[u.data].deep + 1
				graph[v].pi += [u.data]
				Q.put(graph[v])

		graph[u.data].color = 'black'
	

def print_path(graph, source, final):

	if final.data == source.data:
		print([source.data])
	elif len(final.pi) >= 2:
		print_path(graph, source, graph[final.pi[-1]])
		print(final.pi[:-1])
		
	else:
		print('no path from source node to the final node exists')



if __name__ == '__main__':
	graph = []
	graph_map = [ [0, 1, 4], [1, 0, 4, 2, 3], 
				  [2, 1, 3, 5], [3, 1, 4, 2], 
				  [4, 3, 0, 2], [5], [6, 7],
				  [7, 6]]

	
	for x in range(8):
		graph.append(BFS_node(data = x, pi = [x]))

	BFS(graph, graph_map, graph[0])
	
	print_path(graph, graph[0], graph[6])
	






















'''
from queue import Queue #LILO队列
q = Queue() #创建队列对象
q.put(0)    #在队列尾部插入元素
q.put(1)
q.put(2)
print('LILO队列',q.queue)  #查看队列中的所有元素
print(q.get())  #返回并删除队列头部元素
print(q.queue)

from queue import LifoQueue #LIFO队列
lifoQueue = LifoQueue()
lifoQueue.put(1)
lifoQueue.put(2)
lifoQueue.put(3)
print('LIFO队列',lifoQueue.queue)
lifoQueue.get() #返回并删除队列尾部元素
lifoQueue.get()
print(lifoQueue.queue)

from queue import PriorityQueue #优先队列
priorityQueue = PriorityQueue() #创建优先队列对象
priorityQueue.put(3)    #插入元素
priorityQueue.put(78)   #插入元素
priorityQueue.put(100)  #插入元素
print(priorityQueue.queue)  #查看优先级队列中的所有元素
priorityQueue.put(1)    #插入元素
priorityQueue.put(2)    #插入元素
print('优先级队列:',priorityQueue.queue)  #查看优先级队列中的所有元素
priorityQueue.get() #返回并删除优先级最低的元素
print('删除后剩余元素',priorityQueue.queue)
priorityQueue.get() #返回并删除优先级最低的元素
print('删除后剩余元素',priorityQueue.queue)  #删除后剩余元素
priorityQueue.get() #返回并删除优先级最低的元素
print('删除后剩余元素',priorityQueue.queue)  #删除后剩余元素
priorityQueue.get() #返回并删除优先级最低的元素
print('删除后剩余元素',priorityQueue.queue)  #删除后剩余元素
priorityQueue.get() #返回并删除优先级最低的元素
print('全部被删除后:',priorityQueue.queue)  #查看优先级队列中的所有元素

from collections import deque   #双端队列
dequeQueue = deque(['Eric','John','Smith'])
print(dequeQueue)
dequeQueue.append('Tom')    #在右侧插入新元素
dequeQueue.appendleft('Terry')  #在左侧插入新元素
print(dequeQueue)
dequeQueue.rotate(2)    #循环右移2次
print('循环右移2次后的队列',dequeQueue)
dequeQueue.popleft()    #返回并删除队列最左端元素
print('删除最左端元素后的队列：',dequeQueue)
dequeQueue.pop()    #返回并删除队列最右端元素
print('删除最右端元素后的队列：',dequeQueue)
'''		
