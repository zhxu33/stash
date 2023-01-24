def dfs(graph, root):
    found = [] 
    stack = [] 
    stack.append(root)
    while stack:         
        m = stack.pop()
        if (not m in found):
            print(m,end=' ')
            found.append(m)
            for node in graph[m]:
                if (not node in found):
                    stack.append(node)
    
graph = {0: set([1,2]),
         1: set([3,4]),
         2: set([0,3]),
         3: set([1,5]),
         4: set([5,6]),
         5: set([4,6]),
         6: set([4,5]),
        }    
dfs(graph, 0)