//heun_method
#include <stdio.h>
#include <math.h>

double f(double t, double x);

int main(void)
{
  double t=0.0,x=1.0,b=1.0,h,k1,k2; /*初期値はt=a=0なのでaの入力は不必要*/
  double exact;
  int i, n;

  printf("分割数を入力してください--->\n");
  scanf("%d",&n);
  h = (b-t)/n;

  for ( i = 0 ; i < n ; i++)
    {
      k1 = f(t,x); k2 = f(t+h, x+h*k1);
      x = x + h/2.0 * ( k1 + k2 );
      t += h;
      exact = 2.0*exp(t)-t-1.0;
      printf("t=%f  x=%f  exact=%f  err=%20.16f \n", t, x, exact, exact-x);
    }

  return 0;
}

double f(double t, double x)
{
  return( t + x );
}