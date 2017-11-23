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
 * @return Retorna o nome da bicicleta
 */
string Bicicleta::getBikeName() const {
	return bikeName;
}

int Bicicleta::getPrice() const {
	return price;
}

int Urbana::id = 1;

Urbana::Urbana(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 40;

}

int Urbana::getID() {
	return id;
}

int UrbanaSimples::id = 1;

UrbanaSimples::UrbanaSimples(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 30;

}

int UrbanaSimples::getID() {
	return id++;
}

int Corrida::id = 1;

Corrida::Corrida(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 50;

}

int Corrida::getID() {
	return id;
}

int Infantil::id = 1;

Infantil::Infantil(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 20;

}

int Infantil::getID() {
	return id;
}
