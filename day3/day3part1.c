#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this was a pain :( */
/*basically to avoid goint out of bound with the array i made an extra layer of '.' around the array so it can never ever EVER explode*/

int main(int argc, char* argv[]){
    
    FILE *p;

    char buffer[1000][1000];
    int i,j;
    int height = 0;
    int k,h;
    int num;
    int sum = 0;
    int cage;
    int flag;

    
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
            cage = 0;
            flag = 0;
            if (buffer[i][j] == '1' || buffer[i][j] == '2' || buffer[i][j] == '3' || buffer[i][j] == '4' || buffer[i][j] == '5' || buffer[i][j] == '6' || buffer[i][j] == '7' || buffer[i][j] == '8' || buffer[i][j] == '9' || buffer[i][j] == '0') {
                //found a number!
                num = (int) buffer[i][j] - '0';
                //printf("num1: %d\n",num);
                if (buffer[i][j+1] == '1' || buffer[i][j+1] == '2' || buffer[i][j+1] == '3' || buffer[i][j+1] == '4' || buffer[i][j+1] == '5' || buffer[i][j+1] == '6' || buffer[i][j+1] == '7' || buffer[i][j+1] == '8' || buffer[i][j+1] == '9' || buffer[i][j+1] == '0') {
                    num = num*10 + ((int) buffer[i][j+1]-'0');
                    //printf("num2: %d\n",num);
                    cage++;
                    if (buffer[i][j+2] == '1' || buffer[i][j+2] == '2' || buffer[i][j+2] == '3' || buffer[i][j+2] == '4' || buffer[i][j+2] == '5' || buffer[i][j+2] == '6' || buffer[i][j+2] == '7' || buffer[i][j+2] == '8' || buffer[i][j+2] == '9' || buffer[i][j+2] == '0') {
                        num = num*10 + ((int) buffer[i][j+2]-'0');
                        //printf("num: %d\n",num);
                        cage++;
                    }
                }

                //printf("num: %d\n",num);
                /*DETECTINGN IF THE NUMBER IS VALID*/
                
                for (k=i-1;k<i+2 && !flag;k++){
                    for (h=j-1; h<j+2+cage && !flag;h++){
                        if (buffer[k][h] != '.' && buffer[k][h] != '0' && buffer[k][h] != '1' && buffer[k][h] != '2' && buffer[k][h] != '3' && buffer[k][h] != '4' && buffer[k][h] != '5' && buffer[k][h] != '6' && buffer[k][h] != '7' && buffer[k][h] != '8' && buffer[k][h] != '9'){
                            //number is valid!
                            flag++;
                            sum=sum+num;
                            //printf("valid num: %d\n",num);
                            //printf("new sum: %d\n",sum);
                        }
                    }
                }
                j+=cage;
            } 
            //printf("num: %d\n",num);
        }
    }

    printf("result: %d\n", sum);

    return 0;
}
