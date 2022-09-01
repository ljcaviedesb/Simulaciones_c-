#include <iostream>
#include <cmath>
#include "../vector.h"

const double GM = 1.0; // (Constante gravitacional)*(Masa del sol)
// Coeficientes de PEFRL
const double Zeta   = 0.1786178958448091e00;
const double Lambda = -0.2123418310626054e00;
const double Chi    = -0.6626458266981849e-1;

const double Coeficiente1 =(1-2*Lambda)/2;
const double Coeficiente2 =1-2*(Chi+Lambda);

// Declaracion de clases
class Cuerpo;

class Cuerpo{
private:
  vector3D r, V, F;
  double m,R;
public:
  void Inicie(double x0,double y0,double z0, double Vx0, double Vy0, double Vz0,double m0,double R0);
  void CalculeFuerza(void);
  void Mueva_r(double dt, double coeficiente);
  void Mueva_v(double dt, double coeficiente);
  double Getx(void){return r.x();}; //Inline
  double Gety(void){return r.y();}; //Inline
  double Getz(void){return r.z();}; //Inline
};
void Cuerpo::Inicie(double x0,double y0,double z0, double Vx0, double Vy0, double Vz0,double m0,double R0){
  r.load(x0,y0,z0);
  V.load(Vx0,Vy0,Vz0);
  m=m0; R=R0;
}
void Cuerpo::CalculeFuerza(void){
  double aux = GM*m*pow(r.norm2(),-1/5);
  F=-aux*r;
}
void Cuerpo::Mueva_r(double dt,double coeficiente){
  vector3D r_new;
  r+=V*dt*coeficiente;
} 
void Cuerpo::Mueva_v(double dt,double coeficiente){
  vector3D r_new;
  V+=F*dt*coeficiente/m;
}

int main(void){
  Cuerpo Planeta;
  double r0=10, m0=1;
  double omega, V0, T;
  double t, dt=0.001;
  
  omega= sqrt(GM/(pow(r0,3))); V0=omega*r0; T=2*M_PI/omega;
  Planeta.Inicie(r0,0,0,0,V0/2,0,m0,0.5);
  for(t=0;t<1.1*T; t+=dt)
    {
      std::cout<<Planeta.Getx()<<" "<<Planeta.Gety()<<std::endl;
      // Haga el movimiento y los calculos por PEFRL
      Planeta.Mueva_r(dt, Zeta);            // 1
      Planeta.CalculeFuerza();
      Planeta.Mueva_v(dt,1-2*Lambda);     // 2
      Planeta.Mueva_r(dt, Chi);             // 3
      Planeta.CalculeFuerza();     
      Planeta.Mueva_v(dt,Lambda);           // 4
      Planeta.Mueva_r(dt,(1-2*(Chi+Zeta))); // 5
      Planeta.Mueva_v(dt,Lambda);           // 4
      Planeta.Mueva_r(dt, Chi);      // 3
      Planeta.CalculeFuerza();
      Planeta.Mueva_v(dt,1-2*Lambda);            // 2
      Planeta.Mueva_r(dt, Zeta);         // 1
    }
  
  return 0;
}
