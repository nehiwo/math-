#include<stdio.h>
#include<math.h>

int main(int argc,const char**argv){

double u[101],du[101];
int i;
double x,t,dx=0.1,dt=0.0001;
FILE*diffusion_equation;

diffusion_equation=fopen("diffusion_equation.txt","w");

//初期条件
for(i=0;i<=100;i++){
x=0.01*i;
u[i]=sin(M_PI*x);
}

//境界条件
u[0]=0;
u[100]=0;

//拡散方程式の解の計算
for(t=0;t<=0.1;t=t+dt){
for(i=1;i<=99;i++){
du[i]=((u[i+1]-u[i])/dx)*dt;
}
for(i=1;i<=99;i++){
u[i]=u[i]+du[i];
}
}

//解の出力
for(i=0;i<=100;i++){
printf("%lf\n",u[i]);
fprintf(diffusion_equation,"%lf\n",u[i]);
}

fclose(diffusion_equation);
return 0;
}