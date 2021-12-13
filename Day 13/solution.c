#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dots[1311][895];
char line[15];
char delimit[] = ",";
char *token;
int x = 0;
int y = 0;
int x_len = 1310;
int y_len = 895;
int nr_dots = 0;
void readDots(FILE * input);

void readDots(FILE * input) {
    for (int i =0; i < 853; i++) {
        fgets(line,15,input);
        x = atoi(strtok(line,delimit));
        y = atoi(strtok(NULL,delimit));
        dots[x][y] = 1;   
    }
}

void fold(char axis,int number) {
nr_dots=0;
    if (axis == 'x') {
        for (int dy=0; dy< y_len; dy++) {
            for (int dx=1; dx <= number; dx++) {
                if (dots[number + dx][dy] + dots[number - dx][dy] >= 1) {
                    dots[number - dx][dy] = 1;
                    nr_dots++;
                }
            }    
        }  
    x_len = number - 1;    
    }
    
    if (axis == 'y') {
        for (int dx=0; dx< x_len+1; dx++) {
            for (int dy=1; dy <= number; dy++) {
                if (dots[dx][number-dy] + dots[dx][number + dy] >= 1) {
                    dots[dx][number - dy] = 1;
                    nr_dots++;
                }
            }    
        }
    y_len = number -1;
    } 
}
int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) {
        printf("Error! Could not open file!");
        exit(-1);
    }

    readDots(input);
    
    fold('x',655);
    printf("ANSWER TASK 1: ");
    printf("%d\n", nr_dots);
    fold('y',447);
    fold('x',327);
    fold('y',223);
    fold('x',163);
    fold('y',111);
    fold('x',81);
    fold('y',55);
    fold('x',40);
    fold('y',27);
    fold('y',13);
    fold('y',6);

    printf("ANSWER TASK 2:\n\n");
    for (int y1=0; y1<y_len+1; y1++) {
        for (int x1=0; x1<x_len; x1++) {
        if (dots[x1][y1]) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    }
    
    return 0;

}