#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
	virtual double getPrecio() const = 0; //MC)todo puro virtual
}

class Parte : public Item {
private:
	int idParte;
	char descripcionParte [200];
	double precio;

public:
	virtual double getPrecio() const override
	    return precio;

}

class Bicicleta : public Item {
private:
	vector<Parte*> partes; //Puntero para polimorfismo
	int idBici;
	char descripcionBici [200];
	double precio; //Suma de las partes

public:
	Bicicleta() {

	}
	double getPrecio() {
		double total = 0.0;
		for (auto elem : partes) {
			total += elem -> getPrecio();
			return total;
			// return accumulate(partes.begin(), partes.end(), int total);
		}
	}

}

class Oferta {
private:
	vector<Item*> items;
	float dcto = 0.20;

public:
	getPrecio() const override {
		double total = 0.0;
		for (auto elem : items) {
			total += elem -> getPrecio();
			return total - (total * dcto);

		}
	}

}
struct entidad {
	char nombreClase [50];
	int id;
	char descripcion [200];
	double precio;
};

class Gestora {
private:
	vector <Parte*> parte;
	vector <Bicicleta*> bici;
	vector <Oferta*> oferta;

public:
	void guardarDatosBinPartes()
	{
		ofstream archivo ("Partes.dat", ios::binary, ios::trunc);
		for (auto elem : parte) {
			entidad e;
			strcpy(e.nombreClase, "Parte");
			e.id = elem -> idParte;
			strcpy(e.descripcion, (elem -> descripcionParte).c_str());
			e.precio = elem -> precio;
			archivo.write((char*)&e, sizeof(entidad));
		}
		archivo.close();
	}

	void guardarDatosBinBicis()
	{
		ofstream archivo ("Bicis.dat", ios::binary, ios::trunc);
		for (auto elem : bici) {
			entidad e;
			strcpy(e.nombreClase, "Bicicleta");
			e.id = elem -> idBici;
			strcpy(e.descripcion, (elem -> descripcionBici).c_str());
			e.precio = elem -> precio;
			archivo.write((char*)&e, sizeof(entidad));
		}
		archivo.close();
	}

	void guardarDatosBinOfertas()
	{
		ofstream archivo ("Ofertas.dat", ios::binary, ios::trunc);
		for (auto elem : parte) {
			entidad e;
			strcpy(e.nombreClase, "Parte");
			e.id = elem -> idParte;
			strcpy(e.descripcion, (elem -> descripcionParte).c_str());
			e.precio = elem -> precio;
			archivo.write((char*)&e, sizeof(entidad));
		}

		for (auto elem : bici) {
			entidad e;
			strcpy(e.nombreClase, "Bicicleta");
			e.id = elem -> idBici;
			strcpy(e.descripcion, (elem -> descripcionBici).c_str());
			e.precio = elem -> precio;
			archivo.write((char*)&e, sizeof(entidad));
		}
		archivo.close();
	}

	//(15) Guardar en un archivo de texto todas las ofertas, se debe listar elementos que la componen (separado por coma) y el precio total.
	void guardarOfertasTxt() {
		ofstream archivo("Ofertas.txt", ios::trunc);

		for (auto ofertaElem : oferta) {
			string linea;
			for (auto item : ofertaElem -> items) {
				linea += item -> descripcion + ", ";
			}
			archivo << linea << " Precio Total: " << ofertaElem -> getPrecio() << endl;
		}
		archivo.close();

	}
	/*
	(30) Realice las siguientes mC)todos utilizando stl :

	Obtener la o las bicicletas mC!s caras.
	Obtener la parte mC!s utilizada en las bicicletas.
	Obtener la bicicleta que tiene mC!s componentes. */

	void getBicisMasCaras() {
		bici.sort(bici.begin(), bici.end(), [] (Bicicleta* b1, b2) -> bool {return b1 -> precio < b2 -> precio});
		double max = *max_element(bici.begin(), bici.end())
		for (auto b : bici) {
			if(b -> precio == max) {
				cout << b -> idBici << " es de las bicicletas mC!s caras";
			}

		}
	}

	void parteMasUtilizada() {
		map<Parte*, int> contador;

		for (auto b : bici) {
			for (auto p : b->partes) {
				contador[p]++;
			}
		}

		auto it = max_element(contador.begin(), contador.end(), [] (const pair<Parte*, int>& a, const pair<Parte*, int>& b{
			return a.second < b.second });

		cout << "Parte mC!s usada: " << it->second;
	}



	void biciConMasComponentes() {
		auto it = max_element(bici.begin(), bici.end(), [] (const Bicicleta* a, Bicicleta* b) {
			return a -> partes.size() < b -> partes.size()
		});
		cout << "Bici con mas componentes: " << (*it)->idBici;


	}


}

