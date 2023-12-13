class TrieNode:
  def __init__(self):
    self.trie = {}
    self.indices = []
    self.indices2 = []

def count_scores(num_words, num_queries, words, queries):
  words = words.split('_')
  queries = queries.split('_')
  words_trie = TrieNode()
  for i, word in enumerate(words):
    cur = words_trie
    for c in word:
      if c not in cur.trie:
        cur.trie[c] = TrieNode()
      cur = cur.trie[c]
    cur.indices.append(i)
  def dfs(cur, word, i, mismatch):
    if i == len(word) and cur.indices and mismatch == 1:
      return True
    if mismatch > 1 or i == len(word):
      return False
    for c in cur.trie:
      if c == word[i] and dfs(cur.trie[c], word, i+1, mismatch):
        return True
      elif c != word[i] and dfs(cur.trie[c], word, i+1, mismatch+1):
        return True
    return False
  res = []
  for word in queries:
    if dfs(words_trie, word, 0, 0):
      res.append("YES")
    else:
      res.append("NO")
  return '_'.join(res)

print(count_scores(5, 4, "ab_cacab_cbabc_acc_cacab", "abc_aa_acbca_cb"))

def rename_people(num_students, student_names, fakonyms):
  student_names = student_names.split('_')
  fakonyms = fakonyms.split('_')
  res = []
  words_trie = TrieNode()
  for i, word in enumerate(student_names):
    cur = words_trie
    for c in word:
      if c not in cur.trie:
        cur.trie[c] = TrieNode()
      cur = cur.trie[c]
    cur.indices.append(i)
  for i, word in enumerate(fakonyms):
    cur = words_trie
    for c in word:
      if c not in cur.trie:
        cur.trie[c] = TrieNode()
      cur = cur.trie[c]
    cur.indices2.append(i)
  return '_'.join(res)

# print(count_scores(5, 4, "ab_cacab_cbabc_acc_cacab", "abc_aa_acbca_cb"))
# output: YES_YES_NO_YES

print(rename_people(10, "baa_a_ba_aabab_aa_baab_bb_abbbb_a_a", "a_ba_ba_baabbb_ba_a_aabb_baa_ab_b"))
# output: 17_1_8_2_6_3_5_4_7_5_1_6_4_7_10_8_9_9_3_10_2