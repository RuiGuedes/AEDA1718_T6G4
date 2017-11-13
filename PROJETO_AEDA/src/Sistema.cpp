#include "Sistema.h"

void Sistema::addNewUtente(Utente *utente) {
	utentes.push_back(utente);
	return;
}

void Sistema::addPontoPartilha(PontoPartilha* spot) {
	pontosPartilha.push_back(spot);
}

void Sistema::removePonto(int indexPP) {

	pontosPartilha.erase(pontosPartilha.begin() + indexPP);
	return;
}

void Sistema::removeUtente(int indexUT) {

	utentes.erase(utentes.begin() + indexUT);
	return;
}


/////////////////
// METODOS GET //
/////////////////

vector<Utente* > Sistema::getUtentes(){
	return utentes;
}

vector<PontoPartilha* > Sistema::getPontosPartilha() {
	return pontosPartilha;
}



