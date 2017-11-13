#pragma once

#include "Includes.h"

class Bicicleta {
	string bikeType;
	string bikeName;
	bool disponivel;  //True -> Disponivel || False -> Indisponivel
public:
	Bicicleta();
	Bicicleta(string tipo, string name);
	friend ostream & operator <<(ostream & o, const Bicicleta & b);
	friend istream & operator >>(istream & i, Bicicleta & b);

	//Metodos Get
	string getBikeType() const;
	string getBikeName() const;
	bool getBikeAvailable() const;

	//Metodos Set
	void setBikeAvailable();

};

inline ostream& operator <<(ostream & o, const Bicicleta & b)
{
	o << b.bikeName << '/' << b.bikeType << '/' << b.disponivel;
	return o;
}

inline istream& operator >>(istream & i, Bicicleta & b)
{
	getline(i,b.bikeName,'/');
	getline(i,b.bikeType,'/');
	i >> b.disponivel;

	return i;
}

