#include <iostream>
using namespace std;

int busqueda(int n,int max);
void ordenar(int max);
void mostrardatos(int max);
void modbotellas(int menu);
void mostrartotal();

const int m=7;
int aux,n,i=0;
float vino[500][m]; /*m=0 código vino; m=1 precio; m=2 cantidad; m3=botellas vendidas; m4=botellas compradas; m5=monto */

int main(){
	int m,menu,max=0;
	//SISTEMA DE ALTA DE VINOS
	do {	
	//	mostrardatos(max);
		cout<<"Ingrese codigo de vino: "; cin>>n;
		if (n<9999) {
			max=i+1;
			vino[i][0]=n;
			cout<<"Ingrese precio por botella: $"; cin>>vino[i][1];
			cout<<"Ingrese cantidad de botellas existentes: "; cin>>vino[i][2];
			i++;
		}
		else if (n>500) cout<<"Numero ingresado superior al limite de carga de datos (500)"<<endl;
			}while (n<9999);
		n=0;
	//ordenar vinos
	ordenar(max);
	mostrardatos(max);
	
	//MODIFICACIÓN DE VINOS
	do{
		cout<<endl<<"Ingrese codigo de vino: "; cin>>n;
		if (n<9999) {
			m=busqueda(n,max);
			if (n==vino[m][0]) {
				cout<<"Cod. Vino: "<<vino[m][0]<<" | Botellas vendidas "<<vino[m][3]<<" | Botellas compradas "<<vino[m][4];
				cout<<endl<<"Tipo de movimiento"<<endl<<"1. Venta"<<endl<<"2. Compra al proveedor"<<endl;
				cin>>menu;
				if (menu==1) {
				modbotellas(menu);
				}					//en este caso se restan botellas a la existencia total
				else if (menu==2){
				modbotellas(menu);	//en este caso se sumarian botellas a la existencia total
				}
				else cout<<"Número incorrecto"<<endl;
			}
			else cout<<"Codigo de botella no encontrado"<<endl;

		}	
	}while (n<9999);
	n=0;
	//ACTIVIDAD B
	int totalv,totalr;
	for (i=0;i<max;i++){
		totalv=totalv+vino[i][3];
		totalr=totalr+(vino[i][3]*vino[i][1]);
	}
	cout<<"Total de botellas vendidas: "<<totalv<<" | Total recaudado : "<<totalr;
	//ACTIVIDAD C
	ordenar(max);
	mostrardatos(max);	
	//final	
	return 0;
}

void mostrardatos(int max) {
	int i;
	cout<<"==================================[VINERIA]==================================";
	for (i=0;i<max;i++) cout<<endl<<"Cod. Vino: "<<vino[i][0]<<" | Precio: $"<<vino[i][1]<<" | Cantidad: "<<vino[i][2]<<" | Monto: $"<<vino[i][2]*vino[i][1];
}

int busqueda(int n,int max) {
	int i=0,j=max,mid=max/2;
	if (n==vino[0][0]) mid=0;    //como no puede checkear el 0 miramos el 0 primero.
	else {						//acá arranca la busqueda real
		while ((i<=j)&&(n!=vino[mid][0])){
		if (n<vino[mid][0]) j=mid-1;
		else i=mid+1;
		mid=(i+j)/2;}
	}
    return mid;
}

void modbotellas(int menu){
			cout<<"Ingrese cantidad de botellas: "; cin>>aux;
			//system("cls");
			cout<<endl<<endl;
			if (menu==1) {
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

void ordenar(int max){
		int i,j,k;
		cout<<"max: "<<max<<endl;
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
		}
	}



