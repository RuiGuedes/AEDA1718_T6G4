#pragma once

#include "Includes.h"

class Utilizacao {
private:
	unsigned int dia, mes, ano;
	unsigned int useTime;
	string bikeType;
public:
	Utilizacao(string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano);

	//Metodos get
	unsigned int getdia() const;
	unsigned int getmes() const;
	unsigned int getano() const;
	unsigned int getUseTime() const;
	string getBikeType() const;
};
