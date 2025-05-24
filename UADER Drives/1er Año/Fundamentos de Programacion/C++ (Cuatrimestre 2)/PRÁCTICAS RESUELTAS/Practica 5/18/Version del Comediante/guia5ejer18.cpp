#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc; (void)argv;
    /*18. Ingrese una lista de N palabras y almacénelas en un arreglo. Luego genere una matriz de
    Nx3 donde se almacenará lo siguiente: en la columna 1 el largo de la palabra, en la columna 2
    la cantidad de consonantes, en la 3 la cantidad de vocales.
    Luego de finalizada la carga, realizar el siguiente informe:
    Palabra Largo Consonantes Vocales Otros Caracteres
    xxxxxxx 999     999         999     999
    xxxxxxx 999     999         999     999
    xxxxxxx 999     999         999     999
    El valor N se ingresa como primer dato.*/
    int n;
    cout<<"Ingrese la cantidad de palabras"<<endl;
    cin>>n;
    int matriz[n][4];
    char palabras[n][100];
    for (int i=0; i<n;i++)
    {
        cout<<"Ingrese la palabra"<<endl;
        cin>>palabras[i];
    }
    for (int i = 0; i < n; i++)
    {
        int largo = strlen(palabras[i]);
        int consonantes=0, vocales=0, otroscaract=0;
        for (int j = 0; j < largo; j++)
        {
            char l= tolower(palabras[i][j]);
            
            if (isalpha(l))//comprobar si la letra es un simbolo o no
            {
                l=tolower(l);
                if (l=='a' || l=='e' || l=='i' || l=='o' || l=='u')
                {
                vocales++;
                }
                else
                { 
                consonantes++;
                }
            }
            else 
            {
            otroscaract++;
            }
        }
        matriz[i][0]=largo;
        matriz[i][1]=consonantes;
        matriz[i][2]=vocales;
        matriz[i][3]=otroscaract;
    }
    cout<<"PALABRA\t\tLARGO\t\tCONSONANTES\t\tVOCALES\t\tOTROS CARACTERES"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<palabras[i]<<"\t\t"<<matriz[i][0]<<"\t\t\t"<<matriz[i][1]<<"\t\t\t"<<matriz[i][2]<<"\t\t\t"<<matriz[i][3]<<endl;
    }
    
    
    return 0;
}
