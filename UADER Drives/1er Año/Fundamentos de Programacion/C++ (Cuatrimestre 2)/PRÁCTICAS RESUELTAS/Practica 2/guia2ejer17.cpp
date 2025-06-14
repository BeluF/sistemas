#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
	/*17. Complete: Una papelera vende cuatro tipos de papel diferentes en rollos : 1: blanco 80
	gramos, 2: blanco 70 gramos, 3: papel prensa, 4: ilustración color (blanco, azul, rojo).
	Inicialmente se ingresa el precio de cada tipo de papel por rollo.
	Apunte elaborado por la cátedra Fundamentos de Programación – Sede Oro Verde Pág. Nro. 5
	
	Se ingresan como datos el tipo de papel (1, 2 ,3 o 4) y la cantidad de rollos vendidos a un
	cliente.
	Tener en cuenta que si la compra se hace de papel tipo 4, se ingresará el color del mismo,
	debiendo recargar un 5% si el color no es blanco.
	Si el cliente compra mas de 10 rollos se le realiza un descuento del 15%.
	Se desea realizar un informe como el siguiente:
	Papelera “Papelitos”
	Tipo de Papel: ..................
	Precio de Referencia: ......
	Descuento: ..............Total : ..............
	Total a Abonar: ..............*/
	float r80,r70,prensa,ilustra,preciorefe,subt,dto,recargo;
	int tipopapel,cantv;
	string color,papel;
	cout<<"Ingrese el valor de cada tipo de rollos: "<<endl;
	cout<<"Blanco 80 gramos"<<endl;
	cin>>r80;
	cout<<"Blanco 70 gramos"<<endl;
	cin>>r70;
	cout<<"Papel Prensa"<<endl;
	cin>>prensa;
	cout<<"Ilustración color"<<endl;
	cin>>ilustra;
	cout<<endl;
	cout<<"Ingrese el tipo de papel vendido (1-Blanco 80gr, 2-Blanco 70gr, 3-Papél prensa o 4-Ilustración color)"<<endl;
	cin>>tipopapel;
	cout<<"Ingrese la cantidad vendida"<<endl;
	cin>>cantv;
	cin.ignore();
	if (tipopapel==4)
	cout<<"Ingrese el color (blanco, azul,rojo)"<<endl;
	getline(cin,color);
	switch (tipopapel)
	{
	case 1: subt=(r80*cantv);
	papel="Blanco 80 gramos";
	preciorefe=r80;
	break;
	case 2: subt=(r70*cantv);
	papel="Blanco 70 gramos";
	preciorefe=r70;
	break;
	case 3: subt=(prensa*cantv);
	papel="Papel Prensa";
	preciorefe=prensa;
	break;
	case 4: subt=(ilustra*cantv);
	papel="Ilustración color";
	preciorefe=ilustra;
	break;
	}
	if (color !="blanco")
	 recargo=(subt*0.05);
	else  recargo=0;
	if (cantv>10)
	 dto=(subt*0.15);
	else  dto=0;
	cout<<"Papelera: PAPELITOS"<<endl;
	cout<<"Tipo de papel: "<<papel<<endl;
	cout<<"Precio de referencia: $"<<preciorefe<<endl;
	cout<<"Descuento: $"<<dto<<"      "<<"Total: $"<<subt<<endl;
	cout<<"Total a abonar: $"<<subt+recargo-dto;
	
	
	
	return 0;
}

