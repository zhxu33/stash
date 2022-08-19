//Name: James Xu
//Student Id: 919456033

#ifndef FRACTION_H
#define FRACTION_H

#include<iostream>
using namespace std;

class Fraction
{
  private:
  int numerator;
  int denominator;

  public:
  Fraction(void);
  Fraction(int n1);
  Fraction(int n1, int n2);
  int getNum(void) const;
  int getDen(void) const ;
  friend const Fraction operator+ (const Fraction& x, const Fraction& y);
  friend const Fraction operator- (const Fraction& x, const Fraction& y);
  friend const Fraction operator* (const Fraction& x, const Fraction& y);
  friend const Fraction operator/ (const Fraction& x, const Fraction& y);
  friend ostream& operator << (ostream& os, const Fraction& v);
  friend const Fraction operator- (const Fraction& x);
  friend const Fraction operator+ (const Fraction& x, int y);
  friend const Fraction operator+ (int x, const Fraction& y);
  friend const Fraction operator- (const Fraction& x, int y);
  friend const Fraction operator- (int x, const Fraction& y);
  friend const Fraction operator* (const Fraction& x, int y);
  friend const Fraction operator* (int x, const Fraction& y);
  friend const Fraction operator/ (const Fraction& x, int y);
  friend const Fraction operator/ (int x, const Fraction& y);
};
#endif
