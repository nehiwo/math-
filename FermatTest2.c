#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(void){

int N,a,i,flag=1,TmodN;
int j=1.0;
double c;
long int T=1.0;
long int b;//データの保管
srand((unsigned)time(NULL));

printf("Input a positive number:\n");
scanf("%d",&N);

if(N==2){
printf("%d is a prime number.\n",N);
}else if(N==1){
printf("%d is a 1.\n",N);
}else{
 while(flag==1){
  for(a=2;a<=(N-1)/2;a++){
   j=j+1,0;
   T=1.0;
   for(i=1;i<=N-1;i++){
    T=T*a;
    b=T%N;
    if(T>N){
     T=b;
     TmodN=T%N;
    }else{
     TmodN=b;
    }
   }
   printf("TmodN=%d. a=%d.\n",TmodN,j);
   if(TmodN!=1){
    flag=0;
    break;
   }
   flag=1;
  }
  if(j==(N-1)/2) break;
 }
 if(TmodN!=1){
  printf("%d is a composite number.\n",N);
  return 0;
 }else{
  printf("%d is a prime number.\n",N);
  return 1;
 }
}
}