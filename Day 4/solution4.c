#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char delimit[] = " -";
char *token;
struct BingoBoard{
    u_int8_t row1[4];
    u_int8_t row2[4];
    u_int8_t row3[4];
    u_int8_t row4[4];
    u_int8_t row5[4];
    u_int8_t col1[4];
    u_int8_t col2[4];
    u_int8_t col3[4];
    u_int8_t col4[4];
    u_int8_t col5[4];
};


int * read_numbers_to_be_called(FILE * input, int * numbers) {
    char raw_numbers[300];
    //int numbers[150];
    fgets(raw_numbers,300,input);
    token = strtok(raw_numbers,delimit);
    numbers[0]=atoi(token);
    int i = 1;
    while(token !=NULL) {
        printf("%s\n",token);
        token = strtok(NULL,delimit);
        numbers[i] = atoi(token);
        i++;
    }
}

int main() {

    FILE * input = fopen("input4.txt","r");

    if (input == NULL) {
        printf("Error! Couldn't load file");
        exit(-1);
    }
    int numbers[100];
    read_numbers_to_be_called(input, numbers);
    //struct BingoBoard bingboards[150] = read_bingoboards(input);

    fclose(input);
    return (0);
}