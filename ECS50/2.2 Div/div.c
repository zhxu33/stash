#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(int argc, char *argv[]) {
  char *ptr;
  unsigned int dividend = strtoul(argv[1], &ptr ,10);
  unsigned int divisor = strtoul(argv[2], &ptr ,10);
  unsigned int quotient = 0;
  unsigned int remainder = 0;
  bool found = false;
  for (int i = 31; i >= 0; i--) {
    if((dividend & (1<<i)) != 0 && !found) {
          found = true;
          i++;
    } else {
      remainder = remainder << 1;
      if((dividend & (1<<i)) != 0) {
        remainder |= 1<<0;
      } else {
        remainder = remainder & ~(1<<0);
      }
      if (remainder >= divisor) {
        remainder = remainder - divisor;
        quotient |= 1<<i;
      }
    }
  }
  printf("%u / %u = %u R %u", dividend, divisor, quotient, remainder);
}
