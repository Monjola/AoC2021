#include <stdlib.h>
#include <stdio.h>

char line[10];
int old = 0;
int new = 0;
int counter = 0;
int arr[2000];
int i = 0;
int k=3;

int main() {
FILE * input = fopen("input1.txt","r");

if (input == NULL) {
    printf("Error, could not open file!");
    exit(-1);
}

while (fgets(line,10,input) !=NULL) {
    arr[i] = atoi(line);
    i++; 
}

for (int j = 0; j < k; j++) {
    old += arr[j];
}

for (int j = k; j<2000; j++) {
    new = old + arr[j] - arr[j-k];
    if (new > old) { 
        counter++;
    }
    old = new;
}

printf("%d",counter);

fclose(input);
return(0);
}

