#include <stdlib.h>
#include <stdio.h>



char line[10];
int old_depth_measurement = 0;
int depth_measurement = 0;
int counter = 0;

int main() {
FILE * input = fopen("input1.txt","r");

if (input == NULL) {
    printf("Error, could not open file!");
    exit(-1);
}

while (fgets(line,10,input) !=NULL) {
    depth_measurement=atoi(line);
    if (old_depth_measurement != 0) {
        if (depth_measurement > old_depth_measurement) {
            counter++;
        }
    }
    old_depth_measurement = atoi(line);
}

printf("%d",counter);
fclose(input);

return(0);
}
