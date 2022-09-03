#include <iostream>
#include <cmath>
#include "../vector.h"
/////////////////////////////////////////////////////////////////
// Dos planetas                                                //
//                                                             //
// En este programa se simula el movimiento ente dos planetas  //
// con un observador ajeno al sistema, a este último se le     //
// llama colisionador o interaccionador.                       //
/////////////////////////////////////////////////////////////////
const double G=1.0;
// Tenemos dos planetas
const int N=2; // Nos permitirá cerar un arreglo de dos planetas

// constantes globales
// Coeficientes de PEFRL
const double Zeta   = 0.1786178958448091e00;
const double Lambda = -0.2123418310626054e00;
const double Chi    = -0.6626458266981849e-1;
const double Coeficiente1 =(1-2*Lambda)/2;
const double Coeficiente2 =1-2*(Chi+Lambda);

// Clases
class Cuerpo;
class Colisionador;
//------------------ Clase Cuerpo ------------------------------//
class Cuerpo{
private:
  vector3D r, V, F;
  double m,R;
public:
  void Inicie(double x0,double y0,double z0, double Vx0, double Vy0, double Vz0,double m0,double R0);
  void BorreFuerza(void);
  void SumeFuerza(vector3D F0);
  void Mueva_r(double dt, double coeficiente);
  void Mueva_v(double dt, double coeficiente);
  double Getx(void){return r.x();}; //Inline
  double Gety(void){return r.y();}; //Inline
  double Getz(void){return r.z();}; //Inline
  friend class Colisionador; //Cualquier especimen de la clase colisionador le puede meter la mano a la clase cuerpo
};
void Cuerpo::Inicie(double x0,double y0,double z0, double Vx0, double Vy0, double Vz0,double m0,double R0){
  r.load(x0,y0,z0);
  V.load(Vx0,Vy0,Vz0);
  m=m0; R=R0;
}
void Cuerpo::BorreFuerza(void){
  F.load(0,0,0);
}
void Cuerpo::SumeFuerza(vector3D F0){
  F+=F0;
}
void Cuerpo::Mueva_r(double dt,double coeficiente){
  vector3D r_new;
  r+=V*dt*coeficiente;
} 
void Cuerpo::Mueva_v(double dt,double coeficiente){
  vector3D r_new;
  V+=F*dt*coeficiente/m;
}
//------------------ Class Colisionador ------------------------//
class Colisionador{
private:
public:
  void CalculeFuerza(Cuerpo * Planeta);
  void CalculeFuerzaEntre(Cuerpo &  Planeta1, Cuerpo & Planeta2);
};
void Colisionador::CalculeFuerza(Cuerpo * Planeta){
  int i,j;
  for(i=0;i<N;i++)
    Planeta[i].BorreFuerza();
  for(i=0;i<N;i++)
    for(j=i+1;j<N;j++)
      CalculeFuerzaEntre(Planeta[i],Planeta[j]);
}
void Colisionador::CalculeFuerzaEntre(Cuerpo & Planeta1, Cuerpo &Planeta2){
  vector3D r21,n,F1; double d21,F;
  r21 = Planeta2.r - Planeta1.r; d21=r21.norm(); n=r21/d21;
  F = G*Planeta1.m*Planeta2.m*pow(d21,-2.0);
  F1=F*n;
  Planeta1.SumeFuerza(F1); Planeta2.SumeFuerza(F1*(-1));
}
//------------------ main --------------------------------------//
int main(){
  Cuerpo Planeta[N];
  Colisionador Newton;
  double m1=10, m2=1, r=11;
  double M=m1+m2, x1=-m2*r/M, x2=m1*r/M;
  double omega = sqrt(G*m2/pow(r,3.0)), T=2*M_PI/omega, V1=omega*x1, V2=omega*x2;
  double t, dt=0.01;
  int i;

  Planeta[0].Inicie(x1,0,0,0,V1,0,m1,1.0);
  Planeta[1].Inicie(x2,0,0,0,V2,0,m2,0.5);

  for(t=0;t<1.1*T; t+=dt)
    {
      std::cout<<Planeta[1].Getx()<<" "<<Planeta[1].Gety()<<std::endl;
      // Haga el movimiento y los calculos por PEFRL
      for(i=0;i<N;i++) Planeta[i].Mueva_r(dt, Zeta);            // 1 
      Newton.CalculeFuerza(Planeta);
      for(i=0;i<N;i++) Planeta[i].Mueva_v(dt,Coeficiente1);     // 2
      for(i=0;i<N;i++) Planeta[i].Mueva_r(dt, Chi);             // 3
      Newton.CalculeFuerza(Planeta);     
      for(i=0;i<N;i++) Planeta[i].Mueva_v(dt,Lambda);           // 4
      for(i=0;i<N;i++) Planeta[i].Mueva_r(dt,Coeficiente2); // 5
      Newton.CalculeFuerza(Planeta);     
      for(i=0;i<N;i++) Planeta[i].Mueva_v(dt,Lambda);           // 4
      for(i=0;i<N;i++) Planeta[i].Mueva_r(dt, Chi);      // 3
      Newton.CalculeFuerza(Planeta);
      for(i=0;i<N;i++) Planeta[i].Mueva_v(dt,Coeficiente1);            // 2
      for(i=0;i<N;i++) Planeta[i].Mueva_r(dt, Zeta);         // 1
    }
  
  return 0;
}
