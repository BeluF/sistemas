/*
Una empresa de colectivos tiene varios coches que durante el día hacen varios recorridos
y venden 3 tipos de boletos: estudiante, común y jubilado. 
El boleto estudiante es un 20 % más barato que el boleto común y el jubilado un 40 % más
barato que el común. El precio del boleto común se lee como primer dato.
Por cada recorrido se ingresa: Nro. de colectivo, cantidad de boletos estudiantes, cantidad de
boletos comunes y cantidad de boletos jubilados vendidos. 
La carga de datos finaliza con nro. de colectivo = 99. 
Se desea saber:
• Por cada recorrido, el total recaudado.
• Cantidad de boletos estudiantes vendidos durante el día.
• Total recaudado en todos los recorridos ingresados.
• El nro de colectivo que menos recaudó y el monto recaudado por el mismo.
*/
#include <iostream>

using namespace std;

int main(){
    int nrocolectivo,colectivomin,total=0,minimorecorrido=0,CantidadBoletos[]={0,0,0,0};
    float boleto[2];

    cout<<"\nIngrese boleto comun ";
    cin>>boleto[0];
    boleto[1]= boleto[0]*0.80; //precio boleto estudiantil
    boleto[2]= boleto[0]*0.60; //precio boleto jubilado
    do{
        int totalrecorrido=0;
        cout<<"\nIngrese numero de colectivo "; cin>>nrocolectivo;
        
        if (nrocolectivo!=99){
            cout<<"\nCantidad de boletos Comunes ";  cin>>CantidadBoletos[0];
            cout<<"\nCantidad de boletos Estudiantiles "; cin>>CantidadBoletos[1];
            cout<<"\nCantidad de boletos Jubilados ";   cin>>CantidadBoletos[2];
            //consigna 1
            for (int i = 0; i < 3; i++)
            {totalrecorrido=totalrecorrido+CantidadBoletos[i]*boleto[i];}
            cout<<"\nTotal recaudado por ese recorrido: "<<totalrecorrido;
            //consigna 2
            CantidadBoletos[3]=CantidadBoletos[3]+CantidadBoletos[1];
            //consigna 3
            for (int i = 0; i < 3; i++)
            {total=total+ CantidadBoletos[i]*boleto[i];}
            //consigna 4
            if (totalrecorrido<minimorecorrido || minimorecorrido==0)
            { 
                minimorecorrido=totalrecorrido;
                colectivomin=nrocolectivo;
             }
        }
    } while (nrocolectivo!=99);
    
    cout<<"\nCantidad de boletos estudiantiles vendidos: "<<CantidadBoletos[3];
    cout<<"\nTotal recaudado en todos los recorridos ingresados: "<<total;
    cout<<"\nEl colectivo que menos recaudo fue el "<<colectivomin<<" con un total de: $"<<minimorecorrido;

}
