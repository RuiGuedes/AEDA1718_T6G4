#include "Loja.h"


Loja::Loja() {
	vector<unsigned int> init;
	stock = init;
	capacity = 0;
	numberOpinions = 0;
	reputation = 0;
}

Loja::Loja(Localizacao spot, unsigned int capacity, vector<unsigned int> stock) {
	local = spot;
	this->capacity = capacity;
	this->stock = stock;
	this->numberOpinions = 0;
	this->reputation = 0;
}

/////////////////
// METODOS GET //
/////////////////

double Loja::getReputation() const {
	return ((double)reputation/numberOpinions);
}

unsigned int Loja::getNumberOpinions() const {
	return numberOpinions;
}

unsigned int Loja::getCapacity() const {
	return capacity;
}

unsigned int Loja::getStock(unsigned int it) const {
	return stock.at(it);
}


/////////////////
// METODOS SET //
/////////////////

void Loja::setReputation(unsigned int reputation) {
	this->reputation = this->reputation + reputation;
}

void Loja::setNumberOpinions() {
	numberOpinions++;
}

void Loja::setCapacity(unsigned int capacity) {
	this->capacity = capacity;
}

////////////
// OTHERS //
////////////

bool Loja::operator<(const Loja& l1) const {

	if(this->reputation > l1.getReputation())
		return true;

	return false;

}
