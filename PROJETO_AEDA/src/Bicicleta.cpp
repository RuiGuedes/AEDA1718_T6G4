#include "Bicicleta.h"

Bicicleta::Bicicleta(string tipo) {
	bikeType = tipo;
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
