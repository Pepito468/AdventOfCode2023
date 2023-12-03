#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    FILE *p;

    char buffer[100];
    int numbers_buffer[100];
    int i;
    int a=-1,b=-1;
    int flagfirstfound = 0;
    int finalsum = 0;

    p =fopen(argv[1], "r");
    if (!p) {
        exit(1);
    }  
    while (!feof(p)) {
        fscanf(p, " %[^\n]", buffer);
        if (!feof(p)) {
        //printf("%s\n", buffer);

        for (i = 0; i < strlen(buffer) && !flagfirstfound; i++) {
            if (buffer[i] == '0' || buffer[i] == '1' || buffer[i]  == '2' || buffer[i] == '3' || buffer[i] == '4' || buffer[i] == '5' || buffer[i] == '6' || buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9') {
                a = (int) buffer [i] - '0';
                flagfirstfound = 1;
            }
        } 
        flagfirstfound = 0;
        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '0' || buffer[i] == '1' || buffer[i]  == '2' || buffer[i] == '3' || buffer[i] == '4' || buffer[i] == '5' || buffer[i] == '6' || buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9') {
                b = (int) buffer [i] - '0';
            }
        } 

         printf("%d %d\n",a,b);
        finalsum = finalsum +10*a+b;

        }
    }
    
    printf("result: %d\n",finalsum);
    fclose(p);

    return 0;
}