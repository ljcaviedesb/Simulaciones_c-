#include <iostream>
#include <cmath>
using namespace std;
const double g=9.8;
// Realizaremos una clase
class Cuerpo;
class Cuerpo{
private:
    double x,y,Vx,Vy,Fx,Fy,m,R;
public:
    void Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0);
    void CalcularFuerza(void);
    void Muevase(double dt);
    double Getx(void){return x;}; // FUNCION INLINE
    double Gety(void){return y;};
}; // Siempre se debe poner el ; cuando se hace una clase

void Cuerpo::Inicie(double x0,double y0,double Vx0,double Vy0,double m0,double R0){
    x=x0; y=y0; Vx=Vx0; Vy=Vy0; m=m0; R=R0;
}
void Cuerpo::CalcularFuerza(void){
    Fx=0; Fy=m*g;
}
void Cuerpo::Muevase(double dt){
    x+=Vx*dt;           y+=Vy*dt;
    Vx+=(Fx/m)*dt;      Vy+=(Fy/m)*dt;
}
int main(){
    Cuerpo Balon; //Ejemplar (Instance) de la clase cuerpo 
    double t,dt=0.1;
    Balon.Inicie(0,0,4,3,0.453,0.15);
    for (t=0; t<=3;t+=dt){
        cout<<Balon.Getx()<<" "<<Balon.Gety()<<endl;
        Balon.CalcularFuerza();
        Balon.Muevase(dt);
    }
    
    return 0;
}