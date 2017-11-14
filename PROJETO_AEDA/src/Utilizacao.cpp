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

Utilizacao::Utilizacao(string bikeType, unsigned int numHours, Data d, string pp, string loc) {
	this->bikeType = bikeType;
	this->useTime = numHours;
	this->data=d;
	this->pontoPartilha = pp;
	this->localizacao = loc;
}

void Utilizacao::displayUtilizacao() {

	cout << "Tipo de bicicleta: " << bikeType << endl;
	cout << "Número de horas: " << useTime << endl;
	cout << "Data (DD/MM/AAAA): " << data << endl;
	cout << "Ponto Partilha: ECO_RIDES_" << pontoPartilha << endl;
	cout << "Localização: " << localizacao << endl;

	return;

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

double Utilizacao::getPrice() const {

	if(bikeType == "Urbana")
		return useTime*4;
	else if(bikeType == "Urbana Simples")
		return useTime*3;
	else if(bikeType == "Corrida")
		return useTime*5;
	else //bikeType == "Infantil"
		return useTime*2;
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


