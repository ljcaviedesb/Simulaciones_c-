#include <iostream>
#include <cmath>

double f(double alpha, double x, double t){
  return cos(alpha*t-x*sin(t));
}

const double ErrMAx = 1e-7;

double IntegralPorSimpson(double alpha, double x, double a, double b, int n){
  double t,h,suma; int i;
  n*=2;
  h = (b-a)/n;
  suma=0;
  for( i=0; i<=n; i++){
    t = a + i*h;
    if(i==0 || i==n)
      suma += f(alpha, x, t);
    else if (i%2==0)
      suma+=2*f(alpha, x,t);
    else
      suma+=4*f(alpha, x, t);
  }
  return suma*h/3;
}

double Bessel (double alpha, double x){
  double a=0, b=M_PI; int n=50;
  return 1.0/M_PI*IntegralPorSimpson(alpha, x,a,b,n);
}

int main(){
  double alpha, x;
  alpha =0;
  for(x=0; x<=10;x+=0.1)
    std::cout<<x<<" "<<Bessel(alpha,x)<<std::endl;
}
