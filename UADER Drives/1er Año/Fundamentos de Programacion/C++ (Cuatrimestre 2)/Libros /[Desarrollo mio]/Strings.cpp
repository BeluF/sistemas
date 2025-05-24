#include <iostream>
#include <string>
using namespace std;

int main(){
	const string nombre= "Tomas Schlotahuer";		//constante string
	const char freno='.';
	string cadena;			//string común
	string apellido="Schlotahuer Tomas"; 			//strin
	string apelli2 ("Schlotahuer Tomas");		//otra manera de asignar el valor
	//esta otra manera viene porque si no le asignamos valor la cadena se define automáticamente como ("") osea vacio
	string otro=nombre;				//asignando el valor de una constante a una variable
	cout <<nombre<<" + "<<apellido<<endl;
	//CIN solamente lee hasta encontrar un espacio en blanco o un salto de línea, por eso al ingresar 2 palabras separadas 1 de otra por un espacio, guarda solo la primera
	//Para leer un 2 palabras o más juntas, hay que usar la función getline
	getline(cin,cadena,freno);
	/*La función getline lee y almacena en una variable de tipo string todos los caracteres del buffer
	de entrada, hasta leer el carácter de fin de línea (ENTER), sin eliminar los espacios iniciales y/o
	intermedios.*/
	cout<<cadena<<endl;
	/* Getline por defecto lee hasta que el usuario pulsa enter, pero podemos especificarle un delimitador. Ese caracter 
	delimitador no será incluído al guardar los datos del buffer.*/
	//cin.get(); 	cin.get() solamente borra 1 caracter del buffer por lo tnato habría que ejecutarlo por cada caracter que haya en este, o lo que es lo mismo ejecutarlo solamente dsps de un cin.
	/*el operador >> no LEE la tecla enter, pero getline si
	entonces al ingresar algo con cin>> y luego usar getline, 
	este va a mirar la tecla enter en el buffer y va a seguir derecho, 
	como si ese hubiera sido el dato que le queríamos guardar*/
	cin.ignore(5,'\n'); //ignora 5 espacios o hasta el enter='\n'.
	getline(cin,apellido);
	cout<<endl<<apellido<<endl;
	cout<<apelli2+" test ig:"+apellido;

	
		
}

