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

	//Funcionalidades
	// -> Comprar uma peça, a determinado preço e a determinado fornecedor
	// -> Verificar qual o fornecedor que vendeu determinada peça a preço mais baixo.
	// -> Remover peças (BST)
	// -> Adicionar peças (BST)
	// -> Deve ser ainda possível obter uma listagem dos fornecedores e valores das últimas compras de determinadas peças em especifico.

};
