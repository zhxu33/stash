#include<iostream>
using namespace std;

int binarySearch(int a[], int x) {
  int i = 0;
  int j = 8;
  while (i < j) {
    int m = (i+j)/2;
    if (x > a[m]) {
      i = m +1;
    } else {
      j = m;
    }
    cout << i << " " << j << endl;
  }
  int location;
  if (x == a[i]) {
    location = i;
  } else {
    location = -1;
  }
  return location;
}

int findMaxEvenIndex(int a[]) {
  int m = 0;
  for (int i=0; i<6; i++) {
    if (a[m] < a[i] && a[i]%2 == 0) {
      m = i;
    }
  }
  if (m == 0 and a[m]%2 != 0) {
    m = -1;
  }
  return m;
}

int findLastLeastIndex(int a[]) {
  int l = 0;
  for (int i=0; i<6; i++) {
  	if (a[l] >= a[i]) {
  		l = i;
  	}
  }
  return l;

}

int main () {
  int a[9] = {1,2,3,4,5,6,7,8,9};
  cout << binarySearch(a, 5) << endl;
}
