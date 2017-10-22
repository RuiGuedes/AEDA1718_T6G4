#include "Bicicleta.h"

Bicicleta::Bicicleta(string tipo, string name) {
	bikeType = tipo;
	bikeName = name;
	disponivel = true;
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

bool Bicicleta::getBikeAvailable() const {
	return disponivel;
}

/////////////////
// METODOS SET //
/////////////////
void Bicicleta::setBikeAvailable() {

	if(disponivel == true)
		disponivel = false;
	else
		disponivel = true;

	return;
}
