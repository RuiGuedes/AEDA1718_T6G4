#include "Bicicleta.h"

// ATRIBUTOS ESTATICOS //

int Urbana::id = 1;
int UrbanaSimples::id = 1;
int Corrida::id = 1;
int Infantil::id = 1;


//////////////////////
// CLASSE BICICLETA //
//////////////////////

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


// METODOS GET //

/**
 * @return Retorna o nome da bicicleta
 */
string Bicicleta::getBikeName() const {
	return bikeName;
}

int Bicicleta::getPrice() const {
	return price;
}

///////////////////
// CLASSE URBANA //
///////////////////

Urbana::Urbana(string bikeName) : Bicicleta(bikeName){

	id++;
	price = 40;

}


// METODOS GET //

int Urbana::getID() {
	return id;
}


///////////////////////////
// CLASSE URBANA_SIMPLES //
///////////////////////////

UrbanaSimples::UrbanaSimples(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 30;
}


// METODOS GET //

int UrbanaSimples::getID() {
	return id++;
}

////////////////////
// CLASSE CORRIDA //
////////////////////

Corrida::Corrida(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 50;
}


// METODOS GET //

int Corrida::getID() {
	return id;
}

/////////////////////
// CLASSE INFANTIL //
/////////////////////

Infantil::Infantil(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 20;
}


// METODOS GET //

int Infantil::getID() {
	return id;
}
