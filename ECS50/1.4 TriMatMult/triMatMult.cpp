#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream file1,file2;
  file1.open(argv[1]);
  file2.open(argv[2]);
  int n;
  file1 >> n;
  file2 >> n;
  int size = 0;
  for(int i = 1; i <= n; ++i) {
    size += i;
  }
  int a[size];
  int b[size];
  int c[size];
  for (int i=0; i<size; i++) {
    file1 >> a[i];
    file2 >> b[i];
  }
  for (int i=1; i<=n; i++) {
    for (int j=i; j<=n; j++) {
      int index = (n*(i-1)-(i-2)*(i-1)/2)+(j-i);
      int sum = 0;
      for (int k = 1; k<=n; k++) {
        int tempi = i;
        int tempj = k;
        int tempi2 = k;
        int tempj2 = j;
        if (tempj >= tempi && tempj2 >= tempi2) {
          int ind = (n*(tempi-1)-(tempi-2)*(tempi-1)/2)+(tempj-tempi);
          int ind2 = (n*(tempi2-1)-(tempi2-2)*(tempi2-1)/2)+(tempj2-tempi2);
          sum = sum + a[ind]*b[ind2];
        }
      }
      c[index] = sum;
      }
  }
  for (int i=0; i<size; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
}
