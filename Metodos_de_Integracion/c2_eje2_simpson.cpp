#include <iostream>
#include <cmath>

double f(double x){
  return cos(x);
}

const double ErrMAx = 1e-7;

double IntegralPorSimpson(double a, double b, int n){
  double x,h,suma; int i;
  n*=2;
  h = (b-a)/n;
  suma=0;
  for( i=0; i<=n; i++){
    x = a + i*h;
    if(i==0 || i==n)
	suma += f(x);
    else if (i%2==0)
      suma+=2*f(x);
    else
      suma+=4*f(x);
  }
  return suma*h/3;
}

int main(){
  double a=0, b=M_PI/2;
  int n =50;

  std::cout<<"La integral calculada por Simpson es "<<IntegralPorSimpson(a,b,n)<<std::endl;
}
