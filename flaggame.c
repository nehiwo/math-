#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ACT_BUF_SIZE 1024

int main(){
    
    static char act[ACT_BUF_SIZE];
    
    int index = 1;
    while(fgets(act, sizeof(act), stdin) != NULL){
        
        int i = 0;
        int judge1[(strlen(act) + 1) / 3];
        int judge2[(strlen(act) + 1) / 3];
        char red_flag[3] = {0};
        char white_flag[3] = {0};
        for(i = 0; i < (strlen(act) + 1) / 3; i++){
            if(act[3 * i] == 'R'){
                red_flag[0] = act[3 * i];
                red_flag[1] = act[3 * i + 1];
                red_flag[2] = 0;
                if(act[3 * i + 1] == 'D'){
                    judge1[i] = 1;
                    printf("red judge %d ",judge1[i]);
                }
            }else if(act[3 * i] == 'R'){
                red_flag[0] = act[3 * i];
                red_flag[1] = act[3 * i + 1];
                red_flag[2] = 0;
                if(act[3 * i + 1] == 'U'){
                    judge1[i] = 2;
                    printf("red judge %d ",judge1[i]);
                }
            }else if(act[3 * i] == 'W'){
                white_flag[0] = act[3 * i];
                white_flag[1] = act[3 * i + 1];
                white_flag[2] = 0;
                if(act[3 * i + 1] == 'D'){
                    judge2[i] = 1;
                    printf("white judge %d ",judge2[i]);
                }
            }else if(act[3 * i] == 'W'){
                white_flag[0] = act[3 * i];
                white_flag[1] = act[3 * i + 1];
                white_flag[2] = 0;
                if(act[3 * i + 1] == 'U'){
                    judge2[i] = 2;
                    printf("white judge %d\n",judge2[i]);
                }
            }
        }
        
        int temp1, temp2;
        int flag = 0;
        for(i = 0; i < (strlen(act) + 1) / 3 - 1; i++){
            if(judge1[i] == judge1[i + 1] || judge2[i] == judge2[i + 1]){
                printf("Lose\n");
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("Win\nLast flags are %s & %s.\n",red_flag, white_flag);
        }
        printf("\n");
    }
    return 0;
}
