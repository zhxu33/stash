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

int getIntAtLeast(int min_val, const char* prompt){
    //from class drive, returns a value int input greater than min_val
  int num;
  do{
    num = getValidInt(prompt);
  }while(!(num >= min_val));

  return num;
}

double get_random_double_between(double min, double max){
    //from class drive, return a random double between [min, max]
  double percent = ((double)rand()) / ((double)RAND_MAX);
  double range = max - min;
  return min + range * percent;
}

int main() {
    int seed;
    int iterations;
    seed = getValidInt("Enter the seed for the random number generator: ");
    srand(seed);
    iterations = getIntAtLeast(1, "Enter the number of iterations to run: ");
    int i;
    double xrand;
    double yrand;
    double numPoints = 0;
    for (i=0; i<iterations; ++i) {
        xrand = get_random_double_between(-1, 1);
        yrand = get_random_double_between(-1, 1);
        if (sqrt(pow(xrand,2)+pow(yrand, 2)) <= 1) {
        numPoints++; 
        }
    }
    double pi = numPoints/iterations*4.0;
    printf("The value of pi is %.3lf.\n", pi);
}