#include "Sistema.h"

int Utente::lastId = 0;

/**
 * Construtor padrao da classe Bicicleta
 */
Utente::Utente() : id(++lastId){this->bike = 0;}

/**
 * Construtor da classe Utente
 * @param nome nome do utente
 * @param tipoUtente tipo de utente (socio ou regular)
 * @param spot localizacao atual do utente
 */
Utente::Utente(string nome, string tipoUtente,Localizacao spot) : id(++lastId)
{
	this->nome = nome;
	this->tipoUtente = tipoUtente;
	this->bike = 0;
	local = spot;

}

/**
 * Atribui a bicicleta ao utente e remove-a do ponto de partilha mais proximo do utente
 * @param idPP indice do pontos de partilha
 * @param ut utilizacao = aluger da bicicleta em questao
 * @param bikeType tipo de bicicleta a alugar
 */
void Utente::alugaBicicleta(Sistema &ER, string bikeType, Utilizacao ut, int idPP) {

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

/**
 * Remove a bicicleta do utente e coloca-a no ponto de partilha, nao lotado, mais proximo do utente
 * @param index_distancias vetor de indice dos pontos de partilha ordenados por distancia
 * @return Retorna o índice do ponto de partilha afetado
 */
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
			setBike(0);
			break;
		}
	}
	return index_pp;
}

/**
 * Paga a mensalidade do mes selecionedo, removendo as ulizacoes correspondestes a esse mes do vetor utilizacoes
 * e colocando-as no historico do utente
 * @param ano do qual pretende pagar um mes
 * @param mes que pretende pagar
 */
void Utente::pagaMensalidade(unsigned int ano, unsigned int mes) {

	unsigned int numUseHours{0};
	double prestacao{-1};
	string mesName;

	for(unsigned int i = 0; i < getUtilizacoes().size(); i++)
	{
		if((getUtilizacoes().at(i).getData().getAno() == ano) && (getUtilizacoes().at(i).getData().getMes() == mes))
		{
			//Soma as horas de uso do respetivo mes
			numUseHours += getUtilizacoes().at(i).getUseTime();

			//Verifica o tipo de prestação a ser aplicada
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

			//Adiciona utilização ao histórico e remove-a das utilizações
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
		mesName = "Março";
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

	cout << "Montante a pagar referente ao mês " << mesName << " do ano " << ano << ": ";

	if(numUseHours >= 20)
		prestacao = prestacao*0.9;

	cout << prestacao << "€" << endl << endl;

	return;
}


/////////////////
// METODOS GET //
/////////////////

/**
 * @return Retorna o identificador do ultimo utente criado
 */
int Utente::getLastId()
{
	return lastId;
}

/**
 * @return Retorna o identificador do utente
 */
int Utente::getId() const {
	return id;
}

/**
 * @return Retorna o nome do utente
 */
string Utente::getNome() const {
	return nome;
}

/**
 * @return Retorna o tipo do utente (socio ou regular)
 */
string Utente::getTipoUtente() const {

	return tipoUtente;
}

/**
 * @return Retorna localizacao do utente
 */
Localizacao Utente::getLocalizacao() const {
	return local;
}

/**
 * Retorna um apontador para bicicleta que o utente está a usar.
 * Caso nao esteja a usar uma bicicleta, o apontador tem o valor 0
 *
 * @return Retorna um apontador para bicicleta
 */
Bicicleta* Utente::getBike() const {
	return bike;
}

/**
 * @return Retorna vetor de utilizacoes por pagar do utente (so para socios)
 */
vector<Utilizacao> Utente::getUtilizacoes() {
	return utilizacoes;
}

/**
 * @return Retorna valor do atributo disponivel do utente
 */
bool Utente::getAvailable() const {
	return disponivel;
}

/**
 * @return Retorna vetor de utilizacoes ja liquidadas do utente
 */
vector<Utilizacao> Utente::getHistorico() {
	return this->historico;
}

/////////////////
// METODOS SET //
/////////////////

/**
 * Decrementa o numero de identificacao do ultimo utente
 */
void Utente::setLastId()
{
	lastId--;
}

/**
 * Decrementa o numero de identificacao do utente
 */
void Utente::setIDBackward() {
	this->id--;
}

/**
 * Altera o numero de identificacao do utente
 * @param identificacao novo numero de identificacao
 */
void Utente::setID(int identificacao)
{
	id = identificacao;
}

/**
 * Altera a localizacao do utente
 * @param spot nova localizacao
 */
void Utente::setUtenteLocation(Localizacao spot) {
	local = spot;
	return;
}

/**
 * Altera o tipo do utente
 * @param tipo novo tipo de utente
 */
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

/**
 * Atribui a bicicleta ao utente
 * @param bike bicicleta que vai usar
 */
void Utente::setBike(Bicicleta* bike) {
	this->bike = bike;
}

/**
 * Acrescenta uma utilizcao ao historico do utente
 * @param ut utilizacao a acrescentar
 */
void Utente::setHistoric(Utilizacao ut) {
	this->historico.push_back(ut);
}

/**
 * Acrescenta uma utilizcao as utilizacoes do utente
 * @param ut utilizacao a acrescentar
 */
void Utente::setUtilizacoes(Utilizacao ut) {

	this->utilizacoes.push_back(ut);
}





