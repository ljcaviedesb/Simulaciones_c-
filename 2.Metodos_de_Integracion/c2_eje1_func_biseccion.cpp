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

double CerosPorBiseccion(double a, double b){
  double x;
  double  m, fa, fm;
  fa = f(a);
  while (b-a>ErrMax){
    m= (a+b)/2;
    fm = f(m);
    if(fa*fm>0){
      a = m;   // correr a hastam
      fa=fm;
    }
    else
      b = m; // Correr b hasta m
  }
  return (a+b)/2;
}

int main(){

  double x;
  double a=2, b=4;
  auto start = high_resolution_clock::now();
  std::cout<<"Ell cero es  "<<CerosPorBiseccion(a,b)<<std::endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop-start);
  std::cout<<"time: "<<duration.count()<<std::endl;
  return 0;
}
