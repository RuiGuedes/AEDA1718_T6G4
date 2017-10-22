#pragma once

#include "Includes.h"

class Bicicleta {
	string bikeType;
	bool disponivel;  //True -> Disponivel || False -> Indisponivel
public:
	Bicicleta(string tipo);

	//Metodos Get
	string getBikeType() const;
	bool getBikeAvailable() const;

	//Metodos Set
	void setBikeAvailable();
};
