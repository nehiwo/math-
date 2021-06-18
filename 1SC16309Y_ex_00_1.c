#include<stdio.h>
int main(int arc,const char*argv[]){
int i,N;
int S=0;
printf("N=");
scanf("%d",&N);
for(i=1;i<=N;i++){
S=S+i;
}
printf("S=%d\n",S);
return 0;
}