#include <iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
int main()
{
int m[2][3]={12,34,56,78,90,100};
int i,j;
for (i=0;i<2;i++)
{for (j=0; j<3; j++)
 {cout<<setw(4)<<m[i][j]; //escribe elementos de una fila
 }
 cout<<endl; //avanza a la próxima línea
}
return 0;
}
