#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /* Ingrese una cadena que contenga la palabra “pero”. Reemplace dicha palabra por “sin
embargo”.*/
string cad1;
cout<<"ingrese una cadena de caracteres"<<endl;
getline(cin,cad1);
int n= cad1.find("pero");
 cad1.replace(n,4," sin embargo ");
 cout<<cad1;
    return 0;
}


