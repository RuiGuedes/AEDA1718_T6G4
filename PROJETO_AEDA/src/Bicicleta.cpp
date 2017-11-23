#include "Bicicleta.h"

/**
 * Construtor padrao da classe Bicicleta
 */
Bicicleta::Bicicleta(){};

/**
 * Construtor da classe Bicicleta
 * @param tipo tipo de bicicleta
 * @param name nome da bicicleta
 */
Bicicleta::Bicicleta(string name) {

	bikeName = name;

}

/////////////////
// METODOS GET //
/////////////////

/**
 * @return Retorna o tipo da bicicleta
 */
string Bicicleta::getBikeType() const {
	return bikeType;
}

/**
 * @return Retorna o nome da bicicleta
 */
string Bicicleta::getBikeName() const {
	return bikeName;
}

int Bicicleta::getPrice() const {
	return price;
}

int Urbana::id = 0;

Urbana::Urbana(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 40;

}

int UrbanaSimples::id = 0;

UrbanaSimples::UrbanaSimples(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 30;

}

int Corrida::id = 0;

Corrida::Corrida(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 50;

}

int Infantil::id = 0;

Infantil::Infantil(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 20;

}
