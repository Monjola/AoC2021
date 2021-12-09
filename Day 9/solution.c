#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line0 [102];
char line1 [102];
char line2 [102];
int risk_level_sum = 0;

void checkRow(void) {
    for (int i = 0; i <100; i++) {
        if (i==0) {
            if (line1[i] < line1[i+1] && line1[i] < line0[i] && line1[i] < line2[i]) {
                risk_level_sum +=line1[i] - '0' +1;
            }    
        } else if (i==99) {
            if (line1[i] < line1[i-1] && line1[i] < line0[i] && line1[i] < line2[i]) {
                risk_level_sum +=line1[i] - '0' +1;
            }
        } else {
            if (line1[i] < line1[i-1] && line1[i] < line1[i+1] && line1[i] < line0[i] && line1[i] < line2[i]) {
                risk_level_sum +=line1[i] - '0' +1;
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

    //edge case first row
    for (int i = 0; i <100; i++) {
        line0[i] = '9';
    }
    fgets(line1,102,input);

    while (fgets(line2,102,input) != NULL) {
        checkRow();
        strcpy(line0,line1);
        strcpy(line1,line2);
    }

    //edge case last row
    for (int i = 0; i <100; i++) {
        line2[i] = '9';
    }
    checkRow();

    printf("%d\n",risk_level_sum);
    return 0;

}