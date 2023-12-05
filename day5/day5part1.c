#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    FILE *p;
    int height =0;
    //file
    char buffer[1000][1000];
    int i,j,k,h;
    //slider
    int slider;

    //seed container but will transform into fetilizer and so on...
    int res_container[100];
    int res_num=0;
    int res_slid;
    //step counter to know at step I am at
    int stepcounter = -1;
    //filled every line  -> is the array I will use to evolve my seeds
    int checker[100];
    int checker_num=0;

    
    p =fopen(argv[1], "r");
    if (!p) {
        exit(1);
    }  
    while (!feof(p)) {
        fscanf(p, " %[^\n]", buffer[height]);
        printf("%s\n", buffer[height]);
        height++;
    }

    fclose(p);
    printf("\n");

    for (i=0;i<height;i++){
        checker_num=0;
        res_slid=0;
        for (k=0;k<100;k++){
            checker[k]=-1;
        }
            for (j=0;j<strlen(buffer[i]);j++){
            //cleaning checker


            if (buffer[i][j] >= '0' && buffer[i][j] <= '9'){
                checker[checker_num] = (int) buffer[i][j] -'0';
                if (buffer[i][j+1] >= '0' && buffer[i][j+1] <= '9'){
                    //another digit
                    checker[checker_num] = checker[checker_num]*10 + ((int) buffer[i][j+1]-'0');
                    j++;
                }
                checker_num++;
            }
            if (buffer[i][j] == ':'){
                stepcounter++;
            }
        }
        //printf("Elements in the line: [%d]\n", checker_num);
        slider = checker[2]; //range
        switch (stepcounter) {
            case 0:
                //filling seeds!
                printf("Filling seeds\n");
                for (k=0;k<checker_num;k++){
                    res_container[k] = checker[k];
                    //printf("%d ",checker[k]);
                }
                res_num = checker_num;
                //printf("%d\n",res_num);
                break;
            case 1:
                //seed-to-oil
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    //TODO
                }

                break;
            case 2:
                //soil-to-fert
                break;
            case 3:
                //fet-to-water
                break;
            case 4:
                //water-to-light
                break;
            case 5:
                //light-to-temp
                break;
            case 6:
                //temp-to-hum
                break;
            case 7:
                //hum-to-loc
                break;
            default:
                //do nothing
            break;
        }
    }

    //printf("%d\n",res_num);
    /*for (i=0;i<res_num;i++)
    {
        printf("%d ",res_container[i]);
    }*/
    for (k=0;k<res_num;k++){
        printf("%d ",res_container[k]); 
    }
    printf("\n");

    return 0;
}