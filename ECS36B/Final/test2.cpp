#include<iostream>
#include<set>
using namespace std;

int main() {
  set<string> s;
  string x;
  while (cin) {
    cin >> x;
    s.insert(x);
  }
  cout << endl;
  set<string>::iterator iter;
  for (iter = s.begin(); iter != s.end(); iter++) {
    cout << *iter << endl;
  }
}
//g++ test2.cpp
