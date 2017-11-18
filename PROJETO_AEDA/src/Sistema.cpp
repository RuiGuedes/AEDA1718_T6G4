#include "Sistema.h"

/**
 * Adiciona um novo utente ao sistema
 * @param utente utente que pretende adicionar
 */
void Sistema::addNewUtente(Utente *utente) {
	utentes.push_back(utente);
	return;
}

/**
 * Adiciona um novo ponto de partilha ao sistema
 * @param spot ponto de partilha que pretende adicionar
 */
void Sistema::addPontoPartilha(PontoPartilha* spot) {
	pontosPartilha.push_back(spot);
}

/**
 * Remove um novo ponto de partilha do sistema
 * @param indexPP indice do ponto de partilha que pretende remover
 */
void Sistema::removePonto(int indexPP) {

	pontosPartilha.erase(pontosPartilha.begin() + indexPP);
	return;
}

/**
 * Remove um novo utente ao sistema
 * @param indexUT indice do utente que pretende remover
 */
void Sistema::removeUtente(int indexUT) {

	utentes.erase(utentes.begin() + indexUT);
	return;
}


/////////////////
// METODOS GET //
/////////////////

/**
 * Retorna o vetor de apontadores para os utentes registados no sistema
 *
 * @return Retorna um vetor de utentes
 */
vector<Utente* > Sistema::getUtentes(){
	return utentes;
}

/**
 * Retorna o vetor de apontadores para os pontos de partilha existentes no sistema
 *
 * @return Retorna um vetor de pontos de partilha
 */
vector<PontoPartilha* > Sistema::getPontosPartilha() {
	return pontosPartilha;
}



