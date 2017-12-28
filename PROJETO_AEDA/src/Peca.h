#pragma once

#include "Includes.h"


class Peca {
	unsigned int lastPurchasePrice;
	string pieceType;
	string supplier;
public:

	Peca(unsigned int lastPurchasePrice, string pieceType, string supplier);

	//Métodos Get
	unsigned int getLastPurchasePrice() const;
	string getPieceType() const;
	string getSupplier() const;

	//Métodos Set
	void setLastPurchasePrice(unsigned int lastPurchasePrice);
	void setPieceType(string pieceType);
	void setSupplier(string supplier);

	//Others
	bool operator< (const Peca &ps1) const;
	bool operator==(const Peca &ps1) const;
	friend ostream & operator <<(ostream & o, const Peca & p);
	friend istream & operator >>(istream & i, Peca & p);
};


inline ostream& operator <<(ostream & o, const Peca & p)
{
	o << p.lastPurchasePrice << ',' << p.pieceType << ',' << p.supplier ;
	return o;
}

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Peca,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Peca & p) {
	char b1;

	i >> p.lastPurchasePrice >> b1;
	getline(i, p.pieceType, ',');
	getline(i, p.supplier, '\n');

	return i;
}
