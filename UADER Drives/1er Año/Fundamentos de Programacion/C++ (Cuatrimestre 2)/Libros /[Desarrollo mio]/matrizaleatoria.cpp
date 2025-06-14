#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int i,j,k,n=0,m=0,max=0;
	int matriz[n][m];
	cout<<"Ingrese dimension n y m de la matriz"<<endl;
	cin>>n>>m;
	for (k=0;k<n*3;k++) cout<<"--";
	cout<<endl;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++) {
			matriz[i][j]= rand()%51;
			cout<<"|"<<matriz[i][j]<<"|";
			max=max+matriz[i][j];
		}
		cout<<endl;
		for (k=0;k<n*3;k++) cout<<"--";
		cout<<endl;
	}
	cout<<"Suma de todos los números es: "<<max;
	return 0;
}
