#include <stdio.h>
#include <math.h>

double func1(double x);

int main(int argc,const char**argv){
    double x = 1.0;
    double e = 0.00000001;
    int k = 1;
    while(fabs(func1(x)) > e){
        x = func1(x);
        printf("x[%d]=%lf\n",k,x);
        k++;
    }
    return 0;
}

double func1(double x){
    return 2 * cos(x) / (3 * x);
}
