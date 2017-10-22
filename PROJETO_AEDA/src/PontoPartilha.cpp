#include "PontoPartilha.h"

PontoPartilha::PontoPartilha(Localizacao spot,unsigned int storage) {
	local = spot;
	capacidade = storage;
}



void  PontoPartilha::removeBike(Utente utente) {
	Bicicleta* bike = utente.getBike();

}

	//Metodos get
	Localizacao getLocal() const;
	int getCapacidade() const;
	int getNumberOfBikes() const;
	vector <vector<Bicicleta *> > getBikeTypes();
