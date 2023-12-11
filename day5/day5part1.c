#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*this is literally one of the most inefficient things in the universe*/

int main(int argc, char* argv[]){
    FILE *p;
    int height =0;
    //file
    char buffer[1000][1000];
    int i,j,k,h;
    //slider
    int slider;

    //seed container but will transform into fetilizer and so on...
    long int res_container[100];
    long int res_num=0;
    long int res_slid;
    //step counter to know at step I am at
    int stepcounter = -1;
    //filled every line  -> is the array I will use to evolve my seeds
    long int checker[100];
    long int checker_num=0;
    int* already_changed;
    long int min;
    
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

            //there are bigger weapons (numbers) -> need more boolets! (space!)
            //THIS IS DEPRECATED -> DOES NOT WORK WITH MORE THAN 2 DIGITS!!!
            /*if (buffer[i][j] >= '0' && buffer[i][j] <= '9'){
                checker[checker_num] = (int) buffer[i][j] -'0';
                if (buffer[i][j+1] >= '0' && buffer[i][j+1] <= '9'){
                    //another digit
                    checker[checker_num] = checker[checker_num]*10 + ((int) buffer[i][j+1]-'0');
                    j++;
                }
                checker_num++;
            }*/

            //need new method!
            if (buffer[i][j] >= '0' && buffer[i][j] <='9'){
                //found a number!
                checker[checker_num]=0;
                for (k=0;buffer[i][j+k]!=' ' && buffer[i][j+k]!='\0' && buffer[i][j+k] != '\n';k++){
                    checker[checker_num] = (long int) (checker[checker_num]*10+(buffer[i][j+k]-'0'));
                }
                j+=k-1;
                checker_num++;
            }


            if (buffer[i][j] == ':'){
                stepcounter++;
                if (stepcounter > 0){
                    for (k=0;k<res_num;k++){
                        already_changed[k] = 0;
                    }
                }
            }
        }
        printf("Row filled with:\n");
        for (j=0;j<checker_num;j++){
            printf("%ld ",checker[j]);
        }
        printf("\n");

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
                already_changed = (int*)malloc ( sizeof(int)* res_num);
                break;
            case 1:
                //seed-to-oil
                printf("seed-to-oil\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }

                break;
            case 2:
                //soil-to-fert
                printf("soil-to-fert\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }
                break;
            case 3:
                //fet-to-water
                printf("felt-to-water\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }
                break;
            case 4:
                //water-to-light
                printf("water-to-light\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }
                break;
            case 5:
                //light-to-temp
                printf("light-to-temp\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }
                break;
            case 6:
                //temp-to-hum
                printf("temp-to-hum\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }
                break;
            case 7:
                //hum-to-loc
                printf("hum-to-loc\n");
                for (k=0;k<res_num;k++){
                    //printf("%d ",checker[k]);
                    for (h=checker[1];h<checker[1]+slider;h++){
                        if (res_container[k] == h && !already_changed[k]){
                            already_changed[k]++;
                            res_container[k] = checker[0]+(h-checker[1]);
                            printf("Changed %ld to %ld\n",h,res_container[k]);
                            break;
                        }
                    }
                }
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
    printf("Seeds:\n");
    for (k=0;k<res_num;k++){
        printf("%ld ",res_container[k]); 
    }
    /*printf("\n");
    for (i=0;i<checker_num;i++){
        printf("%d ",checker[i]);
    }*/
    printf("\n");


    min = res_container[0];
    for (i=1;i<res_num;i++){
        if (res_container[i]<min){
            min=res_container[i];
        }
    }

    printf("result: %ld\n",min);
    free(already_changed);

    return 0;
}