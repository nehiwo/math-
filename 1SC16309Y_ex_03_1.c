#include<stdio.h>
#include<math.h>
double func(double x);
int main(int arcg,const char*argv[]){
double a,b,s,EPS,ans;
printf("a=");
scanf("%lf",&a);
printf("b=");
scanf("%lf",&b);
printf("ans=");
scanf("%lf",&ans);
int i=0;
while(fabs(a-b)>EPS){
i++;
s=(a+b)/2.0;
if(func(s)==0){
printf("x[%d]=%lf\n",i,s);
break;
}
if(func(s)*func(a)<0) b=s;
else a=s;
if(i==1000) break;
printf("x[%d]=%lf\n",i,s);
printf("誤差=%f\n",fabs(s-ans));
}
if(func(s)*func(a)>0){
printf("解なし　または　範囲の設定ミス\n");
}
return 0;
}

double func(double x){
return tan(x);
}
