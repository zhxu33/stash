#include<iostream>
#include <string>
#include <vector>
using namespace std;

class BaseLength {
  public:
    virtual double length() = 0;
    double getMillimeters() {
      return Length;
    }
  protected:
    double Length;
};

class Inches: public BaseLength {
  public:
    Inches(double len) {
      Length = len;
    }
    virtual double length() {
      return Length/25.4;
    }
};

class Meters: public BaseLength {
  public:
    Meters(double len) {
      Length = len;
    }
    virtual double length() {
      return Length/1000;
    }
};

class Yards: public BaseLength {
  public:
    Yards(double len) {
      Length = len;
    }
    virtual double length() {
      return Length/25.4/36;
    }
};

class Perches: public BaseLength {
  public:
    Perches(double len) {
      Length = len;
    }
    virtual double length() {
      return Length/25.4/36/5.5;
    }
};

int main() {
  vector<BaseLength*> v;
  vector<BaseLength*>::iterator iter;
  double length;
  string unit;
  while (unit != "Quit") {
    cout << "Enter unit: (Inches, Meters, Yards, Perches, Quit)" << endl;
    cin >> unit;
    if (unit == "Quit") {
      break;
    }
    cout << "Enter length: " << endl;
    cin >> length;
    BaseLength *p;
    if (unit == "Inches") {
      p = new Inches(length);
      v.push_back(p);
    } else if (unit == "Meters") {
      p = new Meters(length);
      v.push_back(p);
    } else if (unit == "Yards") {
      p = new Yards(length);
      v.push_back(p);
    } else if (unit == "Perches") {
      p = new Perches(length);
      v.push_back(p);
    } else {
      cout << "Incorrect unit" << endl;
    }
  }
  for (iter = v.begin(); iter != v.end(); iter++) {
    cout << "Millimeters " << (*iter)->getMillimeters() << " Length: " <<(*iter)->length() << endl;
  }
}
