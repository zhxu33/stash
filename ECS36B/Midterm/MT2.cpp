#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

int main()
{
  int x = 4;
  const int * p = &x;
  (*p)++;
}
