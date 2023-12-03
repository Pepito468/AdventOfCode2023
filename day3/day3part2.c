#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* actually this was kind of easy with the setup from part 1 with the array boundary :D */

int main(int argc, char* argv[]){
    
    FILE *p;

    char buffer[1000][1000];
    int i,j;
    int height = 0;
    int k,h;
    int x,y;
    int num;
    int sum = 0;
    int cage;
    int flagfisrtfound;
    int flagsecondfound;
    int num2;

    
    i=1;
    p =fopen(argv[1], "r");
    if (!p) {
        exit(1);
    }  
    height++;
    while (!feof(p)) {
        fscanf(p, " %[^\n]", buffer[height]+1);
        if(!feof(p)){
            buffer[height][0]='.';
            buffer[height][strlen(buffer[height])]='.';
            buffer[height][strlen(buffer[height])+1]='\0';
            height++;   
        }
    }
    height++;
    for (j=0;j<strlen(buffer[1]);j++){
        buffer[height-1][j]='.';
        buffer[0][j]='.';
    }
    buffer[height][strlen(buffer[1])]='\0';
    buffer[0][strlen(buffer[1])]='\0';
    
    fclose(p);
    //for(i=0;i<height;i++){
    //    printf("%s\n",buffer[i]);
    //}

    for (i=0;i<height;i++)
    {
        for(j=0;j<strlen(buffer[i]);j++){
            flagfisrtfound = 0;
            flagsecondfound = 0;

           if (buffer[i][j] == '*'){
                //found a star
                for (k=i-1;k<i+2;k++){
                    for(h=j-1;h<j+2;h++){
                        //checking every cell next to *
                        if (buffer[k][h] == '1' || buffer[k][h] == '2' || buffer[k][h] == '3' || buffer[k][h] == '4' || buffer[k][h] == '5' || buffer[k][h] == '6' || buffer[k][h] == '7' || buffer[k][h] == '8' || buffer[k][h] == '9' || buffer[k][h] == '0'){
                            //found one!
                            if (!flagfisrtfound){
                                //fisrt found!
                                flagfisrtfound++;
                                num = (int) buffer[k][h]-'0';
                                if (buffer[k][h-1] == '1' || buffer[k][h-1] == '2' || buffer[k][h-1] == '3' || buffer[k][h-1] == '4' || buffer[k][h-1] == '5' || buffer[k][h-1] == '6' || buffer[k][h-1] == '7' || buffer[k][h-1] == '8' || buffer[k][h-1] == '9' || buffer[k][h-1] == '0'){
                                    //there is a digit before
                                    num = ((int)buffer[k][h-1]-'0')*10+num;
                                    if (buffer[k][h-2] == '1' || buffer[k][h-2] == '2' || buffer[k][h-2] == '3' || buffer[k][h-2] == '4' || buffer[k][h-2] == '5' || buffer[k][h-2] == '6' || buffer[k][h-2] == '7' || buffer[k][h-2] == '8' || buffer[k][h-2] == '9' || buffer[k][h-2] == '0'){
                                        //there are 2 digit before!
                                        num = ((int)buffer[k][h-2]-'0')*100+num;
                                    }   
                                }
                                if (buffer[k][h+1] == '1' || buffer[k][h+1] == '2' || buffer[k][h+1] == '3' || buffer[k][h+1] == '4' || buffer[k][h+1] == '5' || buffer[k][h+1] == '6' || buffer[k][h+1] == '7' || buffer[k][h+1] == '8' || buffer[k][h+1] == '9' || buffer[k][h+1] == '0'){
                                    //there is a digit after
                                    num = num*10 + ((int)buffer[k][h+1]-'0');
                                    if (buffer[k][h+2] == '1' || buffer[k][h+2] == '2' || buffer[k][h+2] == '3' || buffer[k][h+2] == '4' || buffer[k][h+2] == '5' || buffer[k][h+2] == '6' || buffer[k][h+2] == '7' || buffer[k][h+2] == '8' || buffer[k][h+2] == '9' || buffer[k][h+2] == '0'){
                                        //there are 2 digits after!
                                        num = num*10+((int)buffer[k][h+2]-'0');
                                    }
                                }
                                //printf("%d\n",num);
                            } else if (!flagsecondfound){
                                flagsecondfound++;
                                //second found!
                                num2 = (int) buffer[k][h]-'0';
                                if (buffer[k][h-1] == '1' || buffer[k][h-1] == '2' || buffer[k][h-1] == '3' || buffer[k][h-1] == '4' || buffer[k][h-1] == '5' || buffer[k][h-1] == '6' || buffer[k][h-1] == '7' || buffer[k][h-1] == '8' || buffer[k][h-1] == '9' || buffer[k][h-1] == '0'){
                                    //there is a digit before
                                    num2 = ((int)buffer[k][h-1]-'0')*10+num2;
                                    if (buffer[k][h-2] == '1' || buffer[k][h-2] == '2' || buffer[k][h-2] == '3' || buffer[k][h-2] == '4' || buffer[k][h-2] == '5' || buffer[k][h-2] == '6' || buffer[k][h-2] == '7' || buffer[k][h-2] == '8' || buffer[k][h-2] == '9' || buffer[k][h-2] == '0'){
                                        //there are 2 digit before!
                                        num2 = ((int)buffer[k][h-2]-'0')*100+num2;
                                    }   
                                }
                                if (buffer[k][h+1] == '1' || buffer[k][h+1] == '2' || buffer[k][h+1] == '3' || buffer[k][h+1] == '4' || buffer[k][h+1] == '5' || buffer[k][h+1] == '6' || buffer[k][h+1] == '7' || buffer[k][h+1] == '8' || buffer[k][h+1] == '9' || buffer[k][h+1] == '0'){
                                    //there is a digit after
                                    num2 = num2*10 + ((int)buffer[k][h+1]-'0');
                                    if (buffer[k][h+2] == '1' || buffer[k][h+2] == '2' || buffer[k][h+2] == '3' || buffer[k][h+2] == '4' || buffer[k][h+2] == '5' || buffer[k][h+2] == '6' || buffer[k][h+2] == '7' || buffer[k][h+2] == '8' || buffer[k][h+2] == '9' || buffer[k][h+2] == '0'){
                                        //there are 2 digits after!
                                        num2 = num2*10+((int)buffer[k][h+2]-'0');
                                    }
                                }
                                if (num == num2){
                                    flagsecondfound--;
                                } //else { 
                                    //printf("%d\n",num2);
                               // }
                            }
        
                        }
                    }
                }
                 if (flagsecondfound){
                printf("%d * %d\n", num,num2);
                sum = sum + num*num2;
           } else {
            printf("alone %d\n",num);
           }
           }
          
           
        }
    }

    printf("result: %d\n", sum);

    return 0;
}
