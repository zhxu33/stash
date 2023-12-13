def count_scores(num_words, num_queries, words, queries):
  if not queries:
    return ""
  words = words.split('_')
  queries = queries.split('_')
  res = []
  for w1 in queries:
    found = False
    for w2 in words:
      if len(w1) != len(w2):
        continue
      length = len(w1)
      mismatch = 0
      i = 0
      while mismatch <= 1 and i < length:
        if w1[i] != w2[i]:
          mismatch += 1
        i += 1
      if mismatch == 1:
        found = True 
        break
    r = 'YES' if found else "NO"
    res.append(r)
  return '_'.join(res)

def rename_people(num_students, student_names, fakonyms):
  if num_students >= 30:
    return ""
  student_names = student_names.split('_')
  fakonyms = fakonyms.split('_')
  prefix_counts = [[0] * num_students for _ in range(num_students)]
  for i in range(num_students):
    for j in range(num_students):
      index = 0
      n1 = student_names[i]
      n2 = fakonyms[j]
      length = min(len(n1), len(n2))
      while index < length and n1[index] == n2[index]:
        index += 1
      prefix_counts[i][j] = index
  dp = {}
  def dfs(index, mask):
    if index == num_students:
      return 0, []
    if (index, mask) in dp:
      return dp[(index, mask)]
    res_sum, res_matched = 0, []
    for i in range(num_students):
      if (mask >> i) & 1 == 0:
        m = mask | (1 << i)
        prefix_sum, matched = dfs(index + 1, m)
        prefix_sum += prefix_counts[index][i]
        if prefix_sum >= res_sum:
          res_sum = prefix_sum
          res_matched = [i] + matched
    dp[(index, mask)] = res_sum, res_matched
    return res_sum, res_matched
  res_sum, res_matched = dfs(0, 0)
  res = [str(res_sum)]
  for i,n in enumerate(res_matched):
    res.append(str(i+1))
    res.append(str(n+1))
  return '_'.join(res)

print(rename_people(10, "baa_a_ba_aabab_aa_baab_bb_abbbb_a_a", "a_ba_ba_baabbb_ba_a_aabb_baa_ab_b"))

# print(rename_people(10, "baa_a_ba_aabab_aa_baab_bb_abbbb_a_a", "a_ba_ba_baabbb_ba_a_aabb_baa_ab_b"))

# print(rename_people(30, "cb_ac_ac_bb_a_ccbbb_cb_bccaba_bca_a_ccbbbbcac_a_cba_b_aa_cca_bc_ac_acc_babc_caaa_bca_bacaaaaabcacb_c_caa_cb_bac_cc_baa_cc", "caacc_babbcbcbbc_acaa_bb_bbabaacb_cbaaac_cc_bcbccaac_ccc_ab_acaba_ccab_ab_a_c_bcabcab_ac_aaac_cb_bbcbbccb_ab_bccc_cabb_a_cac_abcbc_bb_cab_bc_cacccccc"))

# print(rename_people(51, "a_c_c_c_b_a_a_a_c_c_c_c_c_b_c_c_a_a_a_a_a_c_a_c_b_c_c_c_b_a_b_a_b_b_a_b_b_c_b_b_b_c_c_a_a_a_c_a_a_a_b", "c_c_a_a_a_a_a_c_a_c_b_c_c_c_c_b_b_b_c_c_c_c_c_c_b_b_a_b_a_b_b_a_b_b_a_a_a_c_a_a_a_b_a_c_c_c_b_a_a_a_c"))
