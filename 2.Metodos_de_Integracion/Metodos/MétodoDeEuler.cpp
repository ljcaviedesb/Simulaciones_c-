#include <iostream>
#include <cmath>
//////////////////////////////////////////////////////////
//                  Método de Euler                     //
// Este método consiste en utilizar la fución derivada  //
// la cual es la que nos da la pendinte en cada punto   //
// de la gráfica, y utilizarla para encontrar la altura //
// de esta.                                             //
//                                                      //
// Datos iniciales: f(t,x)=dx/dt y t.                    //
//////////////////////////////////////////////////////////

// Fución derivada
double f(double t, double x){
  return x;
}
// Euler
void UnPasoDeEuler(double &t, double &x, double dt){
  double dx;
  dx = dt*f(t,x);
  x+=dx; t+=dt;
}
// main
int main(){
  double t,x; double dt=0.0001;
  for(t=0,x=1; t<=2;){
    std::cout<<t<<" "<<x<<" "<<exp(t)<<std::endl;
    UnPasoDeEuler(t,x,dt);
  }  
  
  return 0;
}

