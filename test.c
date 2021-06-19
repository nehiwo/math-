#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LINE_BUF_SIZE 1024

int main(void){
    static char line[LINE_BUF_SIZE];
    int index = 1;

    while(fgets(line,sizeof(line),stdin) != NULL){
        char *ptr;
        ptr = strtok(line," ");
        char *ptr1;
        char *ptr2;
        ptr1 = ptr;
        while(ptr != NULL){
            ptr = strtok(NULL,"@");
            if(ptr != NULL){
                ptr2 = ptr;
                char str[LINE_BUF_SIZE];
                sprintf(str,"%s%s\n",ptr2,ptr1);
                printf("%s\n",str);
            }
        }
    }
    return 0;
}
