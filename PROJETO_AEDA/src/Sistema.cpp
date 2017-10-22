#include "Sistema.h"

void Sistema::addNewUtente(Utente *utente) {
	utentes.push_back(utente);
	return;
}

void Sistema::addPontoPartilha(PontoPartilha* spot) {
	pontosPartilha.push_back(spot);
}

/////////////////
// METODOS GET //
/////////////////
vector<Utente* > Sistema::getUtentes() const {
	return utentes;
}

vector<PontoPartilha* > Sistema::getPontosPartilha() const {
	return pontosPartilha;
}

