#include <iostream>
using namespace std;
//Búsqueda Binaria
int main() {
int li, ls, n, medio, dat, A[10], i;
cout<<"Ingrese la cantidad de datos a leer: "; cin>>n;
for (i=0; i<n; i++)
{
cout<<"Dato: "; cin>>A[i];
}
cout<<"*****************************************"<<endl;
cout<<"Ingrese el dato a buscar: ";
cin>>dat;
li=0; ls=n; medio= (li+ls)/2;
while ((li <= ls) && (dat != A[medio]))
{
if (dat < A[medio])
ls=medio-1;
else li=medio+1;
 medio= (li+ls)/2;
}
cout<<"*****************************************"<<endl;
if (li > ls)
 cout<<"Elemento no encontrado";
else
cout<<"Elemento encontrado en posición: "<<medio+1;
return 0; 
}

