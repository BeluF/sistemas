#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	int *prueb;
	prueb=new int[5];
	cout<<prueb[0]<<endl;
	for (int i=0;i<4;i++){ 	
		prueb[i]= i+1;
		cout<<prueb[i]<<endl;
	}
	prueb=new int[10];
	for (int i=0;i<4;i++){
		cout<<prueb[i]<<endl;
	}
    return 0;
}

