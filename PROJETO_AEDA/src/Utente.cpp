#include "Sistema.h"

int Utente::lastId = 0;

Utente::Utente() : id(++lastId){this->bike = 0;}

Utente::Utente(string nome, string tipoUtente,Localizacao spot) : id(++lastId)
{
	this->nome = nome;
	this->tipoUtente = tipoUtente;
	this->bike = 0;
	local = spot;

}

void Utente::alugaBicicleta(Sistema &ER,string bikeType, Utilizacao ut, int idPP) {

	if(bikeType == "Urbana")
		setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(0).at(0));
	else if(bikeType == "Urbana Simples")
		setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(1).at(0));
	else if(bikeType == "Corrida")
		setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(2).at(0));
	else
		setBike(ER.getPontosPartilha().at(idPP)->getBikes().at(3).at(0));

	setAvailable();

	ER.getPontosPartilha().at(idPP)->removeBike(getBike());


	if(getTipoUtente() == "Socio")
	{
		setUtilizacoes(ut);

	}
	else
	{
		setHistoric(ut);
	}

	return;
}

int Utente::removeBicicleta(Sistema &ER, vector<int> index_distancias) {

	int index_pp {-1};

	setAvailable();

	for(unsigned int i = 0; i < index_distancias.size(); i++)
	{
		int lotacao {0};

		for(unsigned int k = 0; k < ER.getPontosPartilha().at(index_distancias.at(i))->getNumberOfBikes().size(); k++)
		{
			lotacao += ER.getPontosPartilha().at(index_distancias.at(i))->getNumberOfBikes().at(k);
		}

		if(ER.getPontosPartilha().at(index_distancias.at(i))->getCapacidade() > lotacao)
		{
			index_pp = index_distancias.at(i);
			ER.getPontosPartilha().at(index_distancias.at(i))->adicionaBike(getBike());
			Bicicleta * p {0};
			setBike(p);
			break;
		}
	}

	return index_pp;
}

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

/////////////////
// METODOS GET //
/////////////////

int Utente::getLastId()
{
	return lastId;
}

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

void Utente::setLastId()
{
	--lastId;
}

void Utente::setID(int identificacao)
{
	id = identificacao;
}

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





