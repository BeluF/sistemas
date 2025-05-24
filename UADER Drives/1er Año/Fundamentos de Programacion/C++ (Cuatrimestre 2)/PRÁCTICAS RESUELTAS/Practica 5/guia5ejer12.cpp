#include <iostream>
#include <string>

using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    /*12. Un centro pluviométrico desea agrupar las lluvias en rangos, de acuerdo a los milímetros
    llovidos, a saber: [0..100), [100..200), [200..300), [300..400), [400..500) [500 y mayores].
    Por cada lluvia producida se ingresa: cantidad de milímetros, ciudad. Se desea informar para
    cada rango de valores: la cantidad de lluvias, la máxima cantidad llovida y en qué ciudad se
    produjo.
    El fin de datos se da cuando se ingresa una cantidad de mm igual a 0*/
    string ciudades[6],ciudad;
    int lluvias[6]={0};
    float mmllovidos,mayorlluvia[6]={0};
    while (true)
    {
        cout<<"Ingrese cantidad de milímetros llovidos"<<endl;
        cin>>mmllovidos;
        cin.ignore();
        if (mmllovidos==0)
        break;
        cout<<"Ingrese nombre de ciudad donde se produjo la lluvia"<<endl;
        getline(cin,ciudad);
        int rangolluvia=mmllovidos/100;
        if(rangolluvia>=6)
        {
            rangolluvia = 5;
        }
        lluvias[rangolluvia]++;
        if (mmllovidos > mayorlluvia[rangolluvia])
        {
            mayorlluvia[rangolluvia]=mmllovidos;
            ciudades[rangolluvia]=ciudad;
        }
    }
    for (int i = 0; i < 6; i++)
    {   
        if ((i+1)*100 >= 500) 
        {
            cout<<"En el rango de [500 y mayores]"<<endl;
        }
        else 
        {
            cout<<"En el rango de: ["<<i*100<<","<<(i+1)*100<<")"<<endl;
        }
        cout<<"Cantidad de lluvias: "<<lluvias[i]<<endl;
        if (lluvias[i]>0)
        {
           cout<<"La máxima cantidad llovida fue de "<<mayorlluvia[i]<<" mm en: "<<ciudades[i]<<endl; 
        }
    }
    return 0;
}
