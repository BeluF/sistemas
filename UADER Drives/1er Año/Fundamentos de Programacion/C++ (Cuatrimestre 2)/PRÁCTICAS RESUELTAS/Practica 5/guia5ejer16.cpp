#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    /* 16. Una empresa que se dedica a la venta de reactivos químicos posee un plantel de 50
    vendedores que realizan sus ventas a laboratorios de todo el país y del exterior. Cada
    vendedor posee un número de código entre 1 y 50.
    La empresa comercializa 15 tipos de reactivos, los que se encuentran codificados de 1 a 15, y
    cuyos precios se ingresan al principio, ordenados por código.
    Se conocen además los apellidos y nombres de los vendedores, con su código
    correspondiente, sin orden alguno.
    Luego se conocen las ventas realizadas por la empresa, ingresándose por cada una: Código
    de vendedor (1 a 50), código de reactivo (1 a 15), cantidad vendida y tipo de venta (N:
    Nacional o I: Internacional). Pueden venir varias ventas para un mismo vendedor y para un
    mismo reactivo. Las ventas se ingresan sin ningún orden. El fin de datos está dado por un
    código de vendedor = 99.
    Se desea conocer:
    a) Por cada venta, el total vendido en cantidad y monto, indicando el apellido y nombre del
    vendedor que la realizó.
    b) Monto total de ventas nacionales y monto total de ventas internacionales.
    c) Cantidad total vendida de cada reactivo */
    float precioreactivos [15],monto,ventasnacionales=0,ventasinternacionales=0;
    string vendedores[50],tipov;
    int codvendedor,codreactivo,cantv,totv[15];
    for (int i = 0; i < 15; i++)
    {
        cout<<"Ingrese precio del reactivo codificado con el numero "<<i+1<<endl;
        cin>>precioreactivos[i];
        totv[i]=0;
    }
    for (int i = 0; i < 50; i++)
    {
        cout<<"Ingrese codigo de vendedor"<<endl;
        cin>>codvendedor;
        cin.ignore();
        cout<<"Ingrese nombre y apellido"<<endl;
        getline(cin,vendedores[codvendedor]);
    }
    cout<<"Ingrese un codigo de vendedor"<<endl;
    cin>>codvendedor;
    while (codvendedor!=99)
    {
        cout<<"Ingrese codigo del reactivo"<<endl;
        cin>>codreactivo;
        cout<<"Ingrese la cantidad vendida"<<endl;
        cin>>cantv;
        cout<<"Ingrese tipo de venta (N:nacional, I:internacional)"<<endl;
        cin>>tipov;
        totv[codreactivo]+=cantv;
        monto=cantv*precioreactivos[codreactivo-1];
        if (tipov=="N")
        ventasnacionales+=monto;
        else ventasinternacionales+=monto;
        cout<<endl;
        cout<<"Informe de la venta de: "<<vendedores[codvendedor]<<endl;
        cout<<"TOTAL VENDIDO EN CANTIDAD       MONTO"<<endl;
        cout<<cantv<<"                          "<<monto<<endl;
        cout<<endl;
        cout<<"Ingrese un codigo de vendedor"<<endl;
        cin>>codvendedor;
    }
    cout<<"Monto total de ventas Nacionales: $"<<ventasnacionales<<endl;
    cout<<"Monto total de ventas Internacionales: $"<<ventasinternacionales<<endl;
    for (int i=0;i<15;i++)
    {
        cout<<"Cantidad vendida de reactivo codificado con el numero "<<i+1<<" fue de "<<totv[i]<<endl;
    }
    return 0;
}
