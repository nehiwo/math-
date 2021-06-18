#include<stdio.h>
#include<math.h>
float func(float x);
int main(int argc,const char*argv[]){
int k,a;
float b;
for(k=0;k<=14;k++){
b=0;
for(a=1;a<pow(2.0,k);a++){
b+=func(a/pow(2.0,k));
}
printf("%lf\n",fabs((1/pow(2.0,k+1))*(2.0*b+func(0)+func(1))-(M_PI)/4.0));
}
return 0;
}
float func(float x){
return 1.0/(1.0+x*x);
}