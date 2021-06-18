#include <stdio.h>

int main (int argc, const char * argv[]){
	int N;
	printf("Input positive integer:");
	scanf("%d", &N);		
	if (N % 3 == 0 && N % 5 ==0){
		printf("FizzBuzz\n");
	}else if(N % 3 == 0){
		printf("Fizz\n");
	}else if(N % 5 == 0){
		printf("Buzz\n");
	}else{
		printf("%d\n", N);
	}
	return 0;
}
