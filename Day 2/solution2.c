#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int horizontal_position = 0;
int depth = 0;
char line[15];
char delim[] = " ";
int aim = 0;

int main() {
FILE * input = fopen("input2.txt","r");

if (input == NULL) {
    printf("Error, could not open file!");
    exit(-1);
}

while (fgets(line,15,input) !=NULL) {

char *direction = strtok(line, delim);
char *length = strtok(NULL,delim);

switch (direction[0]) {
    
    case 'u':
        depth, aim -= atoi(length);
        break;
    case 'd':
        depth, aim += atoi(length);
        break;
    case 'f':
        horizontal_position += atoi(length);
        depth += aim*atoi(length);
        break;
    default:
        printf("Error! Operator is not correct\n");

}
}
printf("%d",depth*horizontal_position);
fclose(input);

return(0);
}