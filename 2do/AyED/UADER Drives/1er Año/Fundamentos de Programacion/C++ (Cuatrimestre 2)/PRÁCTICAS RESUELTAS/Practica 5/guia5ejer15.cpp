#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    /*15. La Municipalidad de Paraná desea obtener información sobre las multas pagadas durante
    un mes. Existen 10 tipos de multas, codificadas de 1 a 10, y para cada una se ha fijado su
    importe en función de litros de nafta súper. Para realizar el proceso solicitado se ingresa por
    cada tipo de multa, la cantidad de litros de nafta a cobrar (ordenados por tipo de multa).
    Además se ingresan los datos de las multas pagadas durante el mes: día, número de carnet
    de conductor, apellido y nombre y tipo de multa (1..10). Estos datos se ingresan, ordenados
    Apunte elaborado por la cátedra Fundamentos de Programación – Sede Oro Verde Pág. Nro. 2
    por día y para un mismo día pueden venir varias multas. El fin de datos está dado por día =
    99. El precio del litro de nafta súper se ingresa al principio como primer dato.
    Se desea:
    a) Obtener el siguiente informe:
    DIA APELLIDO Y NOMBRE CARNET TIPO MONTO
    XX XXXXXXXXXXXX XXXXXX XXXXX XXXXXX
    ... ... ... ... ...
    TOTAL DEL DIA 1: $ XXXXX
    DIA APELLIDO Y NOMBRE CARNET TIPO MONTO
    XX XXXXXXXXXXXX XXXXXX XXXXX XXX   XXX
    ... ... ... ... ...
    TOTAL DEL DIA 2: $ XXXXX
    ....................................................
    TOTAL DEL MES: $ XXXXX
    b) Informar además por cada tipo de multa el monto total mensual.
    c) Proponga lote de prueba y salida esperada.-
    */
   float preciosuper,multa[10],multadias[999]={0},totmes=0,totmesmultas[10]={0},monto[999];
   int dia,c=0,tipom,d=0,diainforme=0;
   string nya[999],carnet[999];
   cout<<"Ingrese precio de nafta super (por litro)"<<endl;
   cin>>preciosuper;
   for (int i=0; i<10;i++)
   {
    cout<<"Ingrese la cantidad de litros a pagar por tipo de multa: "<<i+1<<endl;
    cin>>multa[i];
   }
   cout<<"Ingrese dia"<<endl;
   cin>>dia;
   while (dia !=99) //comprobar si es valido el dia
   {
    int anterior=dia;
    while (anterior==dia) //número de carnet de conductor, apellido y nombre y tipo de multa (1..10)
    {
        cin.ignore();
        cout<<"Ingrese carnet de conductor"<<endl;
        getline(cin,carnet[c]);
        cout<<"Ingrese apellido y nombre"<<endl;
        getline(cin,nya[c]);
        cout<<"Ingrese tipo de multa"<<endl;
        cin>>tipom;
        monto[c]=tipom*preciosuper;
        multadias[dia-1]+=monto[c];
        totmes+=multadias[dia-1];
        totmesmultas[tipom-1]+=multadias[dia-1];
        c++;
        cout<<"Ingrese dia"<<endl;
        cin>>dia;
    }
    diainforme++;
    cout<<"TOTAL DEL DIA "<<diainforme<<" : $"<<multadias[diainforme-1]<<endl;
    cout<<"DIA   APELLIDO Y NOMBRE  CARNET   TIPO MONTO"<<endl;
    for (int i = d; i < c; i++)
    {
     cout<<diainforme<<"            "<<nya[i]<<"                "<<carnet[i]<<"                "<<monto[i]<<endl;   
    }
    d=c;
   }
   cout<<"TOTAL DEL MES: $"<<totmes<<endl;
   for (int i=0; i<10;i++)
   {
    cout<<"TOTAL RECAUDADO DE TIPO MULTA "<<i+1<<" : $"<<totmesmultas[i]<<endl;;
   }
    return 0;
}
