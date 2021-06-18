#include<stdio.h>
#include<math.h>
float func(float x);
int main(int arcg,const char*argv[]){
int k,a;
float b,c;
for(k=0;k<=14;k++){
b=0;
for(a=0;a<pow(2.0,k-1);a++){
b+=func((2.0*a)/(pow(2.0,k)))+4.0*func((2.0*a+1)/pow(2.0,k))+func(2.0*(a+1)/pow(2.0,k));
}
c=pow(2.0,k);
printf("%lf\n",fabs((b/(3*c)-((M_PI)/4.0))));
}
}
float func(float x){
return 1.0/(1.0+x*x);
}