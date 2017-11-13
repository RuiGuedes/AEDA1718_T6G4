#pragma once

#include "Includes.h"
#include "Utente.h"
#include "PontoPartilha.h"

class Sistema {
	vector<PontoPartilha* > pontosPartilha;
	vector<Utente* > utentes;
public:
	Sistema() {}
	void addPontoPartilha(PontoPartilha* spot); 	 //Criacao de uma nova loja
	void addNewUtente(Utente* utente);	 		 	//Adiciona um novo utente
	void removePonto(int indexPP);
	void removeUtente(int indexUT);

	//Metodos Get
	vector<Utente* > getUtentes();
	vector<PontoPartilha* > getPontosPartilha();

};

