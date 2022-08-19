#include<iostream>
using namespace std;

class Integer {
  private:
    int num;
  public:
    Integer(void) {num = 0; cout << "Object created" << std::endl;}
    Integer(const Integer& i) {}
    Integer(int i) {num = i;}
    int get(void) {return num;}
    void set(int val) {num=val;}
    int compare(const Integer& i) {
      if (num>i.num) {
        return 1;
      } else if (i.num>num) {
        return -1;
      } else {
        return 0;
      }
    }
    Integer operator+(const Integer& i) {
      return Integer(num+i.num);
    }
    Integer operator-(const Integer& i) {
      return Integer(num-i.num);
    }
    Integer operator*(const Integer& i) {
      return Integer(num*i.num);
    }
    friend ostream& operator<<(ostream& os, const Integer& i);
};

ostream& operator<<(ostream& os, const Integer& i) {
  os << i.num;
  return os;
};

int main() {
    Integer a1, a2, a3, a4, a5;
    a1.set(4);
    a2.set(5);
    a3.set(6);
    a4.set(7);
    a5.set(8);
    cout <<(a1*a2*a2*a2+a3*a2*a2+a4*a2+a5)<< endl;
}
