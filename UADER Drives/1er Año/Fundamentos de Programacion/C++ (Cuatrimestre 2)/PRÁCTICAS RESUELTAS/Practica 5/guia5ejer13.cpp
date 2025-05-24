#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    /*13. Un comercio vende 12 tipos de productos, codificados de 1 a 12. Se ingresa por cada
    producto, la descripción y el precio unitario ordenados por código. Además por cada venta
    realizada de los productos en el último mes se ingresa: nro. de producto (1 –12) y cantidad
    vendida. Puede venir más de una venta por producto. Los datos no vienen ordenados por nro.
    de producto y un nro. de producto igual a cero indica el fin de datos.
    Se desea:
    a) Informar según el siguiente detalle:
    NRO. DE PRODUCTO DESCRIPCIÓN CANTIDAD TOTAL VENDIDA IMPORTE TOTAL
    1 XXXXXXXXXXX XXXXX XXXXX
    2 XXXXXXXXXXX XXXXX XXXXX
    …..
    b) Informar cuál es el producto menos vendido (en cantidad)
    */
   string descripcion[12];
   int productos,cantvendida,totvendido[12]={0},menor=9999,prodmenor;
   float preciou[12],total[12]={0};
    for (int i = 0; i < 12; i++)
    {
        cout<<"Ingrese el precio unitario del producto con el codigo "<<i+1<<endl;
        cin>>preciou[i];
        cin.ignore();
        cout<<"Ingrese la descripción del producto con codigo: "<<i+1<<endl;
        getline(cin,descripcion[i]);
    }
    while (true)
    {
        cout<<"Ingrese nro del producto"<<endl;
        cin>>productos;
        if (productos==0) //si el codigo del producto es 0 sale del bucle
        break;
        cout<<"Ingrese cantidad vendida de ese producto"<<endl;
        cin>>cantvendida;
        total[productos-1]+=(preciou[productos-1]*cantvendida);//calculo de totales para cada producto
        totvendido[productos-1]+=cantvendida;//calculo de cantidades vendidas para el punto b;
        if (totvendido[productos-1]<menor)
        {
            menor=totvendido[productos-1];
            prodmenor=productos;
        }
    }
    cout<<"NRO. DE PRODUCTO//DESCRIPCIoN// CANTIDAD TOTAL VENDIDA// IMPORTE TOTAL"<<endl;
    for (int i = 0; i < 12; i++)
    {
        cout<<i+1<<"                        "<<descripcion[i]<<"                            "<<totvendido[i]<<"                         $"<<total[i]<<endl;
    }
    cout<<"Producto menos vendido: "<<prodmenor;
    return 0;
}
