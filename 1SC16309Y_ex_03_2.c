#include<stdio.h>
#include<math.h>
double func1(double x);
double func2(double x);
int main(int argc,const char*argv[]){
double x;
double EPS,ans;
int i=1;
printf("x=");
scanf("%lf",&x);
printf("ans=");
scanf("%lf",&ans);
while(fabs(func1(x))>EPS){
i++;
x=x-(func1(x)/func2(x));
if(i==1000) break;
printf("x[%d]=%lf\n",i,x);
printf("誤差=%lf\n",fabs(x-ans));
}
return 0;
}
double func1(double x){
return tan(x);
}
double func2(double x){
return 1.0/(cos(x)*cos(x));
}