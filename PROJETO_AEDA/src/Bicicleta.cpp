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
Bicicleta::Bicicleta(string tipo, string name) {
	bikeType = tipo;
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

