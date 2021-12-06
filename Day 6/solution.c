#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lantern_fishes[1000000]={0};
int *end_ptr;

void parseFish(FILE * input, int * fishes) {
    char line[700];
    char delim[]=",";
    char *token;
    fgets(line,700,input);
    token = strtok(line,delim);
    int i = 0;
    fishes[i] = atoi(token);
    while (token !=NULL) {
        i++;
        token = strtok(NULL,delim);
        if (token !=NULL) {
            fishes[i]=atoi(token);
        }
        
    }
    end_ptr = fishes + i;
    
}

void printFish() {
    for(int loop = 0; loop < 600; loop++) {
        printf("%d ", lantern_fishes[loop]);
    }
        
    printf("\n-------end_ptr: %p---------\n",end_ptr);
}

void loopOverFishes(int * fishes) {
    int i =0;
    int *newfishes_ptr=end_ptr;
    int new_fishes_were_spawned=0;
    while (&fishes[i] != end_ptr) {
        if (fishes[i] == 0) {
            fishes[i] = 6;
            *newfishes_ptr = 8;
            newfishes_ptr++; 
            new_fishes_were_spawned=1;
        } else {
            fishes[i]--;
        }
        i++;
    }
    if (new_fishes_were_spawned) {
        end_ptr=newfishes_ptr;
    }
    
}

int numberOfFishes() {
    return (end_ptr-lantern_fishes);
}
int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) {
        printf("Error! Could not open file!");
        exit(-1);
    }

    parseFish(input, lantern_fishes);
    int days=0;
    for (days=0; days < 80; days++) {
        loopOverFishes(lantern_fishes);
    }
    printf("number of fishes after %d days:%d\n",days,numberOfFishes());
    return 0;

}