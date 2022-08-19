#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

double convertTemp(double oldVal, char oldType, char newType) {
// return the converted new temperature type unit
    double newVal = oldVal;
    if (oldType == 'F') {
        if (newType == 'C') {
            newVal = (oldVal - 32)*5/9;
        } else if (newType == 'K') {
            newVal = (oldVal-32)*5/9+273.15;
        }
    }
    else if (oldType == 'C') {
        if (newType == 'F') {
            newVal = (oldVal * 9/5) +32;
        } else if (newType == 'K') {
            newVal = oldVal + 273.15;
        }
    }
    else if (oldType == 'K') {
        if (newType == 'F') {
            newVal = (oldVal - 273.15) * 9/5 + 32;
        } else if (newType == 'C') {
            newVal = oldVal -273.15;
        }
    }
    return newVal;
}

double convertDistance(double oldVal, char oldType, char newType) {
    // return the converted new distance type unit
    double newVal = oldVal;
    if (oldType == 'I') {
        if (newType == 'F') {
            newVal = oldVal/12;
        } else if (newType == 'Y') {
            newVal = oldVal/36;
        } else if (newType == 'M') {
            newVal = oldVal/63360;
        }
    }
    else if (oldType == 'F') {
        if (newType == 'I') {
            newVal = oldVal*12;
        } else if (newType == 'Y') {
            newVal = oldVal/3;
        } else if (newType == 'M') {
            newVal = oldVal/5280;
        }
    }
    else if (oldType == 'Y') {
        if (newType == 'I') {
            newVal = oldVal*36;
        } else if (newType == 'F') {
            newVal = oldVal*3;
        } else if (newType == 'M') {
            newVal = oldVal/1760;
        }
    }
    else if (oldType == 'M') {
        if (newType == 'I') {
            newVal = oldVal*63360;
        } else if (newType == 'F') {
            newVal = oldVal*5280;
        } else if (newType == 'Y') {
            newVal = oldVal*1760;
        }
    }
    return newVal;
}

void checkTempType(char type) {
    //stops program if temperature type is not valid
    if (type == 'F' || type == 'C' || type == 'K') {
    } else {
        printf("%c is not a valid temperature type. Ending program.\n", type);
        exit(0);
    }
}

void checkDistanceType(char type) {
    //stops program if distance type is not valid
    if (type == 'I' || type == 'F' || type == 'Y' || type == 'M') {
    } else {
        printf("%c is not a valid distance type. Ending program.\n", type);
        exit(0);
    }
}

void checkInput(int numArgs, int neededArgs) {
    //stops program if input is not valid
    char newLine;
    scanf("%c", &newLine);
    if (numArgs == neededArgs && newLine == '\n') {
    } else {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

int main() {
  char type;
  printf("Pick the type of conversion that you would like to do.\n");
  printf("T or t for temperature\n");
  printf("D or d for distance\n");
  printf("Enter your choice: ");
  int numArgs = scanf(" %c", &type);
  checkInput(numArgs, 1);
  type = toupper(type);
  if (type == 'T') {
      printf("Enter the temperature followed by its suffix (F, C, or K): ");
      char tempType;
      double temp; 
      numArgs = scanf("%lf %c", &temp, &tempType);
      checkInput(numArgs, 2);
      tempType = toupper(tempType);
      checkTempType(tempType);
      char newTempType;
      printf("Enter the new unit type (F, C, or K): ");
      numArgs = scanf(" %c", &newTempType);
      checkInput(numArgs, 1);
      newTempType = toupper(newTempType);
      checkTempType(newTempType);
      double newVal = convertTemp(temp, tempType, newTempType);
      printf("%.2lf%C is %.2lf%C\n", temp, tempType, newVal, newTempType);
  } else if (type == 'D') {
      printf("Enter the distance followed by its suffix (I,F,Y,M): ");
      char distanceType;
      double distance; 
      numArgs = scanf("%lf %c", &distance, &distanceType);
      checkInput(numArgs, 2);
      distanceType = toupper(distanceType);
      checkDistanceType(distanceType);
      char newDistanceType;
      printf("Enter the new unit type (I,F,Y,M): ");
      numArgs = scanf(" %c", &newDistanceType);
      checkInput(numArgs, 1);
      newDistanceType = toupper(newDistanceType);
      checkDistanceType(newDistanceType);
      double newVal = convertDistance(distance, distanceType, newDistanceType);
      printf("%.2lf%C is %.2lf%C\n", distance, distanceType, newVal, newDistanceType);
  } else {
      printf("Unknown conversion type %c chosen. Ending program.\n", type);
  }
  
}