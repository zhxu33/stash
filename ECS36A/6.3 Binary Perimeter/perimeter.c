#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Point_struct  {
   int numberPoints;
   int points[10000][2];
} Point;

int main(int argc, char **argv) {
    FILE* textFile = NULL; 
    textFile = fopen(argv[1], "rb");
    Point pts;
    int i = 0;
    fread(&pts.numberPoints, sizeof(int), 1, textFile);
    while (i<pts.numberPoints) {
        fread(&pts.points[i][0], sizeof(int), 1, textFile);
        fread(&pts.points[i][1], sizeof(int), 1, textFile);
        ++i;
    }
    double tot = 0;
    for (i=0; i<pts.numberPoints; ++i) {
        if (i==pts.numberPoints-1) {
            double x1 = pts.points[i][0];
            double x2 = pts.points[0][0];
            double y1 = pts.points[i][1];
            double y2 = pts.points[0][1];
            tot = tot + sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        } else {
            double x1 = pts.points[i][0];
            double x2 = pts.points[i+1][0];
            double y1 = pts.points[i][1];
            double y2 = pts.points[i+1][1];
            tot = tot + sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        }
    }
    printf("The perimeter is %.2lf\n", tot);
}


