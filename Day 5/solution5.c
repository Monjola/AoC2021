#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int map[1000][1000];
char delim[] = ", ->";
char line[20];

void parseLine(char* line, int *x1, int *y1, int *x2, int *y2) {
    *x1 = atoi(strtok(line, delim));
    *y1 = atoi(strtok(NULL, delim));
    *x2 = atoi(strtok(NULL, delim));
    *y2 = atoi(strtok(NULL, delim));
    //printf("x1=%d\ny1=%d\nx2=%d\ny2=%d\n",*x1,*y1,*x2,*y2);
}


int main () {

    FILE * input = fopen("input5.txt","r");

    if (input == NULL) {
        printf("Error! Couldn't load file");
        exit(-1);
    }
    int x1=0;
    int y1=0;
    int x2=0;
    int y2=0;
    int xmin = 0;
    int xmax = 0;
    int ymin = 0;
    int ymax = 0;
    while (fgets(line,20,input) !=NULL) {
        parseLine(line,&x1,&y1,&x2,&y2);
        if (x1==x2) {
            int x=x1;
            if (y1 < y2) {
                ymin = y1;
                ymax = y2;
            } else {
                ymin = y2;
                ymax = y1;
            }
            for (int y=ymin; y < ymax+1; y++) {
                map[x][y]++;
            }
        } else if (y1==y2) {
            int y=y1;
            if (x1 < x2) {
                xmin = x1;
                xmax = x2;
            } else {
                xmin = x2;
                xmax = x1;
            }
            for (int x=xmin; x < xmax+1; x++) {
                map[x][y]++;
            }
        } else {
            int x_factor = 0;
            int y_factor = 0;
            x_factor = x1 < x2 ? 1 : -1;
            y_factor = y1 < y2 ? 1 : -1;
            int x=0;
            int y=0;
            for (x=x1, y=y1; x != x2 + x_factor; x+=x_factor, y+=y_factor) {
                map[x][y]++;
            }
        }
    }
    int counter = 0;
    for (int x=0; x < 1000; x++) {
        for (int y=0; y <1000; y++) {
            if (map[x][y] > 1) {
                counter++;
            }
            
        }
    }
    printf("%d\n",counter);
    return 0;
}