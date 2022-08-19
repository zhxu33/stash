#include "WordleGame.h"
#include <iostream>
#include <string>
#include <fstream>
#include <set>
using namespace std;

WordleGame::WordleGame(const string& filename) {
  ifstream myfile;
  myfile.open(filename);
  string word;
  while (myfile) {
    getline(myfile, word);
    dictionary.insert(word);
  }
}

string WordleGame::score(const std::string& input) {
  int len = input.length();
  string output = "-----";
  string tempOutput = "-----";
  set<string>::iterator iter = dictionary.begin();
  bool foundDic = false;
  while (iter != dictionary.end()) {
    if (*iter == input) {
      foundDic = true;
    }
    iter++;
  }
  if (foundDic == false) {
    return "not in dictionary";
  }
  for (int i=0; i<len; i++) {
    if (input[i] == key[i]) {
      output[i] = '*';
    } else {
      bool found = false;
      for (int j=0; j<len; j++) {
        if (input[i] == key[j]) {
          output[i] = '?';
          found = true;
        }
      }
      if (found == false) {
        output[i] = '-';
      }
    }
    tempOutput[i] = output[i];
  }
  if (output == "*****") {
    done = true;
  }
  for (int i=0; i<len; i++) {
    if (output[i] == '?') {
      bool found = false;
      for (int j=0; j<len; j++) {
        if (input[i] == key[j] && tempOutput[j] != '*' && tempOutput[j] != '+' && found == false) {
          output[i] = '+';
          tempOutput[j] = '+';
          found = true;
        }
      }
      if (found == false) {
        output[i] = '-';
      }
    }
  }
  /*
    for (int i=0; i<len; i++) {
      if (tempOutput[i] == '+') {
        output[i] = '+';
      } else if (tempOutput[i] == '?') {
        output[i] = '-';
      }
    } */
  return output;
} //./game 16015 <test16015.in
//./game 18076 <test18076.in
//./game 29023 <test29023.in

void WordleGame::select_key(int index) {
  set<string>::iterator iter = dictionary.begin();
  int val = index%(dictionary.size()-1);
  advance(iter, val);
  key = *iter;
}

bool WordleGame::over(void) const {
  return done;
}
