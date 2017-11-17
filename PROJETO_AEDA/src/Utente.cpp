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

void Utente::pagaMensalidade(Sistema &ER, unsigned int ano, unsigned int mes) {

	unsigned int numUseHours{0};
	double prestacao{-1};
	string mesName;

	for(unsigned int i = 0; i < getUtilizacoes().size(); i++)
	{
		if((getUtilizacoes().at(i).getData().getAno() == ano) && (getUtilizacoes().at(i).getData().getMes() == mes))
		{
			//Soma as horas de uso do respetivo mes
			numUseHours += getUtilizacoes().at(i).getUseTime();

			//Verifica o tipo de prestacao a ser aplicada
			unsigned int tmp{};

			if(getUtilizacoes().at(i).getBikeType() == "Urbana")
				tmp = 0;
			else if(getUtilizacoes().at(i).getBikeType() == "Urbana Simples")
				tmp = 1;
			else if(getUtilizacoes().at(i).getBikeType() == "Corrida")
				tmp = 2;
			else
				tmp = 3;

			if(prestacao == 0)
				prestacao = tmp;
			else if(prestacao < tmp)
				prestacao = tmp;

			//Adiciona utiliza��o ao historico e remove-a das utiliza��es
			historico.push_back(getUtilizacoes().at(i));
			utilizacoes.erase(utilizacoes.begin() + i);
			i--;

		}
	}

	if(prestacao == 0)
		prestacao = 40;
	else if(prestacao == 1)
		prestacao = 30;
	else if(prestacao == 2)
		prestacao = 50;
	else
		prestacao = 20;

	if(mes == 1)
		mesName = "Janeiro";
	else if(mes == 2)
		mesName = "Fevereiro";
	else if(mes == 3)
		mesName = "Mar�o";
	else if(mes == 4)
		mesName = "Abril";
	else if(mes == 5)
		mesName = "Maio";
	else if(mes == 6)
		mesName = "Junho";
	else if(mes == 7)
		mesName = "Julho";
	else if(mes == 8)
		mesName = "Agosto";
	else if(mes == 9)
		mesName = "Setembro";
	else if(mes == 10)
		mesName = "Outubro";
	else if(mes == 11)
		mesName = "Novembro";
	else if(mes == 12)
		mesName = "Dezembro";

	cout << "Montante a pagar referente ao mes " << mesName << " do ano " << ano << ": ";

	if(numUseHours >= 20)
		prestacao = prestacao*0.9;

	cout << prestacao << endl << endl;

	return;
}

void Utente::updateHistoric() {

	for(unsigned int i = 0; i < utilizacoes.size(); i+=0)
	{
		historico.push_back(utilizacoes.at(i));
		utilizacoes.erase(utilizacoes.begin() + i);
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

string Utente::getNome() const {
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

void Utente::setIDBackward() {
	this->id--;
}

void Utente::setLastId()
{
	lastId--;
}

void Utente::setID(int identificacao)
{
	id = identificacao;
}

void Utente::setUtenteLocation(Localizacao spot) {
	local = spot;
	return;
}

void Utente::setTipoUtente(string tipo) {

	this->tipoUtente = tipo;

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





