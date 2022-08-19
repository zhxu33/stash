#include <stdio.h>
#include <math.h>

double quadraticFormula(double a, double b, double c, char sign) {
    // calculate solutions using quadratic formula
    if (sign == '+') {
    return (-b+sqrt(pow(b,2)-4.0*a*c))/(2.0*a);
    }
    else if (sign == '-') {
     return (-b-sqrt(pow(b,2)-4.0*a*c))/(2.0*a);
    }
    return 0;
}

int main() {
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    double a;
    double b;
    double c;
    printf("Please enter a: ");
    scanf("%lf", &a);
    printf("Please enter b: ");
    scanf("%lf", &b);
    printf("Please enter c: ");
    scanf("%lf", &c);
    const char plus = '+';
    const char minus = '-';
    double sol1 = quadraticFormula(a,b,c, plus);
    double sol2 = quadraticFormula(a,b,c, minus);
    int numSol = 0;
    if ((a*pow(sol1,2)+b*sol1+c) == 0) {
        numSol++;
    }
    if (sol1 != sol2 && (a*pow(sol1,2)+b*sol1+c) == 0) {
        numSol++;
    }
    if (numSol == 0) {
        printf("There are no real solutions");
    }
    else if (numSol == 1) {
        printf("There is one real solution: %.2lf\n", sol1);
    }
    else if (numSol == 2) {
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2lf\n", sol1);
        printf("Solution 2: %.2lf\n", sol2);
    }
}