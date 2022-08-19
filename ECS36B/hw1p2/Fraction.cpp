//Name: James Xu
//Student Id: 919456033

#include "Fraction.h"
#include<iostream>
using namespace std;

Fraction::Fraction(void)
{
  numerator = 0;
  denominator = 1;
}

Fraction::Fraction(int n1)
{
  numerator = n1;
  denominator = 1;
}

Fraction::Fraction(int n1, int n2)
{
  numerator = n1;
  denominator = n2;
  int gcd, remainder;
  /* Euclid's algorithm */
  remainder = n1 % n2;
  while ( remainder != 0 )
  {
    n1 = n2;
    n2 = remainder;
    remainder = n1 % n2;
  }
  gcd = n2;
  numerator = numerator / gcd;
  denominator = denominator / gcd;
  if (denominator < 0) {
    denominator = -denominator;
    numerator = -numerator;
  }
}

int Fraction::getNum(void) const {
  return numerator;
}

int Fraction::getDen(void) const {
  return denominator;
}

ostream& operator << (ostream& os, const Fraction& f)
{
  if (f.denominator != 1) {
    os << f.numerator << "/" << f.denominator;
  } else {
    os << f.numerator;
  }
  return os;
}

const Fraction operator+ (const Fraction& x, const Fraction& y)
{
  int newDen = x.denominator*y.denominator;
  int newNum = x.numerator*y.denominator+y.numerator*x.denominator;
  Fraction f(newNum, newDen);
  return f;
}

const Fraction operator- (const Fraction& x, const Fraction& y)
{
  int newDen = x.denominator*y.denominator;
  int newNum = x.numerator*y.denominator-y.numerator*x.denominator;
  Fraction f(newNum, newDen);
  return f;
}

const Fraction operator* (const Fraction& x, const Fraction& y)
{
  int newDen = x.denominator*y.denominator;
  int newNum = x.numerator*y.numerator;
  Fraction f(newNum, newDen);
  return f;
}

const Fraction operator/ (const Fraction& x, const Fraction& y)
{
  if (y.numerator == 0) {
    throw invalid_argument("zero denominator");
  }
  int newDen = x.denominator*y.numerator;
  int newNum = x.numerator*y.denominator;
  Fraction f(newNum, newDen);
  return f;
}

const Fraction operator- (const Fraction& x)
{
  Fraction f(-x.numerator, x.denominator);
  return f;
}

const Fraction operator+ (const Fraction& x, int y)
{
  Fraction f(x.numerator+y*x.denominator, x.denominator);
  return f;
}

const Fraction operator+ (int x, const Fraction& y)
{
  Fraction f(y.numerator+x*y.denominator, y.denominator);
  return f;
}

const Fraction operator- (const Fraction& x, int y)
{
  Fraction f(x.numerator-y*x.denominator, x.denominator);
  return f;
}

const Fraction operator- (int x, const Fraction& y)
{
  Fraction f(x*y.denominator-y.numerator, y.denominator);
  return f;
}

const Fraction operator* (const Fraction& x, int y)
{
  Fraction f(x.numerator*y, x.denominator);
  return f;
}

const Fraction operator* (int x, const Fraction& y)
{
  Fraction f(y.numerator*x, y.denominator);
  return f;
}

const Fraction operator/ (const Fraction& x, int y)
{
  Fraction f(x.numerator, x.denominator*y);
  return f;
}

const Fraction operator/ (int x, const Fraction& y)
{
  Fraction f(x*y.denominator, y.numerator);
  return f;
}
