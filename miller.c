#include<stdio.h>
#include<string.h>
 
int main(void){

    char str[12] = {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd', '!', '\0'};

    printf("normal:%s\n",str);

    int i = 0, j = 0;

    for(i = 0, j = strlen(str) - 1; i < j; i++, j--){

        char t;

        t = str[i], str[i] = str[j], str[j] = t;

    }

    printf("millering:%s\n ",str);

    return 0;

}
