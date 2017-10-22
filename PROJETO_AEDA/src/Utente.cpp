#include "Utente.h"

int Utente::lastId = 0;

Utente::Utente(string nome, string tipoUtente) : id(++lastId)
{
	this->nome = nome;
	this->tipoUtente = tipoUtente;
	this->bike = 0;

}

/////////////////
// METODOS GET //
/////////////////

int Utente::getId() const {
	return id;
}

string Utente::getUtenteNome() const {
	return nome;
}

string Utente::getTipoUtente() const {

	return tipoUtente;
}

Localizacao Utente::getLocalizacao() const {
	return local;
}

Bicicleta* Utente::getBike() const {
	return bike;
}

/////////////////
// METODOS SET //
/////////////////

void Utente::setUtenteLocation(Localizacao spot) {
	local = spot;
	return;
}

void Utente::setTipoUtente(int tipo) {

	string type = this->getTipoUtente();
	string conversion;

	if(tipo == 1)
		conversion = "Socio";
	else
		conversion = "Regular";

	if(conversion == type)
		cout << "Este utente j� se encontra definido como do tipo " << type << ".\n";

	else {
		//Efetua pagamento
		this->updateHistoric();
		//Muda tipo
		this->tipoUtente = conversion;
		cout << "O utente com o ID = " << this->getId() << " � agora do tipo:  " << conversion << ".\n";

	}

	return;
}


////////////
// OTHERS //
////////////

void Utente::updateHistoric() {

	for(unsigned int i = 0; i < utilizacoes.size(); i+=0)
	{
		historico.push_back(utilizacoes.at(i));
		utilizacoes.erase(utilizacoes.begin() + i);
	}
}

void Utente::alugaBicicleta(string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano) {

	//Verifica a localiza��o do utente
	Localizacao spot = this->getLocalizacao();

	//Descobre os ponto de partilha mais pr�ximos e retorna-os num vetor por ordem crescente de proximidade

	//Verifica por ordem se tem o tipo de bicleta pretendida

	//Se tiver: atribui a bicicleta ao utente e remove-a do pontopartilha e regista a utilizacao

	//Sen�o tiver: faz cout "Neste momento n�o � possivel alugar a bicicleta do tipo (bikeType)

	return;
}
