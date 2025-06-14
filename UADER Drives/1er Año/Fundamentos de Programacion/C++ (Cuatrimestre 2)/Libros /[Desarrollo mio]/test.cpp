#include <iostream>
#include <string>
using namespace std ;
int main()
{
string nomyape1, nomyape2;
int edad1,edad2;
cout<<"Introduzca el nombre de la primer persona: ";
getline(cin,nomyape1);
cout<<"Introduzca edad de la primer persona: ";
cin>>edad1;
cin.get();
cout<<"Introduzca el nombre de la segunda persona: ";
getline(cin,nomyape2);
cout<<"Introduzca edad de la segunda persona: ";
cin>>edad2;
cout<<endl;
cout<<"Edad: "<<edad1<<" Nombre Completo: "<<nomyape1<<endl;
cout<<"Edad: "<<edad2<<" Nombre Completo: "<<nomyape2<<endl;
return 0;
}

