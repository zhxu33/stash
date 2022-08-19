#include "Sequence.h"
#include<iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

Sequence::Sequence(void) {
  desc = "";
  seq = "";
}

Sequence::Sequence(const string& desc_str, const string& seq_str) {
  desc = desc_str;
  seq = seq_str;
}

ostream& operator << (ostream& os, const Sequence& s ) {
  cout << s.desc << s.seq;
  return os;
}

istream& operator >> ( std::istream& is, Sequence& s ) {
  string line;
  getline(cin, s.desc);
  s.seq = "\n";
  while (getline(cin, line)) {
    s.seq = s.seq + line + '\n';
    if (line.empty()) {
      break;
    }
  }
  s.check();
  return is;
}
//cat Alpha_B.1.1.7.txt Beta_B.1.351.txt | ./mum
//cat Alpha_B.1.1.7.txt Alpha_B.1.1.7.txt | ./mum
// cat rand1.txt rand2.txt | ./mum
// cat rand2.txt rand1.txt | ./mum
// tar cvf hw3.cpp Sequence.cpp

string Sequence::findNextMutation(const Sequence& s, const int& pos) const {
  int found = -1;
  string sampleSeq = seq;
  remove(sampleSeq.begin()+1, sampleSeq.end(), '\n');
  string sampleSeq2 = s.seq ;
  remove(sampleSeq2.begin()+1, sampleSeq2.end(), '\n');
  int size = sampleSeq.length();
  for (int i=pos; i<size; i++) {
    if (sampleSeq[i] != sampleSeq2[i]) {
      found = i;
      break;
    }
  }
  string mutation;
  if (found != -1) {
    mutation = sampleSeq[found]+to_string(found)+sampleSeq2[found];
  } else {
    mutation = "no mutation found";
  }
  return mutation;
}
//cout << found << " " << seq[i] << "vs" << s.seq[i] << endl;
//cat Alpha_B.1.1.7.txt Beta_B.1.351.txt | ./nextMutation 100
//cat Alpha_B.1.1.7.txt Alpha_B.1.1.7.txt | ./nextMutation 1

Sequence findMUM(const Sequence& s1, const Sequence& s2) {
  //cout << s2.seq.substr(1116);
  string sampleSeq = s1.seq;
  remove(sampleSeq.begin()+1, sampleSeq.end(), '\n');
  string sampleSeq2 = s2.seq;
  remove(sampleSeq2.begin()+1, sampleSeq2.end(), '\n');
  int size = sampleSeq.length();
  int starting1 = -1;
  int starting2 = -1;
  int minsize = 20;
  for (int i=1; i<size-20; i++) {
      string test = sampleSeq.substr(i, 20);
      size_t found = sampleSeq2.find(test);
      if (found != string::npos) {
        bool ended = false;
        for (int j=0; i+j+20<size; j++) {
          if (ended == false) {
            string test2 = sampleSeq.substr(i, 20+j);
            string test3 = sampleSeq.substr(i, 21+j);
            size_t found2 = sampleSeq2.find(test2);
            size_t found3 = sampleSeq2.find(test3);
            if ((found2 != string::npos && found3 == string::npos) || (i+j+20 == size-1)) {
              ended = true;
              if (20+j > minsize) {
                if (i+j+20 == size-1) {
                  minsize = 1000000;
                } else {
                  minsize = 20+j;
                }
                starting1 = i;
                starting2 = found;
              }
            }
          }
        }
      }
    }
  if (starting1 > -1 && starting2 > -1) {
    string mum = sampleSeq.substr(starting1, minsize);
    int spaceCounter = starting1/70;
    if (minsize == 1000000) {
      mum =  s2.seq.substr(starting2+spaceCounter);
    }
    mum.erase(remove(mum.begin(), mum.end(), '\n'), mum.end());
    int mumSize = mum.length();
    string finalmum = "";
    int lastfound;
    for (int i=1; i <mumSize; i++) {
      if (i % 70 == 0) {
        lastfound = i;
        finalmum = finalmum+mum.substr(i-70, 70)+'\n';
      } else if (i == mumSize - 1) {
        finalmum = finalmum+mum.substr(lastfound);
      }
    }
    finalmum = finalmum +"\n\n";
    Sequence* s = new Sequence(">MUM pos1="+to_string(starting1)+" pos2="+to_string(starting2)+"\n", finalmum);
    return *s;
  } else {
    Sequence *s = new Sequence(">No MUM found", "\n\n");
    return *s;
  }
}
//cat Alpha_B.1.1.7.txt Beta_B.1.351.txt | ./mum
//cat Omicron_BA.1.txt Alpha_B.1.1.7.txt | ./mum
//cat Alpha_B.1.1.7.txt Alpha_B.1.1.7.txt | ./mum
//cat Delta_B.1.617.2.txt Alpha_B.1.1.7.txt | ./mum

void Sequence::check(void) const {
  if (seq[seq.length()-2] != '\n' && seq[seq.length()-1] != '\n') {
    //cout << seq[seq.length()-2] << seq[seq.length()-1] << endl;
    throw invalid_argument("No newline at end of file");
  }
  size_t found = seq.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
  if (found != string::npos) {
    throw invalid_argument("invalid character in sequence");
  }
}
//cat bad_sequence.txt bad_sequence.txt | ./mum
//cat Alpha_B.1.1.7.txt Alpha_B.1.1.7.txt | ./mum
//cat Omicron_BA.1.txt bad_sequence.txt | ./mum
