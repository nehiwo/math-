# include <stdio.h>
# include <math.h>

int main(int argc, const char ** argv){
    double u[101], du[101];
    int i;
    double x,t,dt=0.00001,dx=0.01;
    
    FILE *output3;
    output3=fopen("output3.text","w");
    
    for (i=0; i<=100; i++){
        x=0.01*i;
        u[i]=sin(M_PI*x);
    }
    
    u[0]=0; u[100]=0;
    
    for (t=0; t<=0; t=t+dt){
        for (i=1; i<=99; i++){
            du[i]=((u[i+1]-u[i])/dx)*dt;
        }
        for (i=1; i<=99; i++){
            u[i]=u[i]+du[i];
        }
        
    }
    for (i=0; i<=100; i++){
        printf("%lf\n", u[i]);
        fprintf(output3,"%lf\n",u[i]);
    }
    fclose(output3);
    return 0;
}

