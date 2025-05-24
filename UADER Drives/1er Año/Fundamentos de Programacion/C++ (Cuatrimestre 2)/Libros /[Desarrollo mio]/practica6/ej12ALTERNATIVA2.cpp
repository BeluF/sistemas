#include <iostream>
#include <conio.h>
using namespace std;

void ordenar(int max);
void modbotellas(int menu);
void mostrartotal(int max);

const int m=7;
int aux,n,i=0;
float vino[500][m]; /*m=0 código vino; m=1 precio; m=2 cantidad; m3=botellas vendidas; m4=botellas compradas; m5=monto */

int main(){
	int m,max=0;
	char menu;
	//SISTEMA DE ALTA DE VINOS
	do {	
	//	mostrardatos(max);
		cout<<"Ingrese codigo de vino: "; cin>>n;
		if ((n<500)&&(n>0)&&(n!=vino[n][0])) {
			max=n+1;
			vino[n][0]=n;
			cout<<"Ingrese precio por botella: $"; cin>>vino[n][1];
			cout<<"Ingrese cantidad de botellas existentes: "; cin>>vino[n][2];
		}
		else if (n>500) cout<<"Numero ingresado superior al limite de carga de datos (500)"<<endl;
		else cout<<"Código de vino cargado anteriormente"<<endl;
			}while (n<9999);
		n=0;
	
	//MODIFICACIÓN DE VINOS
	do{
		cout<<endl<<"Ingrese codigo de vino: "; cin>>n;
		if ((n<9999)&&(n==vino[n][0])) {
			cout<<"Cod. Vino: "<<vino[n][0]<<" | Botellas vendidas "<<vino[n][3]<<" | Botellas compradas "<<vino[n][4];
			cout<<endl<<"Tipo de movimiento"<<endl<<"1. Venta"<<endl<<"2. Compra al proveedor"<<endl;
			menu=getch();
			if (menu=='1') {
			modbotellas(menu);
			}					//en este caso se restan botellas a la existencia total
			else if (menu=='2'){
			modbotellas(menu);	//en este caso se sumarian botellas a la existencia total
			}
			else cout<<"Número incorrecto"<<endl;
		}
		else cout<<"Codigo de botella no encontrado"<<endl;
	}while (n<9999);
	n=0;
	//ACTIVIDAD B
	mostrartotal(max);
	//ACTIVIDAD C
	ordenar(max);
	//final	
	return 0;
}

void mostrartotal(int max){
	int totalv=0,totalr=0;
	for (i=0;i<max;i++){
		totalv=totalv+vino[i][3];
		totalr=totalr+(vino[i][3]*vino[i][1]);
	}
	cout<<"Total de botellas vendidas: "<<totalv<<" | Total recaudado : "<<totalr;
}

void modbotellas(int menu){
			cout<<"Ingrese cantidad de botellas: "; cin>>aux;
			//system("cls");
			cout<<endl<<endl;
			if (menu=='1') {
				vino[n][2]=vino[n][2]-aux;
				vino[n][3]=vino[n][3]+aux;
				vino[n][5]=vino[n][2]*vino[n][1]; 
			}
			else {
				vino[n][2]=vino[n][2]+aux;
				vino[n][4]=vino[n][4]+aux;
			}
			aux++;
	}
	
// ACTIVIDAD B y C
void ordenar(int max){
		int i,j,k;
		for (i=0;i<(max-1);i++){
			for (j=i+1;j<max;j++){
				if (vino[i][2]<vino[j][2]) {
					for (k=0;k<6;k++){
						aux=vino[i][k];
						vino[i][k]=vino[j][k];
						vino[j][k]=aux;
					}
				}
			}
			cout<<endl<<"Cod. Vino: "<<vino[i][0]<<" | Precio: $"<<vino[i][1]<<" | Cantidad: "<<vino[i][2]<<" | Monto: $"<<vino[i][2]*vino[i][1];
		}
	}



