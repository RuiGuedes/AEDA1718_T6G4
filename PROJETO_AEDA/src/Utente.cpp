#include "Utente.h"

using namespace std;

Utente::Utente(string nome, string tipoUtente)
{
	this->nome = nome;
	this->tipoUtente = tipoUtente;
	this->bike = 0;

}

string Utente::getTipoUtente() const {

	return this->tipoUtente;
}
