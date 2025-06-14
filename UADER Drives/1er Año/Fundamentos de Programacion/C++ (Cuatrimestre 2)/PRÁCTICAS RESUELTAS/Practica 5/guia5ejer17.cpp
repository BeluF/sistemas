#include <iostream>
#include <cstdlib>

using namespace std;
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    srand(time(NULL));
    int numeros;
    int matriz [10][10]={0};
    for (int i = 0; i < 10; i++)
    {
       numeros= rand()%101;
       matriz[i][0]=numeros;
    }
    for (int i = 1; i < 10; i++)
    {
        numeros=rand()%101;
        matriz[9][i]=numeros;
    }
    for (int  i = 9; i > -1; i--)
    {
        numeros =rand()%101;
        matriz[i][9]=numeros;
    }
    for (int i = 9; i > 0; i--)
    {
        numeros=rand()%101;
        matriz[0][i]=numeros;
    }
    for (int j = 0; j < 10; j++) //mostrar matriz
    {
        for (int i = 0; i < 10; i++)
        {
           cout << matriz [j][i]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}
