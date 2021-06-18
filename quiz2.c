#include <stdio.h>
#include <math.h>

int main (int argc, const char * argv[]){
	double x, prevx, newx;
	int k;
	printf("Input a positive real number:");
	scanf("%lf", &x);		
	if(x < 0){
		printf("Should input a positive real number\n");
	}else{
		prevx = -x;
		newx = x;
		k = 0;
		while(fabs(prevx - newx) > 1.0e-8){
			prevx = newx;
			newx = 0.5*(prevx+ x/prevx);
			//System.out.println(k+" : val = "+newx);
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
