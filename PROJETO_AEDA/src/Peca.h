#pragma once

#include "Includes.h"


class Peca {
	unsigned int lastPurchasePrice;
	string pieceType;
	string supplier;
public:

	Peca(unsigned int lastPurchasePrice, string pieceType, string supplier);

	//M�todos Get
	unsigned int getLastPurchasePrice() const;
	string getPieceType() const;
	string getSupplier() const;

	//M�todos Set
	void setLastPurchasePrice(unsigned int lastPurchasePrice);
	void setPieceType(string pieceType);
	void setSupplier(string supplier);

	//Others
	bool operator < (const Peca &ps1) const;
};
