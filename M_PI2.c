#include<stdio.h>
#include<math.h>

int main(){

int n;
double S,deltaS;

printf("Input a positive number:");
scanf("%d",&n);

  S=n*0.5*sin((2*M_PI)/n);
  deltaS=M_PI-S;
  printf("正%d角形の面積S=%lf,円の面積との誤差deltaS =%lf\n",n,S,deltaS);

return 0;
}