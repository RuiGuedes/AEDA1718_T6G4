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

	//M�todos Get
	vector<Bicicleta *> getBrokenBikes() const;

	//M�todos Set
	void setBrokenBikes(vector<Bicicleta *> newBrokenBikes);

	//M�todos Add
	void addBrokenBike(Bicicleta * bike);
	void addPiece();

	//M�todos Remove
	void removePieceBST();
	void removePieceBike(int index, string piece);

	//M�todos Display
	void displayBSTInfo();
	void displayBrokenBikeInfo();
	void displayPiecePrices();

	//Others
	void buyPiece();
};
