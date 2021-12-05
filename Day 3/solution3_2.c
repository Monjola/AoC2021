#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
char line[16];
int nr_1s_per_col[16];
int gamma_rate[16];
int epsilon_rate[16];
char *all_lines[1000];
int nr_of_lines=0;
int oxygen_generator_rating[12];
int c02_scrubber_rating[12];


void copy_winners(FILE * input,FILE * output,int col, char type) {
    char winning_nr = '0';
    if (type == 'o') {
        char winning_nr = nr_1s_per_col[col] >= nr_of_lines/2 ? '1' : '0';
    } else if (type=='c'){
        char winning_nr = nr_1s_per_col[col] > nr_of_lines/2 ? '0' : '1';
    }
        
    /*oxygen_generator_rating[col]=winning_nr - '0';
    if (winning_nr== '1') {
        c02_scrubber_rating[col]=0;
    } else {
        c02_scrubber_rating[col]=1;
    }
    */

    while (fgets(line,15,input) !=NULL) {
        if ((char)line[col]==winning_nr) {
            fputs(line,output);
        }
    }
}

void nr_of_1s_per_col(FILE * input,int col) {
    rewind(input);
    for (int i=0; i <16; i++) {
        nr_1s_per_col[i]=0;
    }
    nr_of_lines=0;
    
    while (fgets(line,15,input) !=NULL) {
        nr_1s_per_col[col] += line[col] - '0';
        nr_of_lines++;
    }
    nr_of_lines = nr_of_lines/12;
    printf("Nr of 1s in column %d: \t\t %d\nnumber of lines in file:\t %d\n",col,nr_1s_per_col[col],nr_of_lines);
}


int main() {
    
    FILE * input = fopen("input3.txt","r");
    FILE * oxygen = fopen("oxygen.txt","w+");
    FILE * c02 = fopen("c02.txt", "w+");

    if (input == NULL && oxygen == NULL && c02 == NULL) {
        printf("Error, could not open file!");
        exit(-1);
    } 

    nr_of_1s_per_col(input,0);
    copy_winners(input,oxygen,0,'o');
    //copy_winners(input,c02,0,'c');
    for (int col=1; col < 13; col++) {
        rename("oxygen.txt","inputoxygen.txt");
        //rename("c02.txt","inputc02.txt");
        FILE *inputoxygen=fopen("inputoxygen.txt","r");
        //FILE *inputc02 = fopen("inputc02.txt","r");
        oxygen=fopen("oxygen.txt", "w+");
        //c02 = fopen("c02.txt","w+");

        nr_of_1s_per_col(inputoxygen,col);
        copy_winners(inputoxygen,oxygen,col,'o');
        //nr_of_1s_per_col(inputc02,col);
        //copy_winners(inputc02,c02,0,'c');
    
    }
    

    fclose(input);
    //fclose(inputoxygen);
    //fclose(inputc02);

    return(0);
}