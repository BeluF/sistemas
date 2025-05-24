#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int numeros[10]={0};
  int a=0, min, max=0;
  bool primero = true;
  cout << "Ingrese 10 valores enteros: \n";
  
  for (int i = 0; i < 10; i++)
  {
      cin >> numeros[i];
      if (numeros[i] % 2 == 0)
          a++;
      if (numeros[i] > max)
          max = numeros[i];
      if ((numeros[i] < min) || primero) {
          min = numeros[i];
          primero = false;
      }     
  }
  
  cout << "Cantidad de numeros pares: " << a;
  cout << "\nNumero maximo: " << max;
  cout << "\nNumero minimo: " << min;
  
  int busqueda;
  cout << "\nBusqueda de numeros en el arreglo: ";
  cin >> busqueda;
  while (!primero)
  {
  	  int i;
      for (i = 0; (numeros[i] != busqueda) && (i < 10); i++) 
      		;
      if (numeros[i] == busqueda)
          cout << "Elemento almacenado\n";
      else 
          cout << "Elemento no almacenado\n";
       
    cin >> busqueda;
  }
  
  return 0;
}
