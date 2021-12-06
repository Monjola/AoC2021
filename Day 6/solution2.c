#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long nr_0s, nr_1s, nr_2s, nr_3s, nr_4s, nr_5s, nr_6s, nr_7s, nr_8s = 0;
unsigned long nr_fish;

void parseFish(FILE * input) {
    char line[700];
    char delim[]=",";
    char *token;
    fgets(line,700,input);
    token = strtok(line,delim);
    switch (*token)
    {
        case '0':
            nr_0s++;
            nr_fish++;
            break;
        case '1':
            nr_1s++;
            nr_fish++;
            break;
        case '2':
            nr_2s++;
            nr_fish++;
            break;
        case '3':
            nr_3s++;
            nr_fish++;
            break;
        case '4':
            nr_4s++;
            nr_fish++;
            break;
        case '5':
            nr_5s++;
            nr_fish++;
            break;
        case '6':
            nr_6s++;
            nr_fish++;
            break;
        case '7':
            nr_7s++;
            nr_fish++;
            break;
        case '8':
            nr_8s++;
            nr_fish++;
            break;
    }
    int i = 0;

    while (token !=NULL) {
        i++;
        token = strtok(NULL,delim);
        
        if (token !=NULL) {

            switch (*token)
            {
                case '0':
                    nr_0s++;
                    nr_fish++;
                    break;
                case '1':
                    nr_1s++;
                    nr_fish++;
                    break;
                case '2':
                    nr_2s++;
                    nr_fish++;
                    break;
                case '3':
                    nr_3s++;
                    nr_fish++;
                    break;
                case '4':
                    nr_4s++;
                    nr_fish++;
                    break;
                case '5':
                    nr_5s++;
                    nr_fish++;
                    break;
                case '6':
                    nr_6s++;
                    nr_fish++;
                    break;
                case '7':
                    nr_7s++;
                    nr_fish++;
                    break;
                case '8':
                    nr_8s++;
                    nr_fish++;
                    break;
            }
        }
        
    }
}


void loopOverFishes() {
   unsigned long old0s = nr_0s;
   unsigned long old1s = nr_1s;
   unsigned long old2s = nr_2s;
   unsigned long old3s = nr_3s;
   unsigned long old4s = nr_4s;
   unsigned long old5s = nr_5s;
   unsigned long old6s = nr_6s;
   unsigned long old7s = nr_7s;
   unsigned long old8s = nr_8s;

   nr_0s = old1s;
   nr_1s = old2s;
   nr_2s = old3s;
   nr_3s = old4s;
   nr_4s = old5s;
   nr_5s = old6s;
   nr_6s = old7s + old0s;
   nr_7s = old8s;
   nr_8s = old0s;
}

int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) {
        printf("Error! Could not open file!");
        exit(-1);
    }   

    parseFish(input);
    int days = 256;
    for (int day=0; day < days; day++) {
        loopOverFishes();
    }
    printf("nr of fish: %ld\n",nr_0s+nr_1s+nr_2s+nr_3s+nr_4s+nr_5s+nr_6s+nr_7s+nr_8s);
    return 0;

}