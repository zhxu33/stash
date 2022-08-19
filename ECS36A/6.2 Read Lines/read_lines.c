#include <stdio.h>
#include <stdlib.h>
#include "read_lines.h"

//gdb --args ./read_lines.out blank.txt

void read_lines(FILE* fp, char*** lines, int* num_lines) {
    char read;
    while (!feof(fp)) {
        fscanf(fp, "%c", &read);
        if (read == '\n') {
        *num_lines = *num_lines + 1;
        }
    }
    rewind(fp);
    int i=0;
    *num_lines = *num_lines - 1;
    *lines = (char**)malloc((*num_lines)*sizeof(char*));
    int numchar = 1;
    while (!feof(fp)) {
        if (i==*num_lines) {
            break;
        }
        fscanf(fp, "%c", &read);
        if (read == '\n') {
           (*lines)[i] = (char*)malloc((numchar+1)*sizeof(char));
           (*lines)[i][numchar] = '\0';
           numchar = 1;
           i++;
        } else {
            numchar++;
        }
    }
    rewind(fp);
    i = 0;
    int j = 0;
    if (*num_lines == -1) {
        exit(0);
    }
    while (!feof(fp)) {
        if (i==*num_lines) {
            break;
        }
        fscanf(fp, "%c", &read);
        (*lines)[i][j] = read;
        if (read == '\n') {
            i++;
            j=0;
        } else {
            j++;
        }
    }
}