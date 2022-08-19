#include<iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char *argv[]) {
  string word = "";
  for (int i=1; i<argc; i++) {
    int num = atoi(argv[i]);
    int amt;
    int cap = num >> 26;
    for (amt = 25; amt >= 0; amt--) {
      if((num & (1<<amt)) != 0) {
        break;
      }
    }
    char c;
    if (cap == 1) {
      c = 'A';
    } else {
      c = 'a';
    }
    c = c+amt;
    word = word+c;
  }
  cout << "You entered the word: " << word;
}
