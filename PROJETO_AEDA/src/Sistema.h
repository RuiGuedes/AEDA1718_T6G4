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
	void adicionaBike();
	void removePonto();
	void removeUtente();
	void removeBike();
	void alugaBike(int index);
	void devolveBike(int index);
	void mudaTipoUT(int index);
	void System_Manager(unsigned int index, string bikeType);
	void infoER();


	//Metodos para extracao dos ficheiros
	void addNewUtente(Utente* u1);
	void addPontoPartilha(PontoPartilha* p);


	//Métodos Get
	vector<Utente* > getUtentes();
	vector<PontoPartilha* > getPontosPartilha();
	vector<int> ExtraData(int index);
};
