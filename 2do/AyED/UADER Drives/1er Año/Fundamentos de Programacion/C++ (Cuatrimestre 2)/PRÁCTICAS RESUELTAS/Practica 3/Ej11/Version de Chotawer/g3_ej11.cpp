#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
	int n; float max=0, min=9999;
	string alumnomin, alumnomax;
	
	cout << "Ingrese numero de alumnos: ";
	cin >> n;
	
	for (int contador=0 ; contador<n ; contador++)
	{
		string nya;
		float peso, altura;
		
		cout << "Ingrese nombre y apellido del alumno: ";
		cin.ignore();
		getline(cin, nya);
		
		cout << "Ingrese peso y altura: ";
		cin >> peso >> altura;
		
		if (peso < min)  
		{
			min = peso;
			alumnomin = nya;
		}
		
		if (altura > max)  
		{
			max = altura;
			alumnomax = nya;
		}
	}
	
	cout << "El alumno con menor peso es: " << alumnomin;
	cout << "El alumno con mayor altura es: " << alumnomax;
	
	return 0;
}

