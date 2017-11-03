#include "Utente.h"

int Utente::lastId = 0;

Utente::Utente(string nome, string tipoUtente,Localizacao spot) : id(++lastId)
{
	this->nome = nome;
	this->tipoUtente = tipoUtente;
	this->bike = 0;
	local = spot;

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

vector<Utilizacao> Utente::getUtilizacoes() {
	return utilizacoes;
}

bool Utente::getAvailable() const {
	return disponivel;
}

vector<Utilizacao> Utente::getHistorico() {
	return this->historico;
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
		cout << "Este utente já se encontra definido como do tipo " << type << ".\n";

	else {
		//Efetua pagamento
		this->updateHistoric();
		//Muda tipo
		this->tipoUtente = conversion;
		cout << "O utente com o ID = " << this->getId() << " é agora do tipo:  " << conversion << ".\n";

	}

	return;
}


void Utente::setAvailable() {

	if(disponivel == false)
		disponivel = true;
	else
		disponivel = false;
}

void Utente::setBike(Bicicleta* bike) {
	this->bike = bike;
}

void Utente::setHistoric(Utilizacao ut) {
	this->historico.push_back(ut);
}

void Utente::setUtilizacoes(Utilizacao ut) {

	this->utilizacoes.push_back(ut);
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

void Utente::displayHistoric() {

	if(this->historico.size() != 0)
	{
		for(unsigned int i = 0; i < this->historico.size(); i++)
		{
			cout << "Tipo de bicicleta: " << this->historico.at(i).getBikeType() << endl;
			cout << "Número de horas: " << this->historico.at(i).getUseTime() << endl;
			cout << "Data (dd/mm/aaaa): " << this->historico.at(i).getData() << endl << endl;

		}
	}
	else
	{
		cout << "Este utente ainda não utilizou qualquer tipo de servico" << endl << endl;
	}
}

void Utente::alugaBicicleta(string bikeType, unsigned int numHours, Data d, vector<int> distancias) {

	//Se tiver: atribui a bicicleta ao utente e remove-a do pontopartilha e regista a utilizacao

	/* Atribui bicicleta ao utente */

	/* Remove bicicleta do ponto partilha */

	//	/* Regista utilizacao */
	//
	//Senão tiver: faz cout "Neste momento não é possivel alugar a bicicleta do tipo (bikeType)

	return;
}


