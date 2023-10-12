class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")
      
    def create_cycle(self, data):
        tail = self.head
        cycleNode = self.head
        while tail and tail.next:
           tail = tail.next
           if tail.data == data: # found cycle node
              cycleNode = tail
        if cycleNode and cycleNode.data == data:
          tail.next = cycleNode # set last node to cycle node

def detectCycle(linked_list):
  # Time Complexity: O(n)
  slow, fast = linked_list.head, linked_list.head
  while fast and fast.next:
    slow, fast = slow.next, fast.next.next
    if slow == fast: # found cycle
      return "True"
  return "False" # cycle not found

import collections
def find_next_recommendation(graph, current_friends):
  #time complexity: O(n^2)
  queue = collections.deque(current_friends) # BFS
  queue.append('You')
  visit = {f for f in queue} # track visited friends
  res, least = None, float('inf')
  while queue:
    for _ in range(len(queue)):
      friend = queue.popleft()
      for f in graph[friend]:
        if f not in visit:
            visit.add(f)
            queue.append(f)
            if graph[friend][f] < least:
               least = graph[friend][f]
               res = f
  return "Next recommended friend: "+ res if res else "Next recommended friend: None"