#include <stdlib.h>
#include <stdio.h>



char line[10];
int old_depth_measurement = NULL;
int depth_measurement = NULL;
int main() {
FILE * input = fopen("input1","r");

if (input == NULL) {
    printf("Error, could not open file!");
    exit(-1);
}

while (fgets(line,10,input) !=NULL) {
    //printf("%s",line);
    

}
fclose(input);
return(0);
}
