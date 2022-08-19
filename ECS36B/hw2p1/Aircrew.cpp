#include "Aircrew.h"
#include <string>
#include <iostream>
using namespace std;

Aircrew::Aircrew(string name_str): nm(name_str) {

}

Pilot::Pilot(string name_str): Aircrew(name_str)
{

}

Attendant::Attendant(string name_str): Aircrew(name_str)
{

}

TaggedAttendant::TaggedAttendant(string name_str): Aircrew(name_str)
{

}

const string Pilot::type(void) const {
  return "Pilot";
}

const string Attendant::type(void) const {
  return "Attendant";
}

const string TaggedAttendant::type(void) const {
  return "TaggedAttendant";
}

const int Pilot::maxFlights(void) const {
  return 5;
}

const int Attendant::maxFlights(void) const {
  return 8;
}

const int TaggedAttendant::maxFlights(void) const {
  return 8;
}

const double Aircrew::maxHours(void) const{
  return 60;
}

const string Aircrew::name(void) const {
  return nm;
}

void Aircrew::setFlights(int i) {
  flightsTaken = i;
}

void Aircrew::setHours(double h) {
  hoursWorked = h;
}

void Aircrew::print(void) const {
  cout << type() << ": " << name() <<  " has operated " << flightsTaken << " flights for a total of " << hoursWorked << " hours this week" << endl;
  cout << "Available flights: " << maxFlights()-flightsTaken << endl;
  cout << "Available hours: " << maxHours()-hoursWorked << endl;
}

void Aircrew::scheduleFlight(int f, double h) const {
  cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << endl;
  if (f<(maxFlights()-flightsTaken) && h<(maxHours()-hoursWorked)) {
    cout << "This crew member can be scheduled" << endl;
  } else {
    cout << "This crew member should be replaced" << endl;
  }
  cout << "Done scheduling " << name() << endl;
}

void TaggedAttendant::scheduleFlight(int f, double h) const
{
  cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight..." << endl;
  h = h/2.0;
  if (f<(maxFlights()-flightsTaken) && h<(maxHours()-hoursWorked)) {
    cout << "This crew member can be scheduled" << endl;
  } else {
    cout << "This crew member should be replaced" << endl;
  }
  cout << "Done scheduling " << name() << endl;
}

Aircrew* Aircrew::makeAircrew(char ch, string name_str) {
  Aircrew *p = NULL;
  if (ch == 'P') {
    p = new Pilot(name_str);
  } else if (ch == 'A') {
    p = new Attendant(name_str);
  } else if (ch == 'T') {
    p = new TaggedAttendant(name_str);
  } else {
    cout << "unknown aircrew type" << endl;
    exit(0);
  }
  return p;
}

Aircrew::~Aircrew(void) {

}
