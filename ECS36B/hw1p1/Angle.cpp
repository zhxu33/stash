//Name: James Xu
//Student Id: 919456033

#include "Angle.h"
#include<iostream>
using namespace std;

Angle::Angle(void)
{
  theta = 30;
}

void Angle::print(void)
{
  cout << "angle: " << theta << endl;
}

int Angle::get(void)
{
  return theta;
}

void Angle::set(int t)
{
  if (t >= -120 && t <= 60)
  {
    theta = t;
  } else if (t < -120)
  {
    theta = -120;
  } else if (t > 60) {
    theta = 60;
  }
}

void Angle::change(int dt)
{
  set(theta+dt);
}
