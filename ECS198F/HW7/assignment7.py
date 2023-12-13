import math
def predict_tree_height(target_tree_coordinates, all_trees, all_heights, k):
  if k > len(all_trees):
    return -1
  x1, y1 = target_tree_coordinates
  arr = []
  for i, n in enumerate(all_trees):
    x2, y2 = n
    d = math.sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)))
    arr.append((d, i))
  arr.sort()
  total = 0
  i = 0
  found = 0
  while found < k:
    index = arr[i][1]
    i += 1
    found += 1
    total += all_heights[index]
  return total/k
  
# print(predict_tree_height([0, 0], [(0, 0), (1, 1), (2, 2), (3, 3)], [100.27, 103.56, 97.22, 107.39], 2))

def k_wrapped_books(unwrap, k):
  length = len(unwrap)
  books = [[float('inf'), float('inf'), 0] for _ in range(length)]
  for r,n in enumerate(unwrap):
    i = n-1
    books[i][2] = 1
    for j in range(length):
      if (j < i and (i-j) < books[j][1]):
        books[j][1] = i-j
        if books[j][1]-1 == k and books[j][2] == 1:
          return r + 1
      elif (j > i and (j-i) < books[j][0]):
        books[j][0] = j-i
        if books[j][0]-1 == k and books[j][2] == 1:
          return r + 1
  return -1

# print(k_wrapped_books([1,3,2], 1))
# 2
# print(k_wrapped_books([4, 1, 2, 3], 2))
# 2
# print(k_wrapped_books([1,2,3], -1))
# -1

import heapq
def rearrange_bracelet(bracelet, k):
  count = {}
  for c in bracelet:
    count[c] = count.get(c, 0) + 1
  h = [(-val, key) for key, val in count.items()]
  heapq.heapify(h)
  res = ""
  while h:
    stored = []
    if len(h) < k and h[0][0] < -1:
      return ""
    for _ in range(min(k, len(h))):
      count, c = heapq.heappop(h)
      res += c
      if count + 1 < 0:
        stored.append((count+1, c))
    for count, c in stored:
      heapq.heappush(h, (count, c))
  return res

# print(rearrange_bracelet("ccbbaa", 3))
# "cbacba"
# print(rearrange_bracelet("eeefg", 3))
# ""
# print(rearrange_bracelet("jjjkffgg", 2))
# "jjjkffgg"

def second_longest_prefix(text):
  r = len(text)//2
  n = len(text)
  res = []
  while r < n:
    if text[:n-r] == text[r:]:
      res.append(text[r:])
    r += 1
  return res[1] if len(res) > 1 else ""

# print(second_longest_prefix("ssiencss"))
# "s"
# print(second_longest_prefix("ababab"))
# "ab"
# print(second_longest_prefix("science"))
# ""