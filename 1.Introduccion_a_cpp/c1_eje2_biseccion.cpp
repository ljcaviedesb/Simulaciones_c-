#include <iostream>
#include <cmath>
#include <chrono>
using namespace std::chrono;
// Metodo de la Bissecion
// Este metodo es utilizado para encontrar las raices de una funcion

double f(double x){
  return sin(x)/x;
}

// Definimos un error aceptable. El metodo de la biseccion busca puntos tales que f(a) y f(b) sean de signo contrario con a-b<<1
const double ErrMax=1e-7;

int main(){

  double x;
  double a=2, b=4, m, fa, fm;
  auto start = high_resolution_clock::now();
  // Mientrs que el intervalo sea mas grande que el que yo quiero: redizca el intervalo a la mitad
  fa = f(a);
  while (b-a>ErrMax){
    m= (a+b)/2;
    fm = f(m);
    if(fa*fm>0){
      a = m;
      fa=fm;
    }
    else
      b = m;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop -  start);
  std::cout<<"time: "<<duration.count()<<std::endl;
  std::cout<<"Ell cero es  "<<(a+b)/2<<std::endl;

  return 0;
}
