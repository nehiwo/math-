#include<stdio.h>
#include<math.h>
double func1(double x);
double func2(double x);
int main(int argc,const char*argv[]){
double x=2.0;
double e=0.00000001;
int k=1;
while(fabs(func1(x))>e){
x=x-(func1(x)/func2(x));
printf("x[%d]=%lf\n",k,x);
k++;
printf("誤差=%lf",fabs(x-10));
}
return 0;
}
double func1(double x){
return (x-10)*(x+10);
}
double func2(double x){
return 2.0*x;
}