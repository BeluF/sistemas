#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>

//ios::app nos permite ir a la última línea del archivo para añadir cosas.

using namespace std;

double funcion_cuadratica(int &nu, double a, double b, double c);

int main(int argc, int *argv[]){
    double a,b,c,y;
    int x;

    ofstream file;
    file.open ("./ej1.txt",ios::app);

    if (file.fail()) cout<<"Error en la apertura del archivo";
    else {
        cout<<"Ecuación cuadratica: y = ax^2 + bx + c\nIngrese valores de a, b y c: ";
        cin>>a>>b>>c;
        do {
            cout<<"\n Ingrese X [Valores enteros entre 1 y 1000 | Ingrese 0 para salir]: "; cin>>x;
            if ((x>0)&&(x<1001)){
                y= funcion_cuadratica(x,a,b,c);
                file<<x<<" "<<y<<endl;
            }
            else cout<<"\n Número ingresado incorrecto.";
        } while (x>0);
    }
    file.close();
    return 0;
}


double funcion_cuadratica(int &nu, double a, double b, double c){
    double y=(a*nu*nu)+(b*nu)+c;
    return y;
}