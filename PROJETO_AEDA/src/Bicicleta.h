#pragma once

#include "Includes.h"

class Bicicleta {
	string bikeType;
	string bikeName;
public:
	Bicicleta();
	Bicicleta(string tipo, string name);
	friend ostream & operator <<(ostream & o, const Bicicleta & b);
	friend istream & operator >>(istream & i, Bicicleta & b);

	//Métodos Get
	string getBikeType() const;
	string getBikeName() const;
};

inline ostream& operator <<(ostream & o, const Bicicleta & b)
{
	o << b.bikeName << '/' << b.bikeType << '/';
	return o;
};

inline istream& operator >>(istream & i, Bicicleta & b)
{
	getline(i,b.bikeName,'/');
	getline(i,b.bikeType,'/');
	return i;
};
