#include<stdio.h>
#include<math.h>

double func(double x);

int main(int argc,const char**argv){

    double ans = M_PI;
    int a = 0, b = 0, N = 0, i = 0;
    double c = 0.0, S = 0.0;

    printf("Input a positive integer:");
    scanf("%d",&N);
    for(a = 0; a < N; a++){
        i++;
        c = 0;
        for(b = 1; b < pow(2, a); b++){
            c += func(b / (pow(2, a)));
        }
        S = 1 / pow(2, a+1) * (2 * c + func(0) + func(1));
        printf("S[%d]=%f |S[%d]-π|=%f\n", i, S, i, fabs(S - ans));
    }
    return 0;
}

double func(double x){
    return 4 / (1 + x * x);
}
