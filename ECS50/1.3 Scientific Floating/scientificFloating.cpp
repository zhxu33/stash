#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
  cout << "Please enter a float: ";
  float f;
  cin >> f;
  unsigned int float_int = *((unsigned int*)&f);
  int sign = float_int >> 31;
  int exponent = float_int >> 23 & 0b11111111;
  exponent = exponent - 127;
  int mantissa = (float_int) & 0b11111111111111111111111;
  string print;
  bool found = false;
  for (int i = 0; i < 23; i++) {
    if((mantissa & (1<<i)) != 0) {
      found = true;
      print = "1"+print;
    } else{
      if (found) {
        print = "0"+print;
      }
    }
  }
  if (sign == 0) {
    print = "1."+print+"E"+to_string(exponent);
  } else {
    print = "-1."+print+"E"+to_string(exponent);
  }
  if (float_int == 0) {
    print = "0E0";
  }
  cout << print << endl;;
}
