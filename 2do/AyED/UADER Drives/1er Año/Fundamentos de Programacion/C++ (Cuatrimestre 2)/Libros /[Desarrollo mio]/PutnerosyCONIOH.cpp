#include <iostream>
#include <cstdlib>
#include <conio.h> 	

/*conio.h trae las siguientes funciones:
kbhit	Determina si una tecla del teclado ha sido presionada
getch	Lee un car�cter directamente de la consola sin hacer uso del buffer, y sin mostrar salida
getche	Igual que getch, pero muestra la salida
ungetch	Pone un car�cter de vuelta al buffer de teclado
cgets	Lee una cadena de texto directamente de la consola
cscanf	Lee valores formateados directamente de la consola
putch	Escribe un car�cter directamente en la consola
cputs	Escribe una cadena de texto directamente desde la consola
cprintf	Formatea valores y los escribe directamente a la consola
 */

using namespace std;

/* PUNTEROS
	&n = direcci�n de n
	*n =variable cuya direcci�n est� almacenada en n
*/
int main(){
	int num;
	cin>>num;
	
	int *mem=&num;
	
	cout<<"Numero: "<<num<<endl<<endl;
	cout<<"Direccion de memoria: "<<mem<<endl;
	cout<<"Lo que hay en esa direccion de memoria es: "<<*mem;
		
	getch();
	return 0;
}
