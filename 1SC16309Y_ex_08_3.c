//Runge-Kutta_method
#include <stdio.h>
#include <math.h>

double f(double t, double x);

int main(void)
{
  double t=0.0,x=1.0,b=1.0,h,k1,k2,k3,k4; /*初期値はx=a=0なのでaの入力は不必要*/
  double exact;
  int i, n;

  printf("分割数を入力してください--->\n");
  scanf("%d",&n);
  h = (b-t)/n;

  for ( i = 0 ; i < n ; i++)
    {
      k1 = f(t, x); 
      k2 = f(t + 0.5*h, x + 0.5*h*k1);
      k3 = f(t + 0.5*h, x + 0.5*h*k2);
      k4 = f(t + h, x + h*k3);
      x = x + h/6.0 * ( k1 + 2*k2 +2*k3 + k4 );
      t += h;
      exact = 2.0*exp(t)-t-1.0;
      printf("t=%f \t x=%f \t exact=%f \t err=%f \n", t, x, exact, fabs(exact-x));
    }

  return 0;
}

double f(double t, double x)
{
  return( t + x );
}
