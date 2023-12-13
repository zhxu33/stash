def num_cookies(cookie_sequence, num_queries, lr_queries):
  lr_queries = lr_queries.split('_')
  queries = []
  for i in range(num_queries):
    queries.append([int(lr_queries[i*2]), int(lr_queries[i*2+1])])
  res = []
  left_par = 0
  for l, r in queries:
    characters = 0
    for i in range(l-1, r):
      if cookie_sequence[i] == '(':
        left_par += 1
      elif cookie_sequence[i] == ')' and left_par:
        left_par -= 1
        characters += 2
    left_par = 0
    res.append(str(characters))
  return '_'.join(res)

print(num_cookies("))(()))))())())))))())((()()))))()))))))))))))", 9, "26_42_21_22_6_22_7_26_43_46_25_27_32_39_22_40_2_45"))
#4_0_6_8_0_2_2_10_20

print(num_cookies("(((())((((()()((((((()((()(((((((((((()((", 6, "20_37_28_32_12_18_7_25_21_33_4_5"))