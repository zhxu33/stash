#include <stdio.h>
#include <math.h>

int main() {
    printf("Please enter the amount of money you borrowed: $");
    double borrowed;
    scanf("%lf", &borrowed);
    printf("Please enter the annual interest rate: ");
    double rate;
    scanf("%lf", &rate);
    printf("Please enter the number of payments to be made: ");
    double payments;
    scanf("%lf", &payments);
    double monthRate = rate/12;
    double monthPay = (monthRate*borrowed)/(1-pow((1+monthRate), -payments));
    double loanPay= monthPay*payments;
    double loanCost = loanPay - borrowed;
    printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %.0lf months will have monthly payments of $%.2lf.\n",borrowed, rate, payments, monthPay);
    printf("In total you will pay $%.2lf, making the cost of your loan $%.2lf.\n", loanPay, loanCost);
}