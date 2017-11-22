#pragma once

#include "Includes.h"
#include "Utente.h"
#include "PontoPartilha.h"
#include "Exceções.h"
#include "Localizacao.h"

class Sistema {
	vector<PontoPartilha* > pontosPartilha;
	vector<Utente* > utentes;
public:
	Sistema() {}
	void addPontoPartilha();				/**< Criação de uma nova loja */
	void addNewUtente();					/**< Adiciona um novo utente */
	void removePonto();
	void removeUtente();
	void System_Manager(unsigned int index, string bikeType);
	void infoER() const;

	//Métodos Get
	vector<Utente* > getUtentes();
	vector<PontoPartilha* > getPontosPartilha();
};
