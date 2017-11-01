#include "PontoPartilha.h"

////////////
// OTHERS //
////////////

PontoPartilha::PontoPartilha(Localizacao spot,unsigned int storage) {
	local = spot;
	capacidade = storage;
	vector<Bicicleta *> v1,v2,v3,v4;
	bicicletas.push_back(v1);
	bicicletas.push_back(v2);
	bicicletas.push_back(v3);
	bicicletas.push_back(v4);
}

/////////////////
// METODOS GET //
/////////////////

Localizacao PontoPartilha::getLocal() const {
	return local;
}

int PontoPartilha::getCapacidade() const {
	return capacidade;
}

int PontoPartilha::getNumberOfBikes() const {

	int number_bikes = 0;

	for(unsigned int i = 0; i < bicicletas.size(); i++)
	{
		number_bikes += bicicletas.at(i).size();
	}

	return number_bikes;
}

vector <string> PontoPartilha::getBikeTypes() {

	vector <string> bikeTypes;

	if(bicicletas.at(0).size() != 0)
		bikeTypes.push_back("Urbana");

	if(bicicletas.at(1).size() != 0)
		bikeTypes.push_back("Urbana Simples");

	if(bicicletas.at(2).size() != 0)
		bikeTypes.push_back("Corrida");

	if(bicicletas.at(3).size() != 0)
		bikeTypes.push_back("Infantil");

	return bikeTypes;
}


vector <vector<Bicicleta *> > PontoPartilha::getBikes() const {

	return bicicletas;
}

////////////
// OTHERS //
////////////

void  PontoPartilha::removeBike(Bicicleta *bike) {

	vector<Bicicleta *> bikes;

	int indicator;
	string tipo = bike->getBikeType();
	string name = bike->getBikeName();

	if(tipo == "Urbana")
		indicator = 0;
	else if(tipo == "Urbana Simples")
		indicator = 1;
	else if(tipo == "Corrida")
		indicator = 2;
	else if(tipo == "Infantil")
		indicator = 3;

	for(unsigned int i = 0; i < bicicletas.at(indicator).size(); i++)
	{
		if(bicicletas.at(indicator).at(i)->getBikeName() == name)
			bicicletas.at(indicator).erase(bicicletas.at(indicator).begin() + i);
	}

}

void PontoPartilha::adicionaBike(Bicicleta* bike) {

	int indicator;
	string tipo = bike->getBikeType();

	if(tipo == "Urbana")
		indicator = 0;
	else if(tipo == "Urbana Simples")
		indicator = 1;
	else if(tipo == "Corrida")
		indicator = 2;
	else if(tipo == "Infantil")
		indicator = 3;


	bicicletas.at(indicator).push_back(bike);

	return;
}
