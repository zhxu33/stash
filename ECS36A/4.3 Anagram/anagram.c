#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void makeUpper(char str[]) {
    //make the char array uppercase
    for (int i=0; i<strlen(str); ++i) {
        str[i] = toupper(str[i]);
    }
}

int main() {
    char firstWord[20];
    char secondWord[20];
    printf("Please enter the first word: ");
    scanf("%s", firstWord);
    printf("Please enter the second word: ");
    scanf("%s", secondWord);
    char testFirstWord[20];
    char testSecondWord[20];
    strcpy(testFirstWord, firstWord);
    strcpy(testSecondWord, secondWord);
    makeUpper(testFirstWord);
    makeUpper(testSecondWord);
    int lenFirst = strlen(firstWord);
    int lenSecond = strlen(secondWord);
    if (lenFirst != lenSecond) {
        printf("%s is NOT an anagram of %s\n", firstWord, secondWord);
        exit(0);
    }
    for (int i = 0; i<lenFirst; ++i) {
        bool found = false;
        for (int k = 0; k<lenFirst; ++k) { 
            if (testFirstWord[i] == testSecondWord[k]) {
                found = true;
                testSecondWord[k] = '\0';
                break;
            }
        }
        if (found == false) {
            printf("%s is NOT an anagram of %s\n", firstWord, secondWord);
            exit(0);
        }
    }
    printf("%s is an anagram of %s\n", firstWord, secondWord);
}

