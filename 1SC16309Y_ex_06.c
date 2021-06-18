#include<stdio.h>
int main(void){
double a1,a2,a3,b1,b2,b3,c1,c2,c3;
double x1,x2,x3;

printf("１つ目の式の係数を入力してください\n");
scanf("%lf %lf %lf %lf",&a1, &b1, &c1, &x1);
printf("2つ目の式の係数を入力してください\n");
scanf("%lf %lf %lf %lf",&a2, &b2, &c2, &x2);
printf("3つ目の式の係数を入力してください\n");
scanf("%lf %lf %lf %lf",&a3, &b3, &c3, &x3);

double A[3][3]={
{a1,b1,c1},
{a2,b2,c2},
{a3,b3,c3}
};
double x[3]={x1,x2,x3};

double detA=A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])-A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])+A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
double detA1=x[0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])-x[1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])+x[2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
double detA2=A[0][0]*(x[1]*A[2][2]-x[2]*A[2][1])-A[0][1]*(x[0]*A[2][2]-x[2]*A[2][0])+A[0][2]*(x[0]*A[2][1]-x[1]*A[2][0]);
double detA3=A[0][0]*(A[1][1]*x[2]-A[1][2]*x[1])-A[0][1]*(A[1][0]*x[2]-A[1][2]*x[0])+A[0][2]*(A[1][0]*x[1]-A[1][1]*x[0]);

double ans1=detA1/detA, ans2=detA2/detA, ans3=detA3/detA;

printf("x1=%lf, x2=%lf, x3=%lf\n",ans1, ans2, ans3);
return 0;
}