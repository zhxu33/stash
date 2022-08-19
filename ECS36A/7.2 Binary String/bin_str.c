#include <stdio.h>

void bin_str(char str[], int index) {
    if (str[index] == '\0') {
        printf("%s\n", str);
        return;
    } 
    if (str[index] == 'x' || str[index] == 'X')  {
        str[index] = '0';
        bin_str(str, index+1);
        str[index] = '1';
        bin_str(str, index+1);
        str[index] = 'x';
        return;
    }
    bin_str(str, index+1);
}

int main(int argc, char **argv) {
    bin_str(argv[1], 0);
}