def runErrands(graph: list[list[int]]) -> int:
  res = len(graph) * len(graph)
  def dfs(i, amt, visit):
    nonlocal res
    if amt >= res or len(visit) == len(graph):
      res = amt
      return
    visit.add(i)
    for j, c in enumerate(graph[i]):
      if j == c:
        continue
      dfs(ord(c) - ord('a'), amt + 1, visit.copy())
  for i in range(len(graph)):
    dfs(i, -1, set())
  return res

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None
        self.prev = None

class clipboard:

    def __init__(self, capacity: int):
        self.map = {} # key : node
        self.capacity = capacity
        self.cur_capacity = 0
        self.head = None
        self.tail = None

    def paste(self, key: int) -> int:
      if key not in self.map:
         return -1
      # set as most recently accessed
      prev = self.map[key].prev
      next = self.map[key].next
      if prev:
         prev.next = next
      if next:
         next.prev = prev
      if not next and prev:
         self.tail = prev
      if self.head:
        self.map[key].next = self.head
        self.head.prev = self.map[key]
      self.head = self.map[key]
      return self.map[key].value
        
    def copy(self, key: int, value: int) -> None:
      self.map[key] = Node(key, value)
      # set as most recently accessed
      if self.head:
        self.map[key].next = self.head
        self.head.prev = self.map[key]
      self.head = self.map[key]
      self.cur_capacity += 1
      if not self.tail:
        self.tail = self.head
      if self.cur_capacity > self.capacity: # remove least recent accessed
         del self.map[self.tail.key]
         self.cur_capacity -= 1
         temp = self.tail.prev
         self.tail.prev.next = None
         self.tail = temp