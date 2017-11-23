#pragma once

#include "Includes.h"
#include "Utente.h"
#include "PontoPartilha.h"
#include "Exce��es.h"
#include "Localizacao.h"

class Sistema {
	vector<PontoPartilha* > pontosPartilha;
	vector<Utente* > utentes;
public:
	Sistema() {}

	//M�todos add
	void addPontoPartilha();				/**< Cria��o de uma nova loja */
	void addNewUtente();					/**< Adiciona um novo utente */
	void adicionaBike();
	void addNewUtente(Utente* u1);			//para ficheiros
	void addPontoPartilha(PontoPartilha* p);	//para ficherios

	//M�todos remove
	void removePonto();
	void removeUtente();
	void removeBike();

	//Others
	void alugaBike(int index);
	void devolveBike(int index);
	void mudaTipoUT(int index);
	void system_Manager(unsigned int index, string bikeType);
	void displayNearestPP(int index);
	void displayUtentes();

	//M�todos Get
	vector<Utente* > getUtentes();
	vector<PontoPartilha* > getPontosPartilha();
	void getInfo();
	vector<int> getOrderedPP(int index);
	int getUtenteIndex(int identificacao);
};
