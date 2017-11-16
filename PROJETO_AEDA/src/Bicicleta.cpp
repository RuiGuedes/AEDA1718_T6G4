#include "Bicicleta.h"

Bicicleta::Bicicleta(){};

Bicicleta::Bicicleta(string tipo, string name) {
	bikeType = tipo;
	bikeName = name;
}

/////////////////
// METODOS GET //
/////////////////

string Bicicleta::getBikeType() const {
	return bikeType;
}

string Bicicleta::getBikeName() const {
	return bikeName;
}

