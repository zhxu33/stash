#include<iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
//./wfreq <TheOdyssey.txt
int main(int argc, char *argv[])
{
  string word;
  map<string, int> wordCount;
  while (cin >> word) {
    size_t found = word.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    if (found == string::npos) { wordCount[word]++; }
  }
  vector<pair<string, int>> wordCountVector;
  for (auto& it : wordCount) {
      wordCountVector.push_back(it);
  }
  sort(wordCountVector.begin(), wordCountVector.end(), [](pair<string, int>& x, pair<string, int>&y) { if (x.second != y.second) { return x.second > y.second;} return x.first < y.first; });
  for (auto &it: wordCountVector) {
        std::cout << it.first << " " << it.second << endl;
  }
}
