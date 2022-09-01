#include <iostream>
#include <cmath>
/////////////////////////////////////////////////////////////////////////
//                            RungeKutta 4                             //
// Basandonos en el método de Euler, RunngeKutta elimina loes errores  //
// hasta el quinto orden calculando cuatro dx.                         //
//                                                                     //
// Los valores iniciales son f(t,x), t0, x0.                           //
/////////////////////////////////////////////////////////////////////////

// Funcion
double f(double t, double x){
  return t;
}
// Runge Kutta 4
void UnPasoDeRungeKutta4(double &t, double &x, double dt){
  double dx1, dx2, dx3, dx4;
  double dx;
  dx1= dt*f(t,x);
  dx2= dt*f(t+dt/2, x+dx1/2);
  dx3= dt*f(t+dt/2, x+dx2/2);
  dx4= dt*f(t+dt/2, x+dx3);
  dx = (dx1 +2*dx2 +2*dx3 + dx4)/6;
  x+=dx; t+=dt;
}
// main
int main(){
  double t,x; double dt=0.01;
  for(t=0,x=0; t<2; ){
    std::cout<<t<<" "<<x<<" "<<std::endl;
    UnPasoDeRungeKutta4(t,x,dt);
  }
  
  return 0;
}
  
