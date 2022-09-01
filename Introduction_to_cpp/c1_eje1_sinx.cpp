#include <iostream>
#include <cmath>

double f(double x){
  return sin(x)/x;
}

int main(){
  double x;
  for(x=0.1; x<10; x+=0.1)
    std::cout<<x<<" "<<f(x)<<std::endl;
  return 0;
}
