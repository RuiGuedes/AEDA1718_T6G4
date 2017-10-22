#pragma once

#include "Includes.h"

class Bicicleta {
	string bikeType;
	string bikeName;
	bool disponivel;  //True -> Disponivel || False -> Indisponivel
public:
	Bicicleta(string tipo, string name);

	//Metodos Get
	string getBikeType() const;
	string getBikeName() const;
	bool getBikeAvailable() const;

	//Metodos Set
	void setBikeAvailable();
};
