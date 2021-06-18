#include<stdio.h>
#include<string.h>

#define BUBBLE_BUF_SIZE 2 * 10 * 10 * 10 * 10 * 10 + 1

int main(){
    
    static char bubble[BUBBLE_BUF_SIZE];
    
    int index = 1;
    while(fgets(bubble, sizeof(bubble), stdin) != NULL){
        printf("bubble[%i]:%s\n",index,bubble);
        
        int i,j;
        int len = strlen(bubble);
        char temp;
        for(i = 0; i < len; i++){
            for(j = len - 1; j > i; j--){
                if(bubble[j] < bubble[j - 1]){
                    temp = bubble[j];
                    bubble[j] = bubble[j - 1];
                    bubble[j - 1] = temp;
                }
            }
        }
        printf("bubble_sort[%i]:%s\n",index,bubble);
        index++;
    }
    return 0;
}
