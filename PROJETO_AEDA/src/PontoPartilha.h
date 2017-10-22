#pragma once

#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utente.h"

class PontoPartilha {
	Localizacao local;
	unsigned int capacidade;
	vector <vector<Bicicleta *> > bicicletas;
public:
	PontoPartilha(Localizacao spot,unsigned int storage);
	void removeBike(Utente utente);

	//Metodos get
	Localizacao getLocal() const;
	int getCapacidade() const;
	int getNumberOfBikes() const;
	vector <string> getBikeTypes();

	//Metodos set

};
