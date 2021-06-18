#include<stdio.h>

int main(int argc,const char*argv[]){

 float S = 0.0;
 int N;
 printf("Input a positive integer:");
 scanf("%d",&N);
 for(int i=1;i<=N;i++){
  S=S+1.0F/(i*i);
 }
 printf("S(%d)=%f\n",N,S);
 return 0;
}