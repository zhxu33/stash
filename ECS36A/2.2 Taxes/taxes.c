#include <stdio.h>
#include <math.h>

double CalculateTaxBracket(double income, double percent, double min, double max) {
    // calculate taxed amount 
    double diff = max-min;
    double range = 0;
    if (income > min) {
        if (income - min > diff){
            if (min == 0) {
            range = diff; 
            } else {
            range = diff;    
            }
        } else {
            range = income-min;
        }
    }
    double taxAmount = percent*range;
    if (taxAmount > 0) {
    if (min == 0) {
    taxAmount= taxAmount;
    printf("You were taxed %.2lf%% on the first $%.2lf you made which is $%.2lf.\n", percent*100, range, taxAmount);
    } 
    else {
    printf("You were taxed %.2lf%% on the next $%.2lf you made which is $%.2lf.\n", percent*100, range, taxAmount);
    }
    }
    return taxAmount;
}

int main() {
    printf("Enter your income for the year: ");
    double income;
    scanf("%lf", &income);
    double totalTax = 0;
    totalTax += CalculateTaxBracket(income, 0.1, 0, 9875);
    totalTax += CalculateTaxBracket(income, 0.12, 9875, 40125);
    totalTax += CalculateTaxBracket(income, 0.22, 40125, 85525);
    totalTax += CalculateTaxBracket(income, 0.24, 85525, 163300);
    totalTax += CalculateTaxBracket(income, 0.32, 163300, 207350);
    totalTax += CalculateTaxBracket(income, 0.35, 207350 , 518400);
    totalTax += CalculateTaxBracket(income, 0.37, 518400, 999999999);
    double percentTaxed = totalTax/income*100;
    printf("In total you will pay $%.2lf in taxes on the $%.2lf you made this year.\n", totalTax, income);
    printf("This would amount to a FLAT tax of %.2lf%% on all of your income.\n", percentTaxed);
    
}