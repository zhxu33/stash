#include <stdio.h>

int main() {

    printf("Please enter the amount of money you wish to withdraw: ");
    int withdrawAmount;
    scanf("%d", &withdrawAmount);
    
    printf("You received %d hundred(s)\n", withdrawAmount/100); 
    
    withdrawAmount = withdrawAmount%100;
    
    printf("You received %d fifty(s)\n",  withdrawAmount/50);
    
    withdrawAmount = withdrawAmount%50;
    
    printf("You received %d twenty(s)\n",  withdrawAmount/20);
    
    withdrawAmount = withdrawAmount%20;
    
    printf("You received %d ten(s)\n",  withdrawAmount/10);
    
    withdrawAmount = withdrawAmount%10;

    printf("You received %d five(s)\n",  withdrawAmount/5);
    
    withdrawAmount = withdrawAmount%5;
    
    printf("You received %d one(s)\n",  withdrawAmount);
    

}