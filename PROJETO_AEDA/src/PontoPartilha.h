#pragma once
#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utente.h"

class PontoPartilha {
	Localizacao local;
	unsigned int capacidade;
	vector <vector<Bicicleta *> > bicicletas;
	string nome;
public:
	PontoPartilha(Localizacao spot,unsigned int storage,string name);

	//Metodos get
	Localizacao getLocal() const;
	string getNome() const { return nome; }
	int getCapacidade() const;
	int getNumberOfBikes() const;
	vector <string> getBikeTypes();
	vector <vector<Bicicleta *> > getBikes() const;

	//Metodos set
	void removeBike(Bicicleta *bike);
	void adicionaBike(Bicicleta* bike);
};
