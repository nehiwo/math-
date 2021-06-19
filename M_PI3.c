#include<stdio.h>
#include<math.h>

int main(){

    int n = 0;
    double S = 0.0, deltaS = 0.0;

    printf("Input a positive number:");
    scanf("%d",&n);

    S = n * 0.5 * sin((2 * M_PI) / n);
    deltaS = M_PI - S;

    if(S > 3.05){
        printf("π>3.05 true\n");
    }else{
        printf("S=%lf,deltaS=%lf\n",S,deltaS);
    }

    return 0;
}
