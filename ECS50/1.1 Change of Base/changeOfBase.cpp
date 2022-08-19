#include<iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
  cout << "Please enter the number's base: ";
  int base;
  cin >> base;
  cout << "Please enter the number: ";
  string number;
  cin >> number;
  cout << "Please enter the new base: ";
  int newbase;
  cin >> newbase;
  int newnumber = 0;
  int digits = number.size();
  string val = "";
  for (int i=digits; i>0; i--) {
    int dig = number[digits-i] - '0';
    if (dig > 10) {
      dig = 10 - ('A' - number[digits-i]);
    }
    newnumber = newnumber+pow(base,i-1)*dig;
  }
  int quotient;
  int remainder;
  while (newnumber > 0) {
    quotient = newnumber / newbase;
    remainder = newnumber - newbase*quotient;
    newnumber = quotient;
    if (remainder>=10) {
      char c = 'A'+remainder-10;
      val = c+val;
    }
    else {
      val = to_string(remainder)+val;
    }
  }
  cout << number << " base " << base << " is " << val << " base " << newbase;
}
