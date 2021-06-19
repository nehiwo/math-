#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

unsigned int power( unsigned int a, unsigned int k, unsigned int n );

int main(){

    int hirabun = 0, angou = 0, N = 0, E = 0;

    printf("input hirabun:");
    scanf("%d",&hirabun);

    printf("input publickey\n");
    printf("N=");
    scanf("%d",&N);
    printf("E=");
    scanf("%d",&E);
    angou=power(hirabun,E,N);

    printf("angou:%d\n",angou);

    return 0;
}

/*
  繰り返し自乗法を使った法nのべき乗計算( aのk乗をnで割った余りを求める )

  unsigned int a : 底
  unsigned int k : 指数
  unsigned int n : 法
*/
unsigned int power( unsigned int a, unsigned int k, unsigned int n ){
    if ( n >= 0x10000 ){
        return 0;
    }

    if ( a == 0 || n == 0 ){
        return 0;
    }
    
    if ( k == 0 ){
        return 1 % n;
    }

    unsigned int currentMod = a % n;
    unsigned int currentValue = ( ( k & 1 ) > 0 ) ? currentMod : 1;

    for ( k >>= 1 ; k > 0 ; k >>= 1 ) {
        currentMod = ( currentMod * currentMod ) % n;
        if ( ( k & 1 ) > 0 ){
            currentValue = ( currentValue * currentMod ) % n;
        }
    }

    return currentValue;
}
