#pragma once

#include "Includes.h"

class Bicicleta {
	string bikeType;
	string bikeName;
	bool disponivel;  //True -> Disponivel || False -> Indisponivel
public:
	Bicicleta();
	Bicicleta(string tipo, string name);

	//Metodos Get
	string getBikeType() const;
	string getBikeName() const;
	bool getBikeAvailable() const;

	//Metodos Set
	void setBikeAvailable();

	friend ostream & operator <<(ostream & o, const Bicicleta & b);
	friend istream & operator >>(istream & i, Bicicleta & b);
};

inline ostream& operator <<(ostream & o, const Bicicleta & b)
{
	o << b.bikeName << '/' << b.bikeType << '/' << b.disponivel;
	return o;
}

inline istream& operator >>(istream & i, Bicicleta & b)
{
	char b1, b2;
	i >>  b.bikeName >> b1 >> b.bikeType >> b2 >> b.disponivel;
	return i;
}

