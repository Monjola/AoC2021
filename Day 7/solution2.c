#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_values[] = {16,1,2,0,4,2,7,1,2,14};
int median_value = 0;
int alignment = 0;
char line[4000];
char *token;
char delimit[] =",";
int length = 0;
int values[1000] = {0};
int fuel = 0;
int max_value =0;
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int max(int *values,int length) {
    qsort (values, length, sizeof(int), compare);
    return values[length-1];
}

void parseText(FILE * input) {
    int i = 0;
    fgets(line,4000,input);
    token=strtok(line,delimit);
    values[i]=atoi(token);
    length++;
    while (token !=NULL) {
        i++;
        token = strtok(NULL,delimit);
        if (token !=NULL) {
            values[i]=atoi(token);
            length++;
        }
    }
}

int get_fuel(int value, int median) {
    int diff = 0;
    int fuel = 0;
    diff = value - median;
    diff = diff < 0 ? diff*-1 : diff;
    for (int i = 0; i <= diff; i++) {
        fuel+=i;
    }
    
    return fuel;
}

int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) {
        printf("Error! Could not open file!");
        exit(-1);
    }
    parseText(input);
    max_value=max(values,1000);
    int min_fuel=1000000000;
    for (int j=0; j <= max_value; j++) {
        fuel=0;
        for (int i = 0; i < 1000;i++) {
            fuel+= get_fuel(values[i],j);
        } 
        min_fuel = fuel < min_fuel ? fuel : min_fuel;
    }
    printf("%d\n",min_fuel);
    
    
    

    return 0;

}