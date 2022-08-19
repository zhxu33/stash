#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    FILE* textFile = NULL; 
    textFile = fopen(argv[1], "r");
    int numWords = 0;
    char lastRead = 'a';
    while (!feof(textFile)) {
        char read;
        fscanf(textFile, "%c", &read);
        if (isspace(read) && !isspace(lastRead)) {
            numWords++; 
        } 
        lastRead = read;
    }
    printf("There are %d word(s).\n", numWords);
}


