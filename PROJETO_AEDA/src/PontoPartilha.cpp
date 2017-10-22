#include "PontoPartilha.h"

////////////
// OTHERS //
////////////

PontoPartilha::PontoPartilha(Localizacao spot,unsigned int storage) {
	local = spot;
	capacidade = storage;
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
		bikeTypes.push_back("urbana");
	else if(bicicletas.at(1).size() != 0)
		bikeTypes.push_back("urbanaSimples");
	else if(bicicletas.at(2).size() != 0)
		bikeTypes.push_back("corrida");
	else if(bicicletas.at(3).size() != 0)
		bikeTypes.push_back("infantil");

	return bikeTypes;
}


////////////
// OTHERS //
////////////

void  PontoPartilha::removeBike(Utente utente) {

	Bicicleta* bike = utente.getBike();

	int indicator;
	string tipo = bike->getBikeType();
	string name = bike->getBikeName();

	if(tipo == "urbana")
		indicator = 0;
	else if(tipo == "urbanaSimples")
		indicator = 1;
	else if(tipo == "corrida")
		indicator = 2;
	else if(tipo == "infantil")
		indicator = 3;

	for(unsigned int i = 0; bicicletas.at(indicator).size(); i++)
	{
		if(bicicletas.at(indicator).at(i)->getBikeName() == name)
			bicicletas.at(indicator).erase(bicicletas.at(indicator).begin() + i);
	}

}
