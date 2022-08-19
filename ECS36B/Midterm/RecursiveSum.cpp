#include<iostream>
using namespace std;

int RecursiveSum(int n) {
  if (n==1) {
    return 1;
  } else {
    return n+RecursiveSum(n-1);
  }
}

int Multiply(int n) {
  if (n==0) {
    return 1;
  } else if (n==1) {
    return 2;
  } else {
    return Multiply(n-1)*Multiply(n-2);
  }
} //1, 2, 2, 4, 8, 32

int IterativeMultiply(int n) {
  int x,y;
  if (n==0) {
    y = 1;
  } else {
    x = 1;
    y = 2;
    for (int i = 1; i<n; i++) {
      int z = x*y;
      x = y;
      y = z;
    }
  }
  return y;
}

int main() {
  cout << IterativeMultiply(6);
}
