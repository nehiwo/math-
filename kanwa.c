#include<stdio.h>
#include<math.h>

double func(double x);

int main(int argc,const char*argv[]){
    double x = -1;
    double e = 0.00000001;
    int k = 1;
    double b = 0.1;
    while(fabs(func(x)) > e){
        x = x - b * func(x);
        printf("x[%d]=%lf\n",k,x);
        k++;
    }
    return 0;
}

double func(double x){
    return tanh(x) + 0.2 * x - 0.3;
}
