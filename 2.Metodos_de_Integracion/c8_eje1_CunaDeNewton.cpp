#include <iostream>
#include <cmath>
#include "vector.h"

// Declaración de clases
Class Cuerpo;
class Colisionador;

// -----------------Clase Cuerpo --------------------
class Cuerpo{
private:
  double theta, omega,tau;
  double m,R,m,l,x0;
public:
  void Inicie(doble theta0, double omega0, double m0, double R0, double l0, double x0);
  void BorreTorque(void);
  void SumeTorque(vector3D F0);
  void Mueva_theta(double dt, double coeficiente);
  void Mueva_omega(double dt, double coeficiente);
  double Getx(void){return x0+l*sin(theta);}; //Inline
  double Gety(void){return -l*cos(theta);}; //Inline
  double Gettau(void){return tau;};  
