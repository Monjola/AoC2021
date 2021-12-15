#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void getFirstLine(FILE * input, int length);
void skipRow(FILE *input);
struct InsertionRules getPairInsertionRules(FILE * input);

char line[25];
char line2[8];
char delimit[] = " ->";
char *token;
char startString[25];
struct InsertionRules {
    char pair[100][2];
    char result[100];
};

void getFirstLine(FILE * input, int length) {
    fgets(line, length,input);
    strcpy(startString,line);
}

void skipRow(FILE *input) {
    fgets(line,25,input);
}

struct InsertionRules getPairInsertionRules(FILE * input) 
{
    struct InsertionRules myRules;
    for (int i=0; i<100; i++) {
        fgets(line2,9,input);

        token = strtok(line2,delimit);
        strcpy(myRules.pair[i],token);

        token = strtok(NULL,delimit);
        myRules.result[i]=token[0];
    }   
}

char * applyRules(char * polymerTemplate, struct InsertionRules rules) 
{   //skapa ny resultat char*
    char newPolymerTemplate[];

    //För varje par, kolla om lika med något i rules.pair
    //Om det är likamed ett par, ta rules.result och stoppa in.
    return newPolymerTemplate;
}


int main() {

    FILE * input = fopen("input.txt","r");

    if (input==NULL) 
    {
        printf("Error! Could not open file!");
        exit(-1);
    }

    getFirstLine(input, 25);
    skipRow(input);

    struct InsertionRules rules = getPairInsertionRules(input);

    char resultingPolymer[] = applyRules(startString,rules);

    printf("%s\n",line);
    free(resultingPolymer);

    return 0;

}