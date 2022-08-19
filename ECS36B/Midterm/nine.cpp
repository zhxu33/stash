#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> v;
  vector<int>::reverse_iterator iter;
  int i;
  while (cin >> i) {
    v.push_back(i);
  }
  for (iter = v.rbegin(); iter != v.rend(); iter++) {
    cout << *iter << endl;
  }
}
