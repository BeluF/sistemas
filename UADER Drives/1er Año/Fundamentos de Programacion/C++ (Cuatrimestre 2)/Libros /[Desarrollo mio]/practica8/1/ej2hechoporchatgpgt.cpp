#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int funcion_cuadratica(int a, int b, int c, int x){
    int y = a*x*x + b*x + c;
    return y;
}

bool ordenar_por_y(const vector<int>& v1, const vector<int>& v2){
    return v1[1] < v2[1];
}

int main(){
    int a, b, c;
    cout << "Ingrese los valores de a, b y c: ";
    cin >> a >> b >> c;
    
    ofstream archivo("valores.txt");
    if(!archivo){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    
    for(int x=1; x<=1000; x++){
        int y = funcion_cuadratica(a, b, c, x);
        archivo << x << " " << y << endl;
    }
    
    archivo.close();
    
    ifstream archivo_lectura("valores.txt");
    if(!archivo_lectura){
        cout << "Error al abrir el archivo" << endl;
        return 1;
    }
    
    vector<vector<int> > matriz;
    int x, y;
    while(archivo_lectura >> x >> y){
        matriz.push_back({x, y});
    }
    
    sort(matriz.begin(), matriz.end(), ordenar_por_y);
    
    cout << "Matriz ordenada por la columna de y:" << endl;
    for(auto fila : matriz){
        cout << fila[0] << " " << fila[1] << endl;
    }
    
    archivo_lectura.close();
    
    return 0;
}

