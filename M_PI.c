#include<stdio.h>
#include<math.h>

int main(){

int n,i;
double S,deltaS;

printf("Input a positive number:");
scanf("%d",&n);

for(i=3;i<=n;i++){
  S=i*0.5*sin((2*M_PI)/i);
  deltaS=M_PI-S;
  printf("正%d角形の面積S=%lf,円の面積との誤差deltaS =%lf\n",i,S,deltaS);
}
return 0;
}