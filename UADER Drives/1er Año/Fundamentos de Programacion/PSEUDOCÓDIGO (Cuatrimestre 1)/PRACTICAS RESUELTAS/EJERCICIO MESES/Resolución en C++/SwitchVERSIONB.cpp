#include <iostream> //1,3,5,7,8,10,,12=31dias
					//2=28
					//4,6,9,11=30dias

using namespace std;

main() {
	int mes;
	cout<<"Ingrese el mes"<<endl;
	cin>>mes;
	if (12>=mes&&mes>=1)
		do{
			switch(mes){
				case 1:case 3:case 5:case 7:case 8:case 10:
				case 12: cout<<"El mes tiene 31 dias"<<endl<<endl;
				break;
				case 4:case 6:case 9:case 11: cout<<"El mes tiene 30 dias"<<endl<<endl;
				break;
				default:cout <<"El mes tiene 28 dias"<<endl<<endl;
			}
			cout<<"Ingrese el mes"<<endl;
			cin>>mes;
		} while (mes<=12);
	else cout<<"El numero ingresado no corresponde a un mes";
}
