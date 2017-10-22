#include "Utilizacao.h"

Utilizacao::Utilizacao(string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano) {
	this->bikeType = bikeType;
	useTime = numHours;

	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

/////////////////
// METODOS GET //
/////////////////

unsigned int Utilizacao::getdia()const {
	return dia;
}

unsigned int Utilizacao::getmes()const {
	return mes;
}

unsigned int Utilizacao::getano()const {
	return ano;
}

unsigned int Utilizacao::getUseTime() const {
	return useTime;
}

string Utilizacao::getBikeType() const {
	return bikeType;
}
