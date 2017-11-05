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
	PontoPartilha();
	PontoPartilha(Localizacao spot,unsigned int storage,string name);

	//Metodos get
	Localizacao getLocal() const;
	string getNome() const { return nome; }
	int getCapacidade() const;
	vector<int> getNumberOfBikes() const; // numero de bicicletas de cada tipo
	vector <string> getBikeTypes();
	vector <vector<Bicicleta *> > getBikes() const;

	//Metodos set
	void removeBike(Bicicleta *bike);
	void adicionaBike(Bicicleta* bike);
	void limpaVectorBike();
	friend void ordenaPorDistancia(Localizacao local, vector<PontoPartilha*> pontos);
	friend ostream & operator <<(ostream & o, const PontoPartilha & p);
	friend istream & operator >>(istream & i, PontoPartilha & p);
};

inline ostream& operator <<(ostream & o, const PontoPartilha & p)
{
	o << p.nome << '/' << p.local << '/' << p.capacidade << '[' << p.bicicletas.at(0).size() << ','
			<< p.bicicletas.at(1).size() << ',' << p.bicicletas.at(2).size() << ',' << p.bicicletas.at(3).size() << ']';
	return o;
}

inline istream& operator >>(istream & i, PontoPartilha & p)
{
	char b1, b2, b3, b4, b5, b6;
	unsigned int u,uc,c,inf; //4 tipos de bicicletas
	vector<Bicicleta *> v1,v2,v3,v4;
	vector <vector<Bicicleta *> > bikes{v1,v2,v3,v4};

	Bicicleta * b; //apontador generico apenas para reservar espaco no vetor

	getline(i,p.nome,'/');
	i >> p.local >> b1 >> p.capacidade >> b2 >> u >> b3 >> uc >> b4 >> c >> b5 >> inf >> b6;

	for (unsigned int k=0 ; k<u ; k++){
		bikes.at(0).push_back(b);
	}
	for (unsigned int k=0 ; k<uc ; k++){
		bikes.at(1).push_back(b);
	}
	for (unsigned int k=0 ; k<c ; k++){
		bikes.at(2).push_back(b);
	}
	for (unsigned int k=0 ; k<inf ; k++){
		bikes.at(3).push_back(b);
	}

	p.bicicletas=bikes;
	return i;
}
