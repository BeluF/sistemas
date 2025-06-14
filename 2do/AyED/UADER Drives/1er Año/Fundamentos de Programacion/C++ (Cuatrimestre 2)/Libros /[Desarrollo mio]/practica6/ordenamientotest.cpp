#include <iostream>
using namespace std;
//Ordenamiento por mínimos sucesivos
int main() {
int n, A[50], i, j, aux;
cout<<"Ingrese la cantidad de datos a leer: "; cin>>n;
for (i=0; i<n; i++)
{
cout<<"Dato: "; cin>>A[i];
}
for (i=0; i<(n-1); i++)
for (j=i+1; j<n; j++)
{
if (A[i] > A[j])
{
aux= A[i];
A[i]= A[j];
A[j]= aux;
}
}
cout<<endl;
cout<<"ARREGLO ORDENADO"<<endl;
for (i=0; i<n; i++)
cout<<A[i]<<endl;
 return 0;
}
