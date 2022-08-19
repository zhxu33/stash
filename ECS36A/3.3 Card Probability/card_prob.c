#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
    //from class drive, returns true/false if input is valid
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


int main() {
    int totalCards = getValidInt("Enter how many total cards there are in the deck: ");
    int copies = getValidInt("Enter how many copies of the card that you are looking for are in the deck: ");
    int handSize = getValidInt("Enter your initial hand size: ");
    int mulliganing = getValidInt("Enter how many cards you are mulliganing: ");
    int turnDraw = getValidInt("Enter what turn you want to draw the card by: ");
    int numInDeck = totalCards; 
    int numAside = 0;
    double numerator = 1;
    double denominator = 1;
    int i;
    for (i=0; i<handSize; ++i) {
        numerator = numerator * (numInDeck-copies);
        denominator = denominator * numInDeck;
        numInDeck--;
    }
    for (i=0; i<mulliganing; ++i) {
        numerator = numerator * (numInDeck-copies);
        denominator = denominator * numInDeck;
        numAside++;
        numInDeck--; 
    }
    numInDeck = numInDeck + numAside;
    for (i=0; i<turnDraw; ++i) {
        numerator = numerator * (numInDeck-copies);
        denominator = denominator * numInDeck;
        numInDeck--;
    }
    double probability = 1-numerator/denominator;
    printf("The probability of drawing at least one of the cards by turn %d given you mulliganed %d cards is %.2lf\n",turnDraw, mulliganing, probability);
}