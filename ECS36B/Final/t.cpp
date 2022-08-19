#include<iostream>
#include<vector>
#include<map>
using namespace std;

void increment_time(int &hours, int &minutes) {
  minutes = minutes + 1;
  hours = hours + minutes/60;
  minutes = minutes%60;
}

int main() {
  int hours = 0;
  int minutes = 0;
  increment_time(hours, minutes);
  cout << hours << endl;
  cout << minutes << endl;
}
