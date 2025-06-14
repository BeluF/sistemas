#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream arch;
	arch.open("cursos.txt");
	arch << "2536PEC"<<endl;	arch<<"Perfeccionamiento en la elaboracion de Cerveza" << endl;
	arch << "1254CCC"<<endl;	arch<<"Control de contaminantes cerveceros" << endl;
	arch << "2178MC1"<<endl;	arch<<"Microscopia cervecera" << endl;
	arch << "3694CCL"<<endl;	arch<<"Control de calidad de levaduras" << endl;
	arch << "4718MLC"<<endl;	arch<<"Manejo de levaduras cerveceras" << endl;
	arch << "6152RUL"<<endl;	arch<<"Re-utilizacion de las levaduras" << endl;
	arch << "7382ASC"<<endl;	arch<<"Analisis sensorial de la cerveza" << endl;
	arch << "5537TEC"<<endl;	arch<<"Tecnologia de elaboracion de cerveza" << endl;
	
	
	arch.close();
	
	arch.open("asistentes.txt");
	arch<<"26410166"<<endl;	arch<<"VILLALBA, Indalecio"<<endl;
	arch<<"37782732"<<endl;	arch<<"ESPINOSA, Cesar"<<endl;
	arch<<"24784156"<<endl;	arch<<"RODRIGUEZ, Victor"<<endl;
	arch<<"25032109"<<endl;	arch<<"FUMICHELI, Sonia"<<endl;
	arch<<"32972286"<<endl;	arch<<"HETZE, Cesar"<<endl;
	arch<<"28257284"<<endl;	arch<<"MEDINA, Santiago"<<endl;
	arch<<"14512237"<<endl;	arch<<"VERA, Hugo"<<endl;
	arch<<"26675009"<<endl;	arch<<"CRISTO, Santiago"<<endl;
	arch<<"35299339"<<endl;	arch<<"KINDERKNECHT, Martin"<<endl;
	arch<<"30387758"<<endl;	arch<<"VALENZUELA, Jonathan"<<endl;
	arch<<"38543727"<<endl;	arch<<"GONZALEZ, Marina"<<endl;
	arch<<"27428468"<<endl;	arch<<"TABLADA, Lautaro"<<endl;
	arch<<"22261306"<<endl;	arch<<"DOMINGUEZ, Silvia"<<endl;
	arch<<"25210712"<<endl;	arch<<"PALACIO, Esteban"<<endl;
	arch<<"43350123"<<endl;	arch<<"NUNIEZ, Luana"<<endl;
	arch<<"25157694"<<endl;	arch<<"MACHADO, Keila"<<endl;
	arch<<"28248286"<<endl;	arch<<"LAPIERRE, Luis"<<endl;
	arch<<"26674127"<<endl;	arch<<"BALCAZA, Lis"<<endl;
	arch<<"25210712"<<endl;	arch<<"PALACIO, Eduardo"<<endl;
	arch<<"26042019"<<endl;	arch<<"MONTES, Jonatan"<<endl;
	arch<<"26976530"<<endl;	arch<<"LEDESMA, Brenda"<<endl;
	arch<<"12339402"<<endl;	arch<<"MARTINEZ, German"<<endl;
	arch<<"23883465"<<endl;	arch<<"MORENO, Mariano"<<endl;
	arch<<"38387802"<<endl;	arch<<"BASTIDA, Daniel"<<endl;
	arch<<"26974296"<<endl;	arch<<"CEPEDA, Rosana"<<endl;
	arch<<"35300590"<<endl;	arch<<"REA, Isabela"<<endl;
	arch<<"20732871"<<endl;	arch<<"BASUALDO, Marta"<<endl;
	arch<<"20046248"<<endl;	arch<<"CABRERA, Huerto"<<endl;
	arch<<"33617738"<<endl;	arch<<"SPAHN, Melody"<<endl;
	arch<<"35771716"<<endl;	arch<<"LOPEZ, Agostina"<<endl;
	arch<<"36591043"<<endl;	arch<<"CEPEDA, Patricia"<<endl;
	arch<<"24713733"<<endl;	arch<<"AGUIRRE, Nimsi"<<endl;
	arch<<"26784907"<<endl;	arch<<"ROLON, Karina"<<endl;
	arch<<"38170481"<<endl;	arch<<"BAST, Karen"<<endl;
	arch<<"31724626"<<endl;	arch<<"ZALAZAR, Romina"<<endl;
	arch<<"13043513"<<endl;	arch<<"BARRIOS, Yohanna"<<endl;
	arch<<"20096734"<<endl;	arch<<"MONZON, Karen"<<endl;
	arch<<"33503481"<<endl;	arch<<"SUAREZ, Manuel"<<endl;
	arch<<"17597410"<<endl;	arch<<"MARQUEZ, Paola"<<endl;
	arch<<"25617205"<<endl;	arch<<"GONZALEZ, Edgar"<<endl;
	arch<<"29325707"<<endl;	arch<<"PASSI, Mariana"<<endl;
	arch<<"27963627"<<endl;	arch<<"SIROMSKI, Lucia"<<endl;
	arch<<"34057876"<<endl;	arch<<"BALCAZA, Malena"<<endl;
	arch<<"38170428"<<endl;	arch<<"MARADEY, Ana"<<endl;
	arch<<"32275379"<<endl;	arch<<"MORENO, Lucia"<<endl;
	arch<<"33624377"<<endl;	arch<<"MORILLA, Mauricio"<<endl;
	arch<<"20046249"<<endl;	arch<<"CABRERA, Thiago"<<endl;
	arch<<"35442121"<<endl;	arch<<"SEGOVIA, Maria"<<endl;
	arch<<"26029273"<<endl;	arch<<"VELAZQUEZ, Cristina"<<endl;
	arch<<"34549489"<<endl;	arch<<"ROMERO, Marcelo"<<endl;
	arch<<"33383124"<<endl;	arch<<"SALINAS, Dana"<<endl;
	arch<<"27900996"<<endl;	arch<<"GODOY, Monica"<<endl;
	arch<<"35966360"<<endl;	arch<<"QUINTEROS, Miguel"<<endl;
	arch<<"32834354"<<endl;	arch<<"SAMANIEGO, Rosa"<<endl;
	arch<<"26358143"<<endl;	arch<<"AGUIAR, Lourdes"<<endl;
	arch<<"24158378"<<endl;	arch<<"NOGUERA, Rosa"<<endl;
	arch<<"32580547"<<endl;	arch<<"MEDINA, Samira"<<endl;
	arch<<"29121281"<<endl;	arch<<"SCHAMNE, Maximo"<<endl;
	arch<<"24831653"<<endl;	arch<<"ARELLANO, Nicolas"<<endl;
	arch<<"27441256"<<endl;	arch<<"SIGEL, Sonia"<<endl;
	arch<<"25322735"<<endl;	arch<<"ALVAREZ, Yazmin"<<endl;
	arch<<"37546165"<<endl;	arch<<"BARRETO, Jennifer"<<endl;
	
	arch.close();
	
	return 0;
}

