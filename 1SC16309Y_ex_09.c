//Runge-Kutta_method
#include<stdio.h>
#include<math.h>

double f(double t, double x, double y);
double g(double t, double x, double y);

int main(void){
double t=0.0,x=1.0,y=1.0,h,k1[2],k2[2],k3[2],k4[2];
int i,n;

printf("分割数を入力してください--->\n");
scanf("%d",&n);
h=1.0/n;

for(i=0;i<n;i++){

k1[0]=f(t,x,y);
k1[1]=g(t,x,y);

k2[0]=f(t+h/2.0,x+k1[0]/2.0,y+k1[1]/2.0);
k2[1]=g(t+h/2.0,x+k1[0]/2.0,y+k1[1]/2.0);

k3[0]=f(t+h/2.0,x+k2[0]/2.0,y+k2[1]/2.0);
k3[1]=g(t+h/2.0,x+k1[0]/2.0,y+k1[1]/2.0);

k4[0]=f(t+h,x+k3[0],y+k3[1]);
k4[1]=g(t+h,x+k3[0],y+k3[1]);

x=x+(h*(k1[0]+2.0*k2[0]+2.0*k3[0]+k4[0]))/6.0;
y=y+(h*(k1[1]+2.0*k2[1]+2.0*k3[1]+k4[1]))/6.0;

t+=h;

printf("t=%f \t x=%f \t y=%f \n",t,x,y);
}
return 0;
}

double f(double t, double x, double y){
return x-x*x-1.5*x*y;
}

double g(double t, double x, double y){
return y-y*y-1.5*x*y;
}