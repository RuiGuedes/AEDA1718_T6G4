#include "Utilizacao.h"

////////////////
// UTILIZACAO //
////////////////

Utilizacao::Utilizacao(){
	this->bikeType = " ";
	this->useTime = 0;
}

Utilizacao::Utilizacao(string bikeType, unsigned int numHours, Data d) {
	this->bikeType = bikeType;
	this->useTime = numHours;
	this->data=d;
}

void Utilizacao::displayUtilizacao() {

	cout << "Tipo de bicicleta: " << bikeType << endl;
	cout << "Número de horas: " << useTime << endl;
	cout << "Data (DD/MM/AAAA): " << data << endl;

}

/////////////////
// METODOS GET //
/////////////////

Data Utilizacao::getData()const {
	return data;
}

unsigned int Utilizacao::getUseTime() const {
	return useTime;
}

string Utilizacao::getBikeType() const {
	return bikeType;
}


//////////
// DATA //
//////////

Data::Data(){ dia=0; mes=0; ano=0;}

Data::Data(unsigned int dia,unsigned int mes,unsigned int ano){
	this->dia=dia;
	this->mes=mes;
	this->ano=ano;
}

/////////////////
// METODOS GET //
/////////////////

unsigned int Data::getDia() const { return dia; }
unsigned int Data::getMes() const { return mes; }
unsigned int Data::getAno() const { return ano; }

/////////////////
// METODOS SET //
/////////////////

void Data::setDia(unsigned int d){
	this->dia=d;
}
void Data::setMes(unsigned int m){
	this->mes=m;
}
void Data::setAno(unsigned int a){
	this->ano=a;
}


