#include <iostream>
#include <cmath>
///////////////////////////////////////////////////////////////////////
//             RungeKutta 4 para ecuaciones Acopladas                //
//                                                                   //
// Para una ecuacion de segundo orden tenemos la siguiente forma:    //
//                  x" + B(t,x)x' + C(t,x) = 0                       //
// Escogemos dos funcoines x_i tal que estas sean acopladas:         //
//                    x1 = x',     x2 = x                            //
// Con esto en mente, despejando x" de la ecuación principal podemos //
// saber las derivadas de x1 y x2:                                   //
//          x1' = x" = -B(t, x2=x)x1 - C(t, x2) = f1(t,x1,x2),       //
//          x2'=x1=f2(t,x1,x2)                                       //
///////////////////////////////////////////////////////////////////////

// Vamos a utilizar la ecuacion de onda x" + w²x = 0
const double omega = 3.0;

// Funciones
double f1(double t, double x1, double x2){
  return -omega*omega*x2;
}
double f2(double t, double x1, double x2){
  return x1;
}

// RungeKutta
void UnPasoRK4_ecAcp(double &t0, double &x10, double &x20, double dt){
  double dx11, dx12, dx13, dx14;                double dx21, dx22, dx23, dx24;
  
  dx11 = dt*f1(t0,x10,x20);                      dx21 = dt*f2(t0,x10,x20);
  dx12 = dt*f1(t0+dt/2, x10+dx11/2, x20+dx21/2); dx22 = dt*f2(t0+dt/2, x10+dx11/2, x20+dx21/2);
  dx13 = dt*f1(t0+dt/2, x10+dx12/2, x20+dx22/2); dx23 = dt*f2(t0+dt/2, x10+dx12/2, x20+dx22/2);
  dx14 = dt*f1(t0+dt/2, x10+dx13  , x20+dx23  ); dx24 = dt*f2(t0+dt/2, x10+dx13  , x20+dx23  );

  x10+= (dx11+2*dx12+2*dx13+dx14)/6;             x20+= (dx21+2*dx22+2*dx23+dx24)/6;
  t0+=dt;
}

// main
int main(void){
  double t,x1,x2; double dt=0.001;
  for(x1=1,x2=0,t=0; t<7; ){
    std::cout<<t<<" "<<x2<<std::endl;
    UnPasoRK4_ecAcp(t,x1,x2,dt);
  }
  return 0;
}
