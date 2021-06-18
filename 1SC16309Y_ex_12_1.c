#include<stdio.h>
#include<math.h>

int main(int argc,const char**argv){

double u[101],du[101];
int i;
double x,t,dx=0.1,dt=0.001;
FILE*wave_equation;

wave_equation=fopen("wave_equation.txt","w");

//初期条件
for(i=0;i<=100;i++){
x=0.01*i;
u[i]=sin(M_PI*x);
}

//境界条件
u[0]=0;
u[100]=0;

//波動方程式の解の計算
for(t=0;t<=0.1;t=t+dt){
for(i=0;i<=99;i++){
du[i]=((u[i+1]-2.0*u[i]+u[i-1])/(dx*dx))*dt;
}
for(i=0;i<=99;i++){
u[i]=u[i]+du[i];
}
}

//解の出力
for(i=0;i<=100;i++){
printf("%1f\n",u[i]);
fprintf(wave_equation,"%1f\n",u[i]);
}

fclose(wave_equation);
return 0;
}