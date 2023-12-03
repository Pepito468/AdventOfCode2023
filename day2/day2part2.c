#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define G_LIMIT 13
//#define R_LIMIT 12
//#define B_LIMIT 14

int main(int argc, char* argv[]) {
    FILE *p;
    char buffer[200];
    int r,g,b;
    int power_sum = 0;
    int i;
    int power;
    int game_id;
    char* game_pointer;

    int min_b = -1;
    int min_r = -1;
    int min_g = -1;

    p = fopen(argv[1], "r");
    if (!p){
        exit(1);
    }

     while (!feof(p)) {
        fscanf(p, " %[^\n]", buffer);
        if (!feof(p)) {
        //printf("%s\n", buffer);
        if (buffer[7] == '0') {
            game_id = 100;
            game_pointer = buffer;
        } else if (buffer[6] == ':') {
            game_id = (int) buffer[5]-'0';
            game_pointer = buffer;
        } else {
            game_id = (int) (buffer[5]-'0')*10 + (buffer[6]-'0');
            game_pointer = buffer;
        }
        g=0,r=0,b=0;
        for (i=0; i<strlen(game_pointer); i++) {
            switch (game_pointer[i]) {
                case 'g':
                    if (game_pointer[i-3] == ' ') {
                        g = g + (int) (game_pointer[i-2]-'0');
                    } else {
                        g = g + (int) (game_pointer[i-3]-'0')*10 + (int) (game_pointer[i-2]-'0');
                    }
                    break;
                case 'r':
                    if (game_pointer[i-1]== 'g')
                        break;
                    if (game_pointer[i-3] == ' ') {
                            r = r + (int) (game_pointer[i-2]-'0');
                        } else {
                            r = r + (int) (game_pointer[i-3]-'0')*10 + (int) (game_pointer[i-2]-'0');
                        }
                    break;
                case 'b':
                    if (game_pointer[i-3] == ' ') {
                            b = b + (int) (game_pointer[i-2]-'0');
                        } else {
                            b = b + (int) (game_pointer[i-3]-'0')*10 + (int) (game_pointer[i-2]-'0');
                        }
                    break;
                case ';':
                    /*if (r == -1){
                        min_r = r;
                    }
                    if (g == -1){
                        min_g == g;
                    }
                    if (min_b == -1){
                        min_b = b;
                    }*/

                    if (r > min_r){
                        min_r = r;
                    }
                    if (g > min_g){
                        min_g = g;
                    }
                    if (b > min_b){
                        min_b = b;
                    }
                    r=0;
                    b=0;
                    g=0;
                    break;
                default:
                    //printf("what?");
                    break;
            }
            /*CASE ; FORCED*/
        }
        if (r > min_r){
                        min_r = r;
                    }
                    if (g > min_g){
                        min_g = g;
                    }
                    if (b > min_b){
                        min_b = b;
        }
        power = min_g*min_b*min_r;        
        printf("game %d: %d\n", game_id, power);
        min_b = -1;
        min_g = -1;
        min_r = -1;
        power_sum = power_sum + power;
       // if (!invalidgame) {
       //     id_sum = id_sum + game_id;
       // }

       // invalidgame = 0;



        }
    } 
    printf("result: %d",power_sum);
    //printf("result: %d",id_sum);
    return 0;

}