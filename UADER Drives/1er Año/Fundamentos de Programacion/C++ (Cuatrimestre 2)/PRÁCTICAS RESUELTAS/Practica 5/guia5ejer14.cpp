#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    /*14. Se ha solicitado ingresar los siguientes datos correspondientes a 500 personas inscriptas
    en un curso de gimnasia: Apellido y nombre, Domicilio, Edad, Documento, Sexo y Altura.
    Estos datos se ingresan sin ningún orden y se solicita que dicha información sea guardada en
    matrices. Informar un listado con los siguientes datos: Apellido y nombre – Documento –
    Sexo, de las personas cuya altura supera el promedio general de las mismas.*/
    string nombres[50][10],domicilios[50][10],sexo[50][10],documentos[50][10];
    float altura[50][10],promedioaltura=0;
    int edad[50][10];
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            cout<<"Ingrese Apellido y nombre"<<endl;
            getline(cin,nombres[k][i]);
            cout<<"Ingrese Domicilio"<<endl;
            getline(cin,domicilios[k][i]);
            cout<<"Ingrese sexo"<<endl;
            getline(cin,sexo[k][i]);
            cout<<"Ingrese altura en cm"<<endl;
            cin>>altura[k][i];
            cout<<"Ingrese edad"<<endl;
            cin>>edad[k][i];
            cin.ignore();
            cout<<"Ingrese documento"<<endl;
            getline(cin,documentos[k][i]);
            promedioaltura+=altura[k][i]; //sumar alturas para luego calcular el promedio
        }
    }
    promedioaltura=promedioaltura/500;
    cout<<"Matriz con datos de personas que superan el promedio de altura"<<endl;
        cout<<"NOMBRE Y APELLIDO         DOCUMENTO                  SEXO"<<endl;
    for (int k = 0; k < 50; k++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (altura[k][i]>promedioaltura)
            cout<<nombres[k][i]<<"     "<<documentos[k][i]<<"      "<<sexo[k][i]<<endl;
        }
        
    }
    
    return 0;
}
