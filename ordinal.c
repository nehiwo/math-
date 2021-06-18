#include<stdio.h>
int main(int argc,const char*argv[]){
  int x,y;
    printf("Input a positive intenger:");
  scanf("%d",&x);
  y=x%10;
  if(y==1){
    if(x==11){
      printf("%d th",x);
    }else{
      printf("%d st",x);
    }
  }
  else if(y==2){
    if(x==12){
      printf("%d th",x);
    }else{
      printf("%d nd",x);
    }
  }
  else if(y==3){
    printf("%d rd",x);
  }
  else{
    printf("%d th",x);
  }
  return 0;
}
