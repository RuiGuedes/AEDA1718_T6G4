#include "PontoPartilha.h"
#include "Utente.h"
#include <vector>
#include <string>

using namespace std;

class Sistema {
	vector<PontoPartilha* > pontosPartilha;
	vector<Utente* > utentes;
public:
	Sistema();
	void addPontoPartilha(Utente* utente);  //Criacao de uma nova loja
	void addNewUtente(Utente* utente);	  //Adiciona um novo utente

};
