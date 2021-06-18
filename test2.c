#include<stdio.h>

int main(){
    
    int n = 8;
    int i;
    double sx[n],sy[n],kx[n],ky[n];
    for(i=0;i<n;i++){
        scanf("%lf %lf %lf %lf",&sx[i],&sy[i],&kx[i],&ky[i]);
    }
    double mind1=100.0,mind2=100.0;
    double d1,d2;
    for(i=0;i<n;i++){
        d1=sx[i]*sx[i]+sy[i]*sy[i];
        d2=kx[i]*kx[i]+ky[i]*ky[i];
        if(mind1>d1) mind1=d1;
        if(mind2>d2) mind2=d2;
    }
    printf("%lf %lf\n",mind1,mind2);
    if(mind1==100.0 && mind2==100.0) printf("0 0\n");
    int counta=0;
    if(mind1>mind2){
        for(i=0;i<n;i++){
            d2=kx[i]*kx[i]+ky[i]*ky[i];
            if(mind1>d2) counta++;
        }
        printf("0 %d\n",counta);
    }
    if(mind2>mind1){
        for(i=0;i<n;i++){
            d1=sx[i]*sx[i]+sy[i]*sy[i];
            if(mind2>d1) counta++;
        }
        printf("%d 0\n",counta);
    }
    return 0;
}
