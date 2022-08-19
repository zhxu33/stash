#include <stdio.h>

int main() {

    printf("Enter the grade you want in the class: ");
    char gradeWant;
    scanf("%c", &gradeWant);
    
    printf("Enter the percent you need to get that grade: ");
    double percent;
    scanf("%lf", &percent);
    
    printf("Enter your current percent in the class: ");
    double currentGrade;
    scanf("%lf", &currentGrade);
    
    printf("Enter the weight of the final: ");
    double finalWeight;
    scanf("%lf", &finalWeight);
    
   double gradeNeed = currentGrade+((percent-currentGrade)/(finalWeight/100.0));
    printf("You need to get at least %.2lf%% on the final to get a %c in the class.", gradeNeed, gradeWant);
    
    
    
    
}