def runErrands(graph: list[list[int]]) -> int:
  res = float('inf')
  visit = set()
  def dfs(i):
    if len(visit) == len(graph) or i in visit:
      return 0
    visit.add(i)
    cur = 1
    for c in graph[i]:
      cur = min(cur, 1+dfs(ord(c) - ord('a')))
      print(cur)
    visit.remove(i)
    return cur
  for i in range(len(graph)):
    res = min(res,dfs(i))
  return res

# Example 1
graph1 = [['b','c','d'],['a'],['a'],['a']]
print(runErrands(graph1))
# Exptected Output: "4"
# One possible path is [b,a,c,a,d]

#Example 2
graph2 = [['b'],['a','c','e'],['b','d','e'],['c'],['b','c']]
print(runErrands(graph2))
# Exptected Output: "4"
# One possible path is [a, b, e, c, d]

class ListNode:
    def __init__(self, key = -1, val = -1):
        self.key = key
        self.val = val
        self.next = None

class clipboard:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.accessHeap = [] #access amount, key
        self.map = {}

    def paste(self, key: int) -> int:
      return map[key]
        
    def copy(self, key: int, value: int) -> None:
      self.map[key] = value
      pass

# Your clipboard object will be instantiated and called as such:
# clip = clipboard(capacity)
# clip.put(key,value)
# param_1 = clip.get(key)


clip = clipboard(2)
clip.copy(1, 1) # clip is {1=1}
clip.copy(2, 2) # clip is {1=1, 2=2}
clip.paste(1) # return 1
clip.copy(3, 3) 
# Least recently accessed key was 2, evicts key 2, clipboard is {1=1, 3=3}
clip.paste(2)    # returns -1 (not found)
clip.copy(4, 4) 
# Least recently accessed key was 1, evicts key 1, clipboard is {4=4, 3=3}
clip.paste(1)    # return -1 (not found)
clip.paste(3)    # return 3
clip.paste(4)    # return 4
