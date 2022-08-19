#include<iostream>
#include <string>
using namespace std;

class Animal {
  public:
    void who() {
      cout << "Name: " << name << " " << "Weight: " << weight << endl;
    }
    void setName(string nm) {
      name = nm;
    }
    void setWeight(int wt) {
      weight = wt;
    }
  private:
    string name;
    int weight;
};

class Lion: public Animal {
  public:
};

class Aardvark: public Animal {
  public:
};

int main() {
  Lion l;
  l.setName("Leo");
  l.setWeight(400);
  Aardvark a;
  a.setName("Algernoon");
  a.setWeight(50);
  a.who();
  l.who();
}
