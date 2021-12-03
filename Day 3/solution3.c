#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
char line[16];
int nr_1s_per_col[16];
int gamma_rate[16];
int epsilon_rate[16];

void nr_of_1s_per_col(FILE * input) {
    for (int i = 0; i < 12; i++){
        while (fgets(line,15,input) !=NULL) {
            nr_1s_per_col[i] += line[i] - '0';
    }
    rewind(input);
    }
}
void make_bin_arrays(void) {
    for (int i = 0; i < 12; i++) {
        if (nr_1s_per_col[i] < 500) {
            gamma_rate[i]=0;
            epsilon_rate[i]=1;
        }
        else {
            gamma_rate[i]=1;
            epsilon_rate[i]=0;
        } 
    }
}

int bin_arr_to_bin_int(int *bin_arr,int length) {
    int int_bin=0;
    int exp = 0;
    for (int i = length; i >= 0; i--) {
        int_bin += bin_arr[i]* pow(2, exp);
        exp +=1;
    }
}
int main() {
    
    FILE * input = fopen("input3.txt","r");

    if (input == NULL) {
        printf("Error, could not open file!");
        exit(-1);
    }
    nr_of_1s_per_col(input);
    make_bin_arrays();
    
    int bin_gamma_rate = bin_arr_to_bin_int(gamma_rate,11);
    int bin_epsilon_rate = bin_arr_to_bin_int(epsilon_rate,11);

    printf("%d\n", bin_gamma_rate*bin_epsilon_rate);
}