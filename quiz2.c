#include <stdio.h>
#include <math.h>

#define EOS 1.0e-8

int main (int argc, const char * argv[]){
	double x, prev_x, new_x;
	int k;
	printf("Input a positive real number:");
	scanf("%lf", &x);		
	if(x < 0){
		printf("Should input a positive real number\n");
	}else{
		prev_x = -x;
		new_x = x;
		k = 0;
		while(fabs(prev_x - new_x) > EOS){
			prev_x = new_x;
			new_x = 0.5 * (prev_x + x / prev_x);
			k = k + 1;
			if(k > 100){
				break;
			}
		}
		if(k > 100){
			printf("Approximation of square root of %f = %f\n", x, newx);
		}else{
			printf("Ssquare root of %f = %f\n", x, newx);
		}
	}
	return 0;
}
