#include <iostream>
#include <stdlib.h>
using namespace std;
//ejercicio 12 practica 6
/*En n vamos a colocar el código del vino; en m=0 su precio; m=1 cantidad de botellas; m=2 cantidad de botellas vendidas; 
m=3 cantidad de compradas; m=4 monto;
m=5 auxiliar */
void cargadatos(int menu);
int aux,n=0;
const int k=500,m=4;
float vino[k][m];
	
int main(){
	int menu=0,max=0,totalvendidas=0,totalrecaudado=0;
	do{
		if (aux!=0) {
		cout<<"Cantidad de vinos ingresados hasta el momento: "<< aux<<endl;
		//contador como ayuda a ver cuantos vinos se han ingresado
		cout<<"Ultimo Cod. Vino: "<<n<<" | Precio por botella $"<<vino[n][0]<<" | Existentes: "<<vino[n][1]<<" | Vendidas: "<<vino[n][2]<<" | Compradas: "<<vino[n][3]<<" | Monto $"<<vino[n][0]*vino[n][1]<<endl;
		//^ actividad A
		for (n=0;n<=max;n++) {
			if (vino[n][2]>0) {
			totalvendidas=totalvendidas+vino[n][2];
			totalrecaudado=totalrecaudado+vino[n][4];
			}
		}
		cout<<"Cantidad total de botellas vendidas: "<<totalvendidas<<" | Total recudado $"<<totalrecaudado<<endl<<endl;}
		//^ Actividad B
		cout<<"Ingrese codigo de vino: "; cin>>n;
		if (max<n) max=n;
		if (n<9999) {
			cout<<"Ingrese precio por botella: $"; cin>>vino[n][0];
			cout<<"Tipo de movimiento"<<endl<<"1. Venta"<<endl<<"2. Compra al proveedor"<<endl;
			cin>>menu;
			if (menu==1) {
			cargadatos(menu);
			}					//en este caso se restan botellas a la existencia total
			else if (menu==2){
			cargadatos(menu);	//en este caso se sumarian botellas a la existencia total
			}
			else cout<<"Número incorrecto"<<endl;
		}
	}while (n<9999);
	return 0;
}	

//FALTA ACTIVIDAD A,B,C

void cargadatos(int menu){
			cout<<"Ingrese cantidad de botellas: "; cin>>vino[n][5];
			system("cls");
			if (menu==1) {
				vino[n][1]=vino[n][1]-vino[n][5];
				vino[n][2]=vino[n][2]+vino[n][5];
				vino[n][4]=vino[n][1]*vino[n][0]; //falta averiguar porque no está haciendo el monto
			}
			else {
				vino[n][1]=vino[n][1]+vino[n][5];
				vino[n][3]=vino[n][3]+vino[n][5];
				vino[n][4]=vino[n][1]*vino[n][0]; //falta averiguar porque no está haciendo el monto
			}
			aux++;
	}
