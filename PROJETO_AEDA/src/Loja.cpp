#include "Loja.h"

/**
 * Construtor Padrao da classe Loja
 */
Loja::Loja() {
	local = new Localizacao();
	vector<unsigned int> init;
	stock = init;
	capacity = 0;
	numberOpinions = 0;
	reputation = 0;
}

/**
 * Construtor da classe Loja
 * @param spot apontador para a Localizacao da loja
 * @param capacity capacidade de stock da loja
 * @param stock quantidade de bicicletas de cada tipo (stock[0] = num_Urbanas, stock[1] = num_Urbanas_Simples, stock[2] = num_Corrida, stock[3] = num_Infantis )
 */
Loja::Loja(Localizacao* spot, unsigned int capacity, vector<unsigned int> stock) {
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

	if(numberOpinions != 0)
		return ((double)reputation/numberOpinions);

	return 0;
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

Localizacao* Loja::getLocal() const {
	return local;
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

void Loja::setStock(int index, int bikes) {

	this->stock.at(index) = stock.at(index) - bikes;
}

////////////
// OTHERS //
////////////

bool Loja::operator<(const Loja& l1) const {

	if(this->reputation < l1.getReputation())
		return true;

	return false;

}

void Loja::checkStock(int index) {

	if(stock.at(index) <= 1)
	{
		stock.at(index) = (int)capacity / 4;

		unsigned int sum { stock.at(0) + stock.at(1) + stock.at(2) + stock.at(3) };

		if(sum < capacity)
			stock.at(index)++;
	}

}
