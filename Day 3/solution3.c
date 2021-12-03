#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
char line[16];
int gamma_rate[16];
int bin_gamma_rate = 0;
int epsilon_rate[16];
int bin_epsilon_rate = 0;
int main() {

FILE * input = fopen("input3.txt","r");

    if (input == NULL) {
        printf("Error, could not open file!");
        exit(-1);
    }

    for (int i = 0; i < 12; i++){
        while (fgets(line,15,input) !=NULL) {
            gamma_rate[i] += line[i] - '0';
    }
    printf("%d\n",gamma_rate[i]);
    rewind(input);
    }
    for (int i = 0; i < 12; i++) {
        if (gamma_rate[i] < 500) {
            gamma_rate[i]=0;
            epsilon_rate[i]=1;
        }
        else {
            gamma_rate[i]=1;
            epsilon_rate[i]=0;
        } 
        printf("%d\n",epsilon_rate[i]);
    }
    
    
    int exp = 0;
    for (int i = 11; i >= 0; i--) {
        bin_gamma_rate += gamma_rate[i]* pow(2, exp);
        bin_epsilon_rate += epsilon_rate[i]* pow(2,exp);
        exp +=1;
    }
    
    printf("%d\n",bin_gamma_rate);
    printf("%d\n",bin_epsilon_rate);

    printf("%d\n", bin_gamma_rate*bin_epsilon_rate);
}