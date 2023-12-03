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
            if (buffer[i] == '0' || buffer[i] == '1' || buffer[i]  == '2' || buffer[i] == '3' || buffer[i] == '4' || buffer[i] == '5' || buffer[i] == '6' || buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9' || (buffer[i] == 'o' && buffer[i+1] == 'n' && buffer[i+2] == 'e') || (buffer[i] == 't' && buffer[i+1] == 'w' && buffer[i+2] == 'o') || (buffer[i] == 't' && buffer[i+1] == 'h' && buffer[i+2] == 'r' && buffer[i+3] == 'e' && buffer[i+4] == 'e') || (buffer[i] == 'f' && buffer[i+1] == 'o' && buffer[i+2] == 'u' && buffer[i+3] == 'r') || (buffer[i] == 'f' && buffer[i+1] == 'i' && buffer[i+2] == 'v' && buffer[i+3] == 'e') || (buffer[i] == 's' && buffer[i+1] == 'i' && buffer[i+2] == 'x') || (buffer[i] == 's' && buffer[i+1] == 'e' && buffer[i+2] == 'v' && buffer[i+3] == 'e' && buffer[i+4] == 'n') || (buffer[i] == 'e' && buffer[i+1] == 'i' && buffer[i+2] == 'g' && buffer[i+3] == 'h' && buffer[i+4] == 't') || (buffer[i] == 'n' && buffer[i+1] == 'i' && buffer[i+2] == 'n' && buffer[i+3] == 'e')) {
                if (buffer[i] == '0' || buffer[i] == '1' || buffer[i]  == '2' || buffer[i] == '3' || buffer[i] == '4' || buffer[i] == '5' || buffer[i] == '6' || buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9') {
                    a = (int) buffer [i] - '0';
                } else {
                switch (buffer[i]) {
                    case 'o':
                        a = 1;
                        break;
                    case 't':
                        if ( buffer[i+1] == 'w') {
                            a = 2;
                        } else {
                            a=3;
                        }
                        break;
                    case 'f':
                        if (buffer[i+1] == 'o') {
                            a = 4;
                        } else {
                            a = 5;
                        }
                        break;
                    case 's':
                        if ( buffer[i+1] == 'i') {
                            a = 6;
                        } else {
                            a = 7;
                        }
                        break;
                    case 'e':
                        a = 8;
                        break;
                    case 'n':
                        a = 9;
                        break;
                    default:
                        a=0;
                        break;
                }}
                flagfirstfound = 1;
            }
        } 
        flagfirstfound = 0;
        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] == '0' || buffer[i] == '1' || buffer[i]  == '2' || buffer[i] == '3' || buffer[i] == '4' || buffer[i] == '5' || buffer[i] == '6' || buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9' || (buffer[i] == 'o' && buffer[i+1] == 'n' && buffer[i+2] == 'e') || (buffer[i] == 't' && buffer[i+1] == 'w' && buffer[i+2] == 'o') || (buffer[i] == 't' && buffer[i+1] == 'h' && buffer[i+2] == 'r' && buffer[i+3] == 'e' && buffer[i+4] == 'e') || (buffer[i] == 'f' && buffer[i+1] == 'o' && buffer[i+2] == 'u' && buffer[i+3] == 'r') || (buffer[i] == 'f' && buffer[i+1] == 'i' && buffer[i+2] == 'v' && buffer[i+3] == 'e') || (buffer[i] == 's' && buffer[i+1] == 'i' && buffer[i+2] == 'x') || (buffer[i] == 's' && buffer[i+1] == 'e' && buffer[i+2] == 'v' && buffer[i+3] == 'e' && buffer[i+4] == 'n') || (buffer[i] == 'e' && buffer[i+1] == 'i' && buffer[i+2] == 'g' && buffer[i+3] == 'h' && buffer[i+4] == 't') || (buffer[i] == 'n' && buffer[i+1] == 'i' && buffer[i+2] == 'n' && buffer[i+3] == 'e')) {
                if (buffer[i] == '0' || buffer[i] == '1' || buffer[i]  == '2' || buffer[i] == '3' || buffer[i] == '4' || buffer[i] == '5' || buffer[i] == '6' || buffer[i] == '7' || buffer[i] == '8' || buffer[i] == '9') {
                    b = (int) buffer [i] - '0';
                } else {
                switch (buffer[i]) {
                    case 'o':
                        b = 1;
                        break;
                    case 't':
                        if ( buffer[i+1] == 'w') {
                            b = 2;
                        } else {
                            b=3;
                        }
                        break;
                    case 'f':
                        if (buffer[i+1] == 'o') {
                            b = 4;
                        } else {
                            b = 5;
                        }
                        break;
                    case 's':
                        if ( buffer[i+1] == 'i') {
                            b = 6;
                        } else {
                            b = 7;
                        }
                        break;
                    case 'e':
                        b = 8;
                        break;
                    case 'n':
                        b = 9;
                        break;
                    default:
                        b=0;
                        break;
                }}
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