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




Data::Data(){ dia=0; mes=0; ano=0;}

Data::Data(unsigned int dia,unsigned int mes,unsigned int ano){
	this->dia=dia;
	this->mes=mes;
	this->ano=ano;
}

unsigned int Data::getDia() const { return dia; }
unsigned int Data::getMes() const { return mes; }
unsigned int Data::getAno() const { return ano; }

void Data::setDia(unsigned int d){
	this->dia=d;
}
void Data::setMes(unsigned int m){
	this->mes=m;
}
void Data::setAno(unsigned int a){
	this->ano=a;
}

