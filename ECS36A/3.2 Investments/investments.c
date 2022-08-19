#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    //from class drive, check if input format is valid
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character);
		if(!isspace(character)){ 
			formatIsGood = false;
		}
	}while(character != '\n'); 
  return formatIsGood;
}

double getValidInt(const char* prompt) {
    //from class drive, returns a valid int input
    int num;
    const int numArgsNeeded = 1;
    int numArgsRead;
    do{
        printf("%s", prompt);
        numArgsRead = scanf(" %d", &num);
    }while(!isValidFormat(numArgsRead, numArgsNeeded));
    
    return num;
}

double getValidDouble(const char* prompt){
    //from class drive, returns a valid double input
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num); //waffles\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

double getDoubleAtLeast(double min_val, const char* prompt){
    //from class drive, returns a value double input greater than min_val
  double num;
  do{
    num = getValidDouble(prompt);
  }while(!(num >= min_val));

  return num;
}

int getIntAtLeast(int min_val, const char* prompt){
    //from class drive, returns a value int input greater than min_val
  int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= min_val));

  return num;
}

int main() {
    double investmentMoney = getDoubleAtLeast(0, "Enter how much money you will be putting towards loans/retirement each month: ");
    double loanOwed = getDoubleAtLeast(0, "Enter how much you owe in loans: ");
    double annualInterest = getDoubleAtLeast(0, "Enter the annual interest rate of the loans: ");
    double loanPayment = getDoubleAtLeast(0, "Enter your minimum monthly loan payment: ");
    if (investmentMoney < loanPayment) {
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        exit(0);
    }
    int age = getIntAtLeast(0, "Enter your current age: ");
    int retireAge = getIntAtLeast(age, "Enter the age you plan to retire at: ");
    double rateReturn = getDoubleAtLeast(0, "Enter the annual rate of return you predict for your investments: ");
    double moneyMadeMaxPay = 0;
    double moneyMadeMinPay = 0;
    double tempLoans = loanOwed;
    for (int i = age; i < retireAge; ++i) {
        for (int k = 0; k < 12; ++k) {
            tempLoans = tempLoans*(1+annualInterest/12);
            moneyMadeMaxPay = moneyMadeMaxPay*(1+rateReturn/12);
            if (tempLoans == 0) {
                moneyMadeMaxPay = moneyMadeMaxPay + investmentMoney;
            } else if (tempLoans-investmentMoney < 0) {
                moneyMadeMaxPay = moneyMadeMaxPay + (investmentMoney - tempLoans);
                tempLoans = 0;
            } else{
               tempLoans = tempLoans-investmentMoney;
            }
        }
    }
    if (tempLoans > 0) {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", tempLoans);
    }
    tempLoans = loanOwed;
    for (int i = age; i < retireAge; ++i) {
        for (int k = 0; k < 12; ++k) {
            tempLoans = tempLoans*(1+annualInterest/12);
            moneyMadeMinPay = moneyMadeMinPay*(1+rateReturn/12);
            if (tempLoans == 0) {
                moneyMadeMinPay = moneyMadeMinPay + investmentMoney;
            } else if (tempLoans-loanPayment < 0) {
                moneyMadeMinPay = moneyMadeMinPay + (investmentMoney - tempLoans);
                tempLoans = 0;
            } else{
               tempLoans = tempLoans-loanPayment;
               moneyMadeMinPay = moneyMadeMinPay + (investmentMoney-loanPayment);
            }
        }
    }
    if (tempLoans > 0) {
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n", tempLoans);
    }
    if (moneyMadeMaxPay > moneyMadeMinPay) {
        printf("You should apply all $%.2lf towards your loan before making any investments.\n", investmentMoney);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n", moneyMadeMaxPay, moneyMadeMinPay);
    } else {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n", moneyMadeMinPay, moneyMadeMaxPay);
    }
}