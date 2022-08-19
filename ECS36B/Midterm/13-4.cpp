#include<iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
  public:
    Person(void) {
      age = 18;
      name = "John";
      gender = "Male";
    }
    Person(int givenAge, string givenName, string givenGender) {
      age = givenAge;
      name = givenName;
      gender = givenGender;
    }
    virtual void display() {
      cout << "Name :" << name << "is a person." << endl;
    }
  protected:
    int age;
    string name;
    string gender;
};

class Employee: public Person {
  public:
    virtual void display() {
      cout << "Name: " << name << " is an employee." << endl;
    }
  protected:
    int number;
};

class Executive: public Employee {
  public:
    virtual void display() {
      cout << "Name: " << name << " is an executive." << endl;
    }
};

int main() {
  vector<Employee> v(5);
  vector<Executive> v2(5);
  vector<int>::iterator iter;
  for ( int i = 0; i < v.size(); i++ )
  {
    Person& p = v[i];
    p.display();
  }
  for ( int i = 0; i < v2.size(); i++ )
  {
    Person& p = v2[i];
    p.display();
  }
}
