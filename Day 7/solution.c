#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_values[] = {16,1,2,0,4,2,7,1,2,14};
int median_value = 0;
char line[4000];
char *token;
char delimit[] =",";
int length = 0;
int values[1000] = {0};
int fuel = 0;

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int median(int *values,int length) {
    qsort (values, length, sizeof(int), compare);
    return values[length/2];
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

int get_fuel(void) {
    int diff = 0;
    for (int i=0; i < length; i++) {
        diff = values[i] - median_value;
        diff = diff < 0 ? diff*-1 : diff;
        fuel += diff;
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
    median_value = median(values,length);
    fuel = get_fuel();
    printf("%d\n", fuel);

    return 0;

}