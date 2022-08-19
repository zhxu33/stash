#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 * how to use string?
 * Get the input in form of string
 * find the index of i
 * get the substring of input before i, convert to number
 * find the index of +
 * get the substring of input after +, convert to number
 * */

int main() {
    /**
    const char plus = '+';
    int found;
    int i;
    printf("Enter the first complex number in the form ai + b: ");
    string input1;
    scanf("%s",&input1);
    for (i = 0; i < strlen(input1); ++i) {
      if (strcmp(input1, plus) == 0) {
         found = i;
      }
    }
    **/
    int a;
    int b;
    printf("Enter the first complex number in the form ai + b: ");
    scanf("%d i + %d", &a, &b);
    int a2;
    int b2;
    printf("Enter the second complex number in the form ai + b: ");
    scanf("%d i + %d", &a2, &b2);
    
    int a3 = a2*b+b2*a;
    int b3 = b*b2-a*a2;
    printf("(%di + %d) * (%di + %d) = %di + %d", a,b,a2,b2,a3,b3);
    }
    
    
    
    