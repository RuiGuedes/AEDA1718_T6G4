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

	//Others
	void addBrokenBike(Bicicleta * bike);
	void addPiece();
	void removePiece();

	void displayBSTInfo();
	void displayBrokenBikeInfo();
};
