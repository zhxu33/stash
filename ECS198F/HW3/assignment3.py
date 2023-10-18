def runErrands(graph):
  res = float('inf')
  visit = set()
  def dfs(i):
    if len(visit) == len(graph):
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