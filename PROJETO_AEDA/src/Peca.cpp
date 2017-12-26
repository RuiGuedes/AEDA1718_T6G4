#include "Peca.h"

Peca::Peca(unsigned int lastPurchasePrice, string pieceType, string supplier) {
	this->lastPurchasePrice = lastPurchasePrice;
	this->pieceType = pieceType;
	this->supplier = supplier;
}


bool Peca::operator< (const Peca &pt1) const {
	if(this->pieceType < pt1.getPieceType())
		return true;
	else if(this->pieceType == pt1.getPieceType())
	{
		if(this->lastPurchasePrice <= pt1.getLastPurchasePrice())
			return true;
	}
	return false;
}

bool Peca::operator==(const Peca &ps1) const {
	if((this->pieceType == ps1.getPieceType()) && (this->supplier == ps1.getSupplier()))
		return true;

	return false;
}

/////////////////
// METODOS GET //
/////////////////

unsigned int Peca::getLastPurchasePrice() const {
	return lastPurchasePrice;
}

string Peca::getPieceType() const {
	return pieceType;
}

string Peca::getSupplier() const {
	return supplier;
}


/////////////////
// METODOS SET //
/////////////////

void Peca::setLastPurchasePrice(unsigned int lastPurchasePrice) {
	this->lastPurchasePrice = lastPurchasePrice;
}

void Peca::setPieceType(string pieceType) {
	this->pieceType = pieceType;
}

void Peca::setSupplier(string supplier) {
	this->supplier = supplier;
}

