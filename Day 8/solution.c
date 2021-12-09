#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int zero = 6; //  * 
int one = 2; //unique
int two = 5; // **
int three = 5; // **
int four = 4; //unique
int five = 5; // **
int six = 6; // *
int seven = 3; //unique
int eight = 7; //unique
int nine = 6; // *
char *token;
char line[100];
char unique_signal_patterns[200][80];
char output_signals[200][50];

int count = 0;

void parseFile(FILE * input) {
    char delimit[] = "|";
    int i = 0;
    while (fgets(line,100,input) != NULL) {
        strcpy(unique_signal_patterns[i],strtok(line,delimit));
        strcpy(output_signals[i], strtok(NULL,delimit));
        i++;
    }
}

int countoutput0478(char signals[200][50]) {
    char delimit[] = " ";
    int counter=0;
    for (int i = 0; i < 200; i++) {
        counter = 0;
        token = strtok(signals[i],delimit);
        int str_len = strlen(token);
        //rintf("WTFtoken=%s\n WTFstr_len=%d\n",token,str_len);
        printf("token=%s\n",token);
        if (str_len == one || str_len == four || str_len == seven || str_len == eight) {
            printf("token that is counted=%s\n",token);
            count++;
        }
        counter++;
        while (token != NULL) {
            token = strtok(NULL,delimit);
            if (token !=0) {
                str_len = strlen(token);
                if (counter == 3) {
                    str_len--; 
                }
                //printf("LOLtoken=%s\nLOLstr_len=%d\n",token,str_len);
                printf("token=%s\n",token);
                if (str_len == one || str_len == four || str_len == seven || str_len == eight) {
                    printf("token that is counted=%s\n",token);
                    count++;
                }
                counter++;
            }
            
        }
    }   
}

int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) {
        printf("Error! Could not open file!");
        exit(-1);
    }
    parseFile(input);
    countoutput0478(output_signals);
    printf("%d\n",count);
    return 0;

}