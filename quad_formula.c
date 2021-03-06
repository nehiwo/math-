#include<stdio.h>
#include<math.h>

int main(int argc,const char*argv[]){
    float a = 0.0;
    float b = 0.0;
    float c = 0.0;
    float D = 0.0;
    float x1 = 0.0;
    float x2 = 0.0;
    float real = 0.0;
    float imag = 0.0;
    printf("a=");
    scanf("%f",&a);
    printf("b=");
    scanf("%f",&b);
    printf("c=");
    scanf("%f",&c);
    if(a == 0){
        if(b == 0){
            printf("解なし\n");
        }else{
            x1 = x2 = -c / b;
            printf("解x=%.2f\n",x1);
        }
    }else{
        D = b * b - 4 * a * c;
        if(D > 0){
            x1 = (-b + sqrt(D)) / (2 * a);
            x2 = (-b - sqrt(D)) / (2 * a);
            printf("解x=%.2f,%.2f\n",x1,x2);
        }else if(D == 0){
            x1 = x2 = (-b) / (2 * a);
            printf("解x=%.2f\n",x1);
        }else{
            real = (-b) / (2 * a);
            imag = sqrt(-D) / (2 * a);
            printf("解x=%.2f+%.2fi,%.2f-%.2fi\n",real,imag,real,imag);
        }
    }
    return 0;
}
