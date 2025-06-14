#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream archip;
	ofstream arche;
	
	arche.open("EMPLEADOS.TXT");
	arche<<"7296"<<endl;	arche<<"VILLALBA"<<endl;	arche<<"Juan"<<endl;	arche<<"20200409"<<endl;	arche<<"3"<<endl;	arche<<"PRJDAM01"<<endl;
	arche<<"5418"<<endl;	arche<<"ESPINOSA"<<endl;	arche<<"Maria"<<endl;	arche<<"20170515"<<endl;	arche<<"5"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"3067"<<endl;	arche<<"RODRIGUEZ"<<endl;	arche<<"Carlos"<<endl;	arche<<"20180423"<<endl;	arche<<"4"<<endl;	arche<<"PRJDAM01"<<endl;
	arche<<"1854"<<endl;	arche<<"FUMICHELI"<<endl;	arche<<"Sofia"<<endl;	arche<<"20190610"<<endl;	arche<<"3"<<endl;	arche<<"PRJQA002"<<endl;
	arche<<"4023"<<endl;	arche<<"HETZE"<<endl;	arche<<"Alejandro"<<endl;	arche<<"20170829"<<endl;	arche<<"4"<<endl;	arche<<"PRJDS001"<<endl;
	arche<<"9385"<<endl;	arche<<"MEDINA"<<endl;	arche<<"Lucia"<<endl;	arche<<"20190217"<<endl;	arche<<"3"<<endl;	arche<<"PRJDIU01"<<endl;
	arche<<"6742"<<endl;	arche<<"VERA"<<endl;	arche<<"Diego"<<endl;	arche<<"20201105"<<endl;	arche<<"2"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"5139"<<endl;	arche<<"CRISTO"<<endl;	arche<<"Valentina"<<endl;	arche<<"20180120"<<endl;	arche<<"3"<<endl;	arche<<"PRJDAM02"<<endl;
	arche<<"8472"<<endl;	arche<<"KINDERKNECHT"<<endl;	arche<<"Pedro"<<endl;	arche<<"20191008"<<endl;	arche<<"2"<<endl;	arche<<"PRJDS001"<<endl;
	arche<<"2056"<<endl;	arche<<"VALENZUELA"<<endl;	arche<<"Ana"<<endl;	arche<<"20200712"<<endl;	arche<<"3"<<endl;	arche<<"PRJDS002"<<endl;
	arche<<"6183"<<endl;	arche<<"GONZALEZ"<<endl;	arche<<"Javier"<<endl;	arche<<"20171130"<<endl;	arche<<"3"<<endl;	arche<<"PRJDIU01"<<endl;
	arche<<"7530"<<endl;	arche<<"TABLADA"<<endl;	arche<<"Marta"<<endl;	arche<<"20180307"<<endl;	arche<<"3"<<endl;	arche<<"PRJDS003"<<endl;
	arche<<"4961"<<endl;	arche<<"DOMINGUEZ"<<endl;	arche<<"Andres"<<endl;	arche<<"20181218"<<endl;	arche<<"3"<<endl;	arche<<"PRJQA002"<<endl;
	arche<<"8203"<<endl;	arche<<"PALACIO"<<endl;	arche<<"Laura"<<endl;	arche<<"20190726"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"3574"<<endl;	arche<<"NUNIEZ"<<endl;	arche<<"Manuel"<<endl;	arche<<"20200414"<<endl;	arche<<"3"<<endl;	arche<<"PRJDIU02"<<endl;
	arche<<"1092"<<endl;	arche<<"MACHADO"<<endl;	arche<<"Paula"<<endl;	arche<<"20180903"<<endl;	arche<<"2"<<endl;	arche<<"PRJDIU02"<<endl;
	arche<<"6845"<<endl;	arche<<"LAPIERRE"<<endl;	arche<<"Gabriel"<<endl;	arche<<"20210125"<<endl;	arche<<"1"<<endl;	arche<<"PRJDIU02"<<endl;
	arche<<"9274"<<endl;	arche<<"BALCAZA"<<endl;	arche<<"Carmen"<<endl;	arche<<"20170709"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"3406"<<endl;	arche<<"PALACIO"<<endl;	arche<<"Daniel"<<endl;	arche<<"20190624"<<endl;	arche<<"3"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"5728"<<endl;	arche<<"MONTES"<<endl;	arche<<"Elena"<<endl;	arche<<"20201019"<<endl;	arche<<"2"<<endl;	arche<<"PRJDS001"<<endl;
	arche<<"8613"<<endl;	arche<<"LEDESMA"<<endl;	arche<<"Jose"<<endl;	arche<<"20180211"<<endl;	arche<<"5"<<endl;	arche<<"PRJDIU01"<<endl;
	arche<<"2954"<<endl;	arche<<"MARTINEZ"<<endl;	arche<<"Adriana"<<endl;	arche<<"20200530"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"7140"<<endl;	arche<<"MORENO"<<endl;	arche<<"David"<<endl;	arche<<"20191205"<<endl;	arche<<"3"<<endl;	arche<<"PRJDIU01"<<endl;
	arche<<"6304"<<endl;	arche<<"BASTIDA"<<endl;	arche<<"Sara"<<endl;	arche<<"20171022"<<endl;	arche<<"2"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"8723"<<endl;	arche<<"CEPEDA"<<endl;	arche<<"Fernando"<<endl;	arche<<"20180801"<<endl;	arche<<"3"<<endl;	arche<<"PRJDS001"<<endl;
	arche<<"4396"<<endl;	arche<<"REA"<<endl;	arche<<"Isabel"<<endl;	arche<<"20200229"<<endl;	arche<<"2"<<endl;	arche<<"PRJDAM02"<<endl;
	arche<<"1857"<<endl;	arche<<"BASUALDO"<<endl;	arche<<"Miguel"<<endl;	arche<<"20191113"<<endl;	arche<<"3"<<endl;	arche<<"PRJDIU02"<<endl;
	arche<<"9240"<<endl;	arche<<"CABRERA"<<endl;	arche<<"Beatriz"<<endl;	arche<<"20170504"<<endl;	arche<<"5"<<endl;	arche<<"PRJDS001"<<endl;
	arche<<"5063"<<endl;	arche<<"SPAHN"<<endl;	arche<<"Antonio"<<endl;	arche<<"20181027"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA002"<<endl;
	arche<<"3718"<<endl;	arche<<"LOPEZ"<<endl;	arche<<"Natalia"<<endl;	arche<<"20200909"<<endl;	arche<<"2"<<endl;	arche<<"PRJDIU02"<<endl;
	arche<<"8451"<<endl;	arche<<"CEPEDA"<<endl;	arche<<"Pablo"<<endl;	arche<<"20170416"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA002"<<endl;
	arche<<"2093"<<endl;	arche<<"AGUIRRE"<<endl;	arche<<"Claudia"<<endl;	arche<<"20190731"<<endl;	arche<<"3"<<endl;	arche<<"PRJDS003"<<endl;
	arche<<"5647"<<endl;	arche<<"ROLON"<<endl;	arche<<"Sergio"<<endl;	arche<<"20180203"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA002"<<endl;
	arche<<"1309"<<endl;	arche<<"BAST"<<endl;	arche<<"Patricia"<<endl;	arche<<"20191014"<<endl;	arche<<"3"<<endl;	arche<<"PRJDIU01"<<endl;
	arche<<"7832"<<endl;	arche<<"ZALAZAR"<<endl;	arche<<"Jorge"<<endl;	arche<<"20200620"<<endl;	arche<<"2"<<endl;	arche<<"PRJDAM01"<<endl;
	arche<<"4701"<<endl;	arche<<"BARRIOS"<<endl;	arche<<"Andrea"<<endl;	arche<<"20180112"<<endl;	arche<<"3"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"6953"<<endl;	arche<<"MONZON"<<endl;	arche<<"Ruben"<<endl;	arche<<"20170928"<<endl;	arche<<"4"<<endl;	arche<<"PRJDIU01"<<endl;
	arche<<"2815"<<endl;	arche<<"SUAREZ"<<endl;	arche<<"Rosa"<<endl;	arche<<"20191229"<<endl;	arche<<"5"<<endl;	arche<<"PRJDS001"<<endl;
	arche<<"6084"<<endl;	arche<<"MARQUEZ"<<endl;	arche<<"Ricardo"<<endl;	arche<<"20200318"<<endl;	arche<<"2"<<endl;	arche<<"PRJDS003"<<endl;
	arche<<"3872"<<endl;	arche<<"GONZALEZ"<<endl;	arche<<"Miriam"<<endl;	arche<<"20181107"<<endl;	arche<<"3"<<endl;	arche<<"PRJDAM01"<<endl;
	arche<<"5490"<<endl;	arche<<"PASSI"<<endl;	arche<<"Angel"<<endl;	arche<<"20170721"<<endl;	arche<<"4"<<endl;	arche<<"PRJDS002"<<endl;
	arche<<"7138"<<endl;	arche<<"SIROMSKI"<<endl;	arche<<"Martina"<<endl;	arche<<"20220106"<<endl;	arche<<"1"<<endl;	arche<<"PRJQA002"<<endl;
	arche<<"3065"<<endl;	arche<<"BALCAZA"<<endl;	arche<<"Francisco"<<endl;	arche<<"20220814"<<endl;	arche<<"1"<<endl;	arche<<"PRJDIU02"<<endl;
	arche<<"9421"<<endl;	arche<<"MARADEY"<<endl;	arche<<"Veronica"<<endl;	arche<<"20190605"<<endl;	arche<<"3"<<endl;	arche<<"PRJDAM02"<<endl;
	arche<<"1759"<<endl;	arche<<"MORENO"<<endl;	arche<<"Guillermo"<<endl;	arche<<"20171223"<<endl;	arche<<"4"<<endl;	arche<<"PRJQA001"<<endl;
	arche<<"8306"<<endl;	arche<<"MORILLA"<<endl;	arche<<"Elena"<<endl;	arche<<"20180228"<<endl;	arche<<"3"<<endl;	arche<<"PRJDS003"<<endl;
	arche<<"6925"<<endl;	arche<<"CABRERA"<<endl;	arche<<"Ignacio"<<endl;	arche<<"20191003"<<endl;	arche<<"2"<<endl;	arche<<"PRJDS002"<<endl;
	arche<<"1047"<<endl;	arche<<"SEGOVIA"<<endl;	arche<<"Carolina"<<endl;	arche<<"20170617"<<endl;	arche<<"5"<<endl;	arche<<"PRJDAM01"<<endl;
	arche<<"2840"<<endl;	arche<<"VELAZQUEZ"<<endl;	arche<<"Raul"<<endl;	arche<<"20190322"<<endl;	arche<<"3"<<endl;	arche<<"PRJQA002"<<endl;
	
	
	arche.close();
	
	
	
	
	archip.open("PROYECTOS.TXT");
	
	archip<<"PRJDAM01"<<endl;	archip<<"Proyecto Aurora"<<endl;	archip<<"Desarrollo de Aplicaciones Moviles  "<<endl;
	archip<<"PRJDIU01"<<endl;	archip<<"Operacion Orbita"<<endl;	archip<<"Disenio Interfaz de Usuario  "<<endl;
	archip<<"PRJQA001"<<endl;	archip<<"Proyecto Horizonte"<<endl;	archip<<"Quality Assurance    "<<endl;
	archip<<"PRJDS001"<<endl;	archip<<"Proyecto Genesis"<<endl;	archip<<"Desarrollo de software   "<<endl;
	archip<<"PRJDS002"<<endl;	archip<<"Proyecto Nebula"<<endl;	archip<<"Desarrollo de software   "<<endl;
	archip<<"PRJDIU02"<<endl;	archip<<"Operacion Cosmos"<<endl;	archip<<"Disenio Interfaz de Usuario  "<<endl;
	archip<<"PRJQA002"<<endl;	archip<<"Proyecto Alfa"<<endl;	archip<<"Quality Assurance    "<<endl;
	archip<<"PRJDAM02"<<endl;	archip<<"Proyecto Icaro"<<endl;	archip<<"Desarrollo de Aplicaciones Moviles  "<<endl;
	archip<<"PRJIAML1"<<endl;	archip<<"Proyecto Pulsar"<<endl;	archip<<"Inteligencia Artificial y Machine Learning "<<endl;
	archip<<"PRJDS003"<<endl;	archip<<"Operacion Centauro"<<endl;	archip<<"Desarrollo de software   "<<endl;
	archip<<"PRJSI001"<<endl;	archip<<"Proyecto Beta"<<endl;	archip<<"Seguridad Informatica    "<<endl;
	archip<<"PRJADBI1"<<endl;	archip<<"Operacion Espectra"<<endl;	archip<<"Analisis de Datos y Business Intelligence"<<endl;
	
		
	archip.close();
	
	

	return 0;
}

