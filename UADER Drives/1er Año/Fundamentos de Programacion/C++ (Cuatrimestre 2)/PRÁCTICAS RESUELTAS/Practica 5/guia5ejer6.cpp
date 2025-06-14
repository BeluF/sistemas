#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    /*6. Una cooperadora desea obtener la nómina de personas que han adquirido un bono
    contribución, numerados del 1 al 100. Para ello se ingresan los nombres de cada una de las
    100 personas que compraron dicho bono, ordenados por número de bono. Se quiere mostrar
    al finalizar la carga, un listado con el siguiente formato;
    NRO BONO PERSONA QUE ADQUIRIÓ EL BONO
    1 XXXXXXXXXXXXXXXXX
    2 XXXXXXXXXXXXXXXXX*/
    string bono[100];
    for (int i = 0; i < 2; i++)
    {
        cout<<"Ingrese el nombre de la persona correspondiente al nro de bono: "<<i+1<<endl;
        getline(cin,bono[i]);
    }
    cout<<"NRO BONO ---------- PERSONA QUE ADQUIRIÓ EL BONO"<<endl;
    for (int i = 0; i < 100; i++)
    {
        cout<<i+1<<" ------------ "<<bono[i]<<endl;
    }
    
    return 0;
}

