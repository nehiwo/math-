#include<stdio.h>
#include<math.h>
int main(int arc,const char*argv[]){
int i,N;
float S=0;
printf("N=");
scanf("%d",&N);
for(i=1;i<=N;i++){
S=S+1.0/(i*i);
}
float x;
x=S-(M_PI*M_PI/6.0);
float E=fabs(x);
printf("E=%f\n",E);
return 0;
}