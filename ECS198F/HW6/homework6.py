def num_cookies(cookie_sequence, num_queries, lr_queries):
  def constructTree(l, h, i):
    if h-l <= 1:
      tree[i][1] += cookie_sequence[l] == "("
      tree[i][2] += cookie_sequence[l] == ")"
      return
    m = (l+h)//2
    constructTree(l, m, 2*i+1) 
    constructTree(m, h, 2*i+2)
    match = min(tree[2*i+1][1], tree[2*i+2][2])
    tree[i] = [tree[2*i+1][0]+tree[2*i+2][0]+match*2, tree[2*i+1][1]+tree[2*i+2][1]-match, tree[2*i+1][2]+tree[2*i+2][2]-match]

  def query(ql, qh, l, h, i):
    if ql <= l and qh >= h:
      return tree[i]
    if ql >= h or qh <= l:
      return [0, 0, 0]
    m = (l+h)//2
    left, right = query(ql, qh, l, m, 2*i+1), query(ql, qh, m, h, 2*i+2)
    match = min(left[1], right[2])
    return [left[0]+right[0]+match*2, left[1]+right[1]-match, left[2]+right[2]-match]
  
  res, n = [], len(cookie_sequence)
  tree = [[0, 0, 0] for _ in range(4*n)]  # (matched, left, right)
  constructTree(0, n, 0)
  lr_queries = lr_queries.split('_')
  for i in range(0, num_queries * 2, 2):
    res.append(str(query(int(lr_queries[i])-1, int(lr_queries[i+1]), 0, n, 0)[0]))
  return '_'.join(res)

print(num_cookies("))(()))))())())))))())((()()))))()))))))))))))", 9, "26_42_21_22_6_22_7_26_43_46_25_27_32_39_22_40_2_45"))
#4_0_6_8_0_2_2_10_20

print(num_cookies("(((())((((()()((((((()((()(((((((((((()((", 6, "20_37_28_32_12_18_7_25_21_33_4_5"))
#4_0_2_6_4_2