#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    FILE *p;

    char buffer[1000][1000];
    int win[100];
    int my[100];
    int i,j,k,h;
    int height = 0;
    int sum_of_points = 0;
    int number_of_wins = 0;
    int winning = 0;

    int i_win=0;
    int i_my=0;

    char* winnig_numbers_p = NULL;
    char* my_numbers_p = NULL;
    p =fopen(argv[1], "r");
    if (!p) {
        exit(1);
    }  
    while (!feof(p)) {
        fscanf(p, " %[^\n]", buffer[height]);
        if(!feof(p)){
            //printf("%s\n", buffer[height]);
            //buffer[height][strlen(buffer[height])] = '\0';
        }
        height++;
    }
    fclose(p);
    height--;
    //printf("height: %d\n",height);
    for (i=0;i<height;i++){
        //checking every line to assign pointers
        
        for (j=0;j<strlen(buffer[i]);j++){
            //printf("flag");
            i_my=0;
            i_win=0;
            if (buffer[i][j] == ':'){
                //found the beginning of the winning part
                winnig_numbers_p = &buffer[i][j];
                //printf("%c -> %c ",buffer[i][j],winnig_numbers_p[0]);
                //printf("%d ",strlen(winnig_numbers_p));
            }
            if (buffer[i][j] == '|'){
                //found the beginning of my part
                my_numbers_p = &buffer[i][j];
            }
            //printf("flag");
            //printf("%d %d\n", strlen(winnig_numbers_p), strlen(my_numbers_p));
            //printf("%c\n", winnig_numbers_p[0]);
            //filling the 2 arrays with the numbers
            if (winnig_numbers_p && my_numbers_p) {
                for (k=0;k<strlen(winnig_numbers_p)-strlen(my_numbers_p);k++){
                    if (winnig_numbers_p[k] >= '0' && winnig_numbers_p[k] <= '9'){
                        //found a number!
                        win[i_win] = (int)winnig_numbers_p[k]-'0';
                        //printf("%d", win[i_win]);
                        if (winnig_numbers_p[k+1] >= '0' && winnig_numbers_p[k+1] <='9'){
                            //there is another digit!
                            win[i_win] = win[i_win]*10 + ((int)winnig_numbers_p[k+1]-'0');
                        }
                        i_win++;
                        k++;
                    }
                }
                for (k=0;k<strlen(my_numbers_p);k++){
                    if (my_numbers_p[k] >= '0' && my_numbers_p[k] <= '9'){
                        //found one!
                        my[i_my] = (int)my_numbers_p[k]-'0';
                        if (my_numbers_p[k+1] >= '0' && my_numbers_p[k+1] <= '9'){
                            //another digit!
                            my[i_my] = my[i_my]*10+((int)my_numbers_p[k+1]-'0');
                        }
                        i_my++;
                        k++;
                    }
                }
                if (buffer[i][j+1] == '\0'){
                    //end of the liiiiiiiiiiiiiiiine (cit.)

                    //i have them!
                    //now i have toc heck if they are winning numbers
                    for (k=0;k<i_win;k++){
                        printf("%d ",win[k]);
                    }
                    printf(" | ");
                    for (k=0;k<i_my;k++){
                        printf("%d ",my[k]);
                    }
                    printf("\n");

                    //checking
                    winning = 0;
                    number_of_wins = 0;
                    for (k=0;k<i_my;k++){
                        winning = 0;
                        for (h=0;h<i_win && !winning;h++){
                            if (my[k]==win[h]){
                                printf("Winning: %d\n",my[k]);
                                if (number_of_wins == 0){
                                    number_of_wins = 1;
                                } else {
                                    number_of_wins*=2;
                                }
                                winning++;
                            }
                        }
                    }
                    sum_of_points +=number_of_wins;
                }
            }
        }
    }
    printf("result: %d\n",sum_of_points);
    return 0;
}