#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) {
        printf("Error! Could not open file!");
        exit(-1);
    }


    return 9;

}