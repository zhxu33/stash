#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point {
  public:
    Point(void) {
      x = 0;
      y = 0;
    }
    Point(int x, int y) {
      this->x = x;
      this->y = y;
    }
    void Print() {
      cout << "("<<x <<"," << y<< ")" << endl;
    }
    friend Point operator+ (const Point& a, const Point& b) {
      Point c(a.x+b.x, a.y+b.y);
      return c;
    }
  private:
    int x;
    int y;
};

void partition(vector<int> &v) {
  int temp, left = 0, right = v.size()-1;
  while (left < right) {
    if(v[left] % 2 == 0) {
      left++;
    } else if(v[right] % 2 == 1) {
      right--;
    } else {
      temp = v[left];
      v[left] = v[right];
      v[right] = temp;
      left++;
      right--;
    }
  }
}

int main() {
  /*
  Point a(1,1);
  Point b(2,2);
  Point c = a+b;
  c.Print();
  vector<int> v= {1,2,3,4,5};
  v.insert(v.begin()+3, 6);
  vector<int>::iterator iter;
  for (iter = v.begin(); iter != v.end(); iter++) {
    cout << *iter << endl;
  }
  */
  vector<int> v= {3,2,9,4,5,7,6};
  vector<int>::iterator iter;
  partition(v.begin(), v.end(), [](int& x) { return x%2 == 0; });
  for (iter = v.begin(); iter != v.end(); iter++) {
    cout << *iter << endl;
  }

}
//g++ test.cpp
