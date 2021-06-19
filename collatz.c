#include<stdio.h>

int main(int argc,const char*argv[]){
    unsigned long long int n = 0, i = 0;
    i = 0;
    printf("input a positive integer:");
    scanf("%llu",&n);
    printf("%llu\n",n);
    while(n > 1){
        if(n % 2 == 0){
            n = n / 2;
        }else if(n % 2 == 1){
            n = 3 * n + 1;
        }
        printf("=>%llu\n",n);
        i = i + 1;
    }
    printf("f(n) = %llu\n",i);
    return 0;
}
