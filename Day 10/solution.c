#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// inputs ( [ { <
//outputs ) ] } >

//Rekursiv funktion som callas med input och returnerar när den får motsvarande output?
int exitRecursiveCall = 0;
char output = '(';
int i =0;
int length = 25;
char* test = "{([(<{}[<>[]}>{[]{[(<()>";

char recursiveCall (char input) {
    if (exitRecursiveCall) {
        printf("EXIT\n");
        return output;
    }
    printf("input=%c\n",input);
    while(exitRecursiveCall == 0) {
        if (input == '(' || input == '[' || input == '{' || input == '<') {
            i++;
            if (i < length) {
                printf("since input is one of ([{<, recursive function is called\n");
                output = recursiveCall(test[i]);
                switch (input) {
                    case '(':
                        if (output == ')') {
                            printf("(), OK\n");
                            return output;
                        } else {
                            exitRecursiveCall = 1;
                            printf("%c%c, NOT OK\n",input,output);
                            return output;
                        }
                    case '[':
                        if (output == ']') {
                            printf("[], OK\n");
                            return output;
                        } else {
                            exitRecursiveCall = 1;
                            printf("%c%c, NOT OK\n",input,output);
                            return output;
                        }
                    case '{':
                        if (output == '}') {
                            printf("{}, OK\n");
                            return output;
                        } else {
                            exitRecursiveCall = 1;
                            printf("%c%c, NOT OK\n",input,output);
                            return output;
                        }
                    case '<':
                        if (output == '>') {
                            printf("<>, OK\n");
                            return output;
                        } else {
                            exitRecursiveCall = 1;
                            printf("%c%c, NOT OK\n",input,output);
                            return output;
                        }

                }
            } else {
                printf("length=%d, returning output=%c\n",length,output);
                return output;
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
    
    printf("start string: %s\n",test);
    //char* test = "[[<[([]))<([[{}[[()]]]";
    char result; 
    result = recursiveCall(test[0]);
    printf("result: %c\n",result);
    return 0;

}