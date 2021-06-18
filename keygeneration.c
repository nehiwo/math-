#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

int main(){

srand((unsigned) time(NULL));

int p,q,N,E,D;
int r,x,y,gcd,lcm;

printf("input a bigger prime number:");
scanf("%d",&p);
printf("input a smaller prime number:");
scanf("%d",&q);
N=p*q;
x=p-1;
y=q-1;

while((r=x%y)!=0){
 x=y;
 y=r;
}
gcd=y;
lcm=(p-1)*(q-1)/gcd;

int gcd1,e;

while(gcd1!=1){
 e=0;
 while(e<=1){
  e=rand()%lcm;
 }
 x=e;
 y=lcm;
 while((r=x%y)!=0){
  x=y;
  y=r;
 }
 gcd1=y;
}
E=e;

int x1=1;
int y1=0;
int z1=lcm;
int x2=0;
int y2=1;
int z2=E; 
while(z2!=0){
  int q=z1/z2;
  int x3=x1-q*x2;
  int y3=y1-q*y2;
  int z3=z1-q*z2;
  x1=x2;
  y1=y2;
  z1=z2;
  x2=x3;
  y2=y3;
  z2=z3;
}if(y1<=0){
  printf("retry\n");
  char program[] = "./keygeneration.out";
  int result;
  result = system(program);
}else{
  D=y1;
  printf("publickey=%d\n angoukey=%d\n hukugoukey=%d\n",N,E,D);
}

return 0;
}