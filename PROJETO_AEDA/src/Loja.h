#pragma once

#include "Includes.h"
#include "Localizacao.h"

class Loja {
	Localizacao* local;
	unsigned int reputation;
	unsigned int numberOpinions;
	unsigned int capacity;
	vector<unsigned int> stock;
public:
	Loja();
	Loja(Localizacao* spot, unsigned int capacity, vector<unsigned int> stock);

	//Metodos Get
	double getReputation() const;
	unsigned int getNumberOpinions() const;
	unsigned int getCapacity() const;
	unsigned int getStock(unsigned int it) const;
	Localizacao* getLocal() const;

	//Metodos Set
	void setReputation(unsigned int reputation);
	void setNumberOpinions();
	void setCapacity(unsigned int capacity);

	//Others
	bool operator<(const Loja& l1) const;
};
