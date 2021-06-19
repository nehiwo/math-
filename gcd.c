#include <stdio.h>
#include <stdlib.h>

int recursive_gcd(int a, int b);
int nonrecursive_gcd(int a, int b);

int main(int argc, const char ** argv){
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	printf("(a, b) = (%d, %d)\n", a, b);
	
    int N1 = nonrecursive_gcd(a, b);
	printf("gcd(%d, %d) = %4d\n", a, b, N1);
	
    int N0 = recursive_gcd(a, b);
	printf("gcd(%d, %d) = %4d\n", a, b, N0);
	
    return 0;
}

int recursive_gcd(int a, int b){
    int r = a % b;
    if(b == 0){
        recursive_gcd(a, b) = a;
    }else{
        recursive_gcd(a, b) = recursive_gcd(b, r);
    }
}

int nonrecursive_gcd(int a, int b){
  int a = 0, b = 0, r = 0, tmp = 0;
 
  printf("2つの自然数を入力してください。\n");
  printf("1つ目の自然数 = ");
  scanf("%d", &a);
  printf("2つ目の自然数 = ");
  scanf("%d", &b);
 
  /* 自然数 a > b を確認・入替 */
  if(a < b){
      tmp = a;
      a = b;
      b = tmp;
  }
 
  /* ユークリッドの互除法 */
  r = a % b;
  while(r != 0){
      a = b;
      b = r;
      r = a % b;
  }
 
  /* 最大公約数を出力 */
  printf("最大公約数 = %d\n", b);
 
  return 0;
}
