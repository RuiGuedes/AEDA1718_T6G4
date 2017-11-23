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
	void addPontoPartilha();
	void addNewUtente();
	void adicionaBike();
	void addNewUtente(Utente* u1);
	void addPontoPartilha(PontoPartilha* p);

	//M�todos remove
	void removePonto();
	void removeUtente();
	void removeBike();

	//M�todos Get
	vector<Utente* > getUtentes() const;
	vector<PontoPartilha* > getPontosPartilha() const;
	void getInfo() const;
	vector<int> getOrderedPP(int index) const;
	int getUtenteIndex(int identificacao) const;

	//Others
	void alugaBike(int index);
	void devolveBike(int index);
	void mudaTipoUT(int index);
	void system_Manager(unsigned int index, string bikeType);
	void displayNearestPP(int index) const;
	void displayUtentes() const;

};

/**
 * Procura um valor x num vetor v de elementos comparaveis com os operadores de comparacao.
 * @param v vetor de elementos
 * @param x valor a procurar no vetor
 * @return Retorna o indice da primeira ocorrencia de x em v, se encontrar; senao, retorna -1.
 */
template <class T>
int SequentialSearch(const vector<T> &v, T x)
{
	for (unsigned int i = 0; i < v.size(); i++)
		if (v[i] == x)
			return i;// encontrou
	return -1; // n�o encontrou
}


