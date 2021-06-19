#include<stdio.h>

int fib(int x);

int main(){
    
    int x = 0;
    scanf("%d",&x);
    
    int y = x;
    int counta = 0;
    while(y > 0){
        counta++;
        y = y - fib(counta);
    }
    
    if(x == 1){
        printf("x = fib(1) or fib(2)\n");
    }else if(x - fib(counta) == fib(counta - 1)){
        printf("%d\n",counta + 1);
    }else{
        printf("No\n");
    }
    return 0;
}

//再帰関数.
int fib(int x){
    int val = 0;
    if(x == 1 || x == 2){
        val = 1;
    }else{
        val = fib(x - 1) + fib(x - 2);
    }
    return val;
}
