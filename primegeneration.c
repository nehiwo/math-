#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(void){

 int c,n,p,flag=0;

 srand((unsigned)time(NULL));
 
 printf("何桁の素数を生成しますか？\n");
 scanf("%d",&n);
 c=pow(10,n);
 
 while(flag==0){
  
  p=rand()%c;
  
  int a,i;
  for(i=2;i<=sqrt(p);i++){
    a=p%i;
   if(a==0){
    flag=0;
    break;
   }
   flag=1;
  }
 }
 printf("素数 %d\n",p);
 return 0;
}