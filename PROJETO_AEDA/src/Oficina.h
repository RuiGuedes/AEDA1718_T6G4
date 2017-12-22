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
	// -> Comprar uma pe�a, a determinado pre�o e a determinado fornecedor
	// -> Verificar qual o fornecedor que vendeu determinada pe�a a pre�o mais baixo.
	// -> Remover pe�as (BST)
	// -> Adicionar pe�as (BST)
	// -> Deve ser ainda poss�vel obter uma listagem dos fornecedores e valores das �ltimas compras de determinadas pe�as em especifico.

};
