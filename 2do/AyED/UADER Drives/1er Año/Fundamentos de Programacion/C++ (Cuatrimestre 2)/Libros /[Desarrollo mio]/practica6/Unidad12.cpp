#include <iostream>
#include <conio.h>
using namespace std;

/* Punteros = Variable que guarda la direcci�n de memoria donde se guarda otra variable.
&n = direcci�n de n;
*n = variable cuya direcci�n est� almacenada en n */ 


int main(){
	//punteros fr
	int num=20,*dir_num=&num;
	//otra manera de definir la variable: int num,*dir_num
	//									  dir_num=&num;
	
	cout<<"Numero: "<<num<<endl;
	cout<<"Direccion de memoria: "<<dir_num<<endl;
	cout<<"Que hay en esa direccion de memoria: "<<*dir_num;
	
	return 0;

} 
