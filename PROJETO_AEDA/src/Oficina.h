#pragma once

#include "Includes.h"
#include "Bicicleta.h"
#include "BST.h"
#include "Peca.h"

class Oficina {
	BST<Peca> pieces;
	vector<Bicicleta *> brokenBikes;
public:
	/**
	 *  Construtor padrao da classe Oficina
	 */
	Oficina() : pieces(Peca(0,"","")) {}

	//Métodos Get
	vector<Bicicleta *> getBrokenBikes() const;

	//Métodos Set
	void setBrokenBikes(vector<Bicicleta *> newBrokenBikes);

	//Métodos Add
	void addBrokenBike(Bicicleta * bike);
	void addPiece();

	//Métodos Remove
	void removePieceBST();
	void removePieceBike(int index, string piece);

	//Métodos Display
	void displayBSTInfo();
	void displayBrokenBikeInfo();
	void displayPiecePrices();

	//Others
	void buyPiece();
};
