#include <iostream>
#include <string>
using namespace std;
/*19. Una empresa periodística está realizando una encuesta sobre las necesidades de
capacitación de la gente en diversos temas.
Para la encuesta tomó un muestreo de 500 personas a las cuales les preguntó en que temas
necesitaban capacitarse.
Se ingresan inicialmente los temas seleccionados por la empresa, de la siguiente forma:
Código de tema (1 a 20), nombre del tema, costo de capacitación de una persona, no
necesariamente ordenados por código de tema.
Luego por cada uno de los encuestados se ingresa: código de tema en el que quiere
capacitarse, pudiendo contestar que quiere capacitarse en varios temas, y sabiendo que
finalizan los datos de cada encuestado con un código de tema = 0.
Se desea:
 • Por cada encuestado total de temas en que quiere capacitarse.
 • Total de encuestados que eligieron cada tema, de la siguiente manera:
 Descripción del tema Cantidad de interesados
 xxxxx xxxxxx
 • Número de encuestados que eligieron más de 10 temas.
 • Presupuesto necesario para capacitar a todas las personas en los temas que eligieron.*/
int main()
{
    int codtema,canttemas, cantinteresados[20] = {0}, masde10 = 0;
    float costotema[20],tottemas[20]= {0};
    string nyatema[20];
    for (int i = 0 ; i < 20 ; i++) //Ingreso de datos para cada tema.
    {
        cout << "Ingrese codigo de tema  ";
        cin >> codtema;
        cout << "Ingrese nombre del tema  ";
        cin>>nyatema[codtema];
        cout << "Ingrese el costo de capacitacion de una persona para ese tema  ";
        cin >> costotema[codtema];
    }
    for (int i = 0 ; i < 500 ; i++)
    {
        cout << "Ingrese codigo de tema al que quiere capacitarse  ";
        cin >> codtema;
        canttemas = 0;
        while (codtema != 0)
        {
            cantinteresados[codtema]++;
            tottemas[codtema] += costotema[codtema];
            cout << "Ingrese codigo de tema al que quiere capacitarse, o ingrese 0 para indicar que no quiere ingresar a mas temas  ";
            cin >> codtema;
            canttemas++;
        }
        cout << endl;
        cout << "Al encuestado le gustaria capacitarse en " << canttemas << " temas" << endl;;
        if (canttemas > 10)
        masde10++;
    }
    cout << "La cantidad de personas a las que les gustaria capacitarse en mas de 10 temas es: " << masde10 << endl;
    cout << "Descripcion del tema\t\tCantidad de interesados "<<endl;
    for (int i = 0 ; i < 20 ; i++)
    {
        cout << nyatema[i] << "\t\t\t\t" << cantinteresados[i] << endl;
    }
    cout << "Presupuesto necesario para capacitar a todas las personas segun temas elegidos: " << endl;
    for (int i = 0 ; i < 20 ; i++)
    {
        cout << "Presupuesto necesario para el tema " << i+1 << " $" << tottemas[i] << endl;
    }
    return 0;
}
