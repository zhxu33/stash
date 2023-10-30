import collections
def runErrands(graph: list[list[int]]) -> int:
  queue = collections.deque([])
  visit = set()
  for i in range(len(graph)):
      visit.add((i, 1 << i))
      queue.append((i, 0, 1 << i))
  while queue:
      i, amt, mask = queue.popleft()
      if mask == (1<<len(graph))-1:
          return amt
      for c in graph[i]:
          index = ord(c) - ord('a')
          m = mask | (1 << index)
          if (index, m) not in visit:
              visit.add((index, m))
              queue.append((index, amt+1, m))
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
      if self.map[key].key == self.head.key:
         return self.map[key].value
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
      self.cur_capacity += 1
      if self.tail and self.cur_capacity > self.capacity:
        del self.map[self.tail.key]
        self.map[key] = self.tail
        self.tail.key = key
        self.tail.value = value
      else: 
        self.map[key] = Node(key, value)
        if self.tail:
          self.tail.next = self.map[key]
          self.map[key].prev = self.tail
          self.tail = self.map[key]
        else:
           self.head = self.map[key]
           self.tail = self.map[key]