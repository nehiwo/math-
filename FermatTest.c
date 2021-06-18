#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int binary_expand(int a, int n);

int main(void){

    int N = 0, a = 0, i = 0;
    int j = 0;
    double c = 0;
    long int T = 1.0, TmodN = 0;
    int b = 0;//データの保管
    srand((unsigned)time(NULL));

    printf("Input a positive number:");
    scanf("%d", &N);

    if(N == 2){
        printf("%d is a prime number.\n", N);
    }else if(N == 1){
        printf("%d is a 1.\n", N);
    }else{
        for(a = 2; a <= sqrt(N - 1); a++){
            TmodN = binary_expand(a, N);
            if(TmodN == 1){
                j++;
            }
            b++;
            printf("as a=%d, TmodN=%ld\n", a, TmodN);
        }
        c = ((double)j / (double)b) * 100;
        if(c != (double)100.0 && c != (double)0.0){
            printf("The possibility that this number is a Fermat pseudoprime number is %lf .\n", c);
        }
        if(TmodN != 1){
            printf("%d is a composite number.\n", N);
        }else{
            printf("%d is a prime number.\n", N);
        }
    }
    return 0;
}

int binary_expand(int a, int n){
    int m = n - 1;
    int S = 1;
    int T = a;
    while(m > 0){
        if(m % 2 == 1){
            S = (S * T) % n;
        }
        T = (T * T) % n;
        m >>= 1;
    }
    return S;
}
