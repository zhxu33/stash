def bfs(graph, root):
    found = [] 
    queue = [] 
    found.append(root)
    queue.append(root)
    while queue:    
        m = queue.pop(0) 
        print (m, end = " ") 
        for node in graph[m]:
            if node not in found:
                found.append(node)
                queue.append(node)
    
graph = {0: set([1,2,3]),
         1: set([0,4,5,6]),
         2: set([0]),
         3: set([0,7,8]),
         4: set([1,9]),
         5: set([1]),
         6: set([1]),
         7: set([3]),
         8: set([3]),
         9: set([4]),
        }    
bfs(graph, 0)