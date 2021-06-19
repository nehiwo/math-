#include<stdio.h>
#include<math.h>

double func(double x);

int main(int arcg,const char*argv[]){

    int k = 0, a = 0, N = 0;
    double b = 0.0, c = 0.0;

    printf("Input a positive integer:");
    scanf("%d",&N);

    for(k = 0; k <= N; k++){
        b = 0;
        for(a = 0; a < pow(2.0, k-1); a++){
            b += func((2.0 * a) / (pow(2.0, k))) + 4.0 * func((2.0 * a + 1) / pow(2.0, k)) + func(2.0 * (a + 1) / pow(2.0, k));
        }
        c = pow(2.0, k);
        printf("S[%d]=%lf |S[%d]|=%lf\n", k, b / (3 * c), k, fabs((b / (3 * c) - M_PI)));
    }
    return 0;
}

double func(double x){
    return 4.0 / (1.0 + x * x);
}
