#include <stdio.h>
#include <time.h>

int recursive_fib(int n);
int nonrecursive_fib(int n);

int main(int argc, const char ** argv){
	int n;
	printf("Input a positive integer :");
	scanf("%d", &n);
	clock_t t1, t2, t3;
	t1 = clock();
	int N1 = nonrecursive_fib(n);
	t2 = clock();
	printf("fib(%2d) = %4d\n", n, N1);
	printf("Time of non-recursive function = %3.2f[sec]\n", (double)(t2-t1)/CLOCKS_PER_SEC);
	int N0 = recursive_fib(n);
	t3 = clock();
	printf("fib(%2d) = %4d\n", n, N0);
	printf("Time of recursive function = %3.2f[sec]\n", (double)(t3-t2)/CLOCKS_PER_SEC);
	return 0;
}	

int recursive_fib(int n){
	int val;
	if(n == 1 || n == 2){
		val = 1;
	}else{
		val = recursive_fib(n-1) + recursive_fib(n-2);
	}
	return val;
}

int nonrecursive_fib(int n){
	int a = 1; int b = 1; int c;
	for (int i=3; i <=n; i++){
		c = a + b;
		b = a;
		a = c;
	}
	return a;
}
