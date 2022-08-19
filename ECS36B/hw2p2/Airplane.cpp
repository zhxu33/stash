#include "Airplane.h"
#include <string>
#include <iostream>
using namespace std;

Airplane::Airplane(int n): maxContainers(n), numContainers(0) {
}

int Airplane::maxLoad(void) const {
  return maxContainers;
}

int Airplane::currentLoad(void) const {
  return numContainers;
}

bool Airplane::addContainers(int n) {
  if ((numContainers+n)<=maxContainers) {
    numContainers = numContainers+n;
    return true;
  }
  return false;
}
