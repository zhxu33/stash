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
      if (m, index) not in visit:
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
    
    def p(self):
        if self.head:
          cur = self.head
          while cur:
              print(cur.key, cur.value, end = " -> ")
              cur = cur.next
          print(end = "\n")

    def paste(self, key: int) -> int:
      if key not in self.map:
         return -1
      if self.map[key].key == self.head.key:
         return self.map[key].value
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
      self.p()
      return self.map[key].value
        
    def copy(self, key: int, value: int) -> None:
      if key in self.map:
        self.map[key].key = key
        self.map[value].value = value
      else:
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
      self.p()

clip = clipboard(3)
clip.copy(3, 2)
clip.copy(5, 3)
print(clip.paste(5))
clip.copy(6,1)
clip.copy(4, 2)
clip.copy(5, 3)
print(clip.paste(6))
print(clip.paste(1))
print(clip.paste(4))