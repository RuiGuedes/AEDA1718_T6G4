#include "Sistema.h"

int Utente::lastId = 0;


///////////////////////
//// CLASSE UTENTE ////
///////////////////////

/**
 * Construtor padrao da classe Utente
 */
Utente::Utente() : id(++lastId){
	this->bike = 0;
	this->nome = "";
}

/**
 * Construtor da classe Utente
 * @param nome nome do utente
 * @param tipoUtente tipo de utente (socio ou regular)
 * @param spot localizacao atual do utente
 */
Utente::Utente(string nome,Localizacao spot) : id(++lastId) {
	this->nome = nome;
	this->bike = 0;
	local = spot;
}

/**
 * Atribui a bicicleta ao utente e remove-a do ponto de partilha mais proximo do utente
 * @param idPP indice do pontos de partilha
 * @param ut utilizacao = aluger da bicicleta em questao
 * @param bikeType tipo de bicicleta a alugar
 */
void Utente::alugaBicicleta(Bicicleta* b, Utilizacao ut) {
	setBike(b);
	setAvailable();
	addUse(ut);

	return;
}

/**
 * Remove a bicicleta do utente e coloca-a no ponto de partilha, nao lotado, mais proximo do utente
 * @param index_distancias vetor de indice dos pontos de partilha ordenados por distancia
 * @return Retorna o índice do ponto de partilha afetado
 */
Bicicleta* Utente::removeBicicleta(vector<int> index_distancias) {

	Bicicleta* b = bike;
	setAvailable();
	setBike(0);

	return b;
}

/**
 * Mostar a localizacao atual e extrai da stream de input a nova localizacao introduzida pelo utente.
 * Chama o metodo da classe utente setUtenteLocation que altera a localizacao.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void Utente::updateLocation(int index) {

	cout << "Localização atual: (" << getLocalizacao().getX() << " , " << getLocalizacao().getY();
	cout << ")" << endl << endl;

	cout << "Indique as novas coordenadas GPS:" << endl;

	string option;
	double coordX { }, coordY { };

	while(1)
	{
		try{
			cout << endl << "Coordenada X: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordX = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	while(1)
	{
		try{
			cout << endl << "Coordenada Y: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number_double(option) == false)
				throw OpcaoInvalida<string>(option);

			coordY = stod(option);
			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Coordenada inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	Localizacao spot(coordX,coordY);

	setUtenteLocation(spot);

	cout << endl << "O utente encontra-se agora num novo local de coordenadas (" << coordX << " , " << coordY << ")" << endl << endl;

	return;
}


// METODOS GET //

/**
 * @return Retorna o identificador do ultimo utente criado
 */
int Utente::getLastId(){
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
 * @return Retorna valor do atributo disponivel do utente
 */
bool Utente::getAvailable() const {
	return disponivel;
}

/**
 * @return Retorna vetor de utilizacoes ja liquidadas do utente
 */
vector<Utilizacao> Utente::getHistorico() const{
	return historico;
}


// METODOS SET //

/**
 * Decrementa o numero de identificacao do ultimo utente
 */
void Utente::setLastId(){
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
void Utente::setID(int identificacao){
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

void Utente::setAvailable() {
	disponivel = !disponivel;
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


//////////////////////
//// CLASSE SOCIO ////
//////////////////////

Socio::Socio() : Utente{}
{}

Socio::Socio(string nome,Localizacao spot) : Utente{nome, spot} {}

/**
 * Paga a mensalidade do mes selecionedo, removendo as ulizacoes correspondestes a esse mes do vetor utilizacoes
 * e colocando-as no historico do utente
 * @param ano do qual pretende pagar um mes
 * @param mes que pretende pagar
 */
void Socio::pagaMensalidade(unsigned int ano, unsigned int mes) {

	unsigned int numUseHours{0};
	double prestacao{-1};
	string mesName;

	for(unsigned int i = 0; i < utilizacoes.size(); i++)
	{
		if((utilizacoes.at(i).getData().getAno() == ano) && (utilizacoes.at(i).getData().getMes() == mes))
		{
			//Soma as horas de uso do respetivo mes
			numUseHours += utilizacoes.at(i).getUseTime();

			//Verifica o tipo de prestação a ser aplicada
			unsigned int tmp{};


			if(utilizacoes.at(i).getBikeType() == "Urbana")
				tmp = 40;
			else if(utilizacoes.at(i).getBikeType() == "Urbana Simples")
				tmp = 30;
			else if(utilizacoes.at(i).getBikeType() == "Corrida")
				tmp = 50;
			else
				tmp = 20;

			if(prestacao < tmp)
				prestacao = tmp;

			//Adiciona utilização ao histórico e remove-a das utilizações
			historico.push_back(utilizacoes.at(i));
			utilizacoes.erase(utilizacoes.begin() + i);
			i--;

		}
	}

	string monthNames[] = {"Janeiro","Fevereiro","Março","Abril", "Maio", "Junho",
			"Julho", "Agosto","Setembro","Outubro","Novembro", "Dezembro"};

	mesName = monthNames[mes-1];

	cout << "Montante a pagar referente ao mês " << mesName << " do ano " << ano << ": ";

	if(numUseHours >= 20)
		prestacao = prestacao*0.9;

	cout << prestacao << "€" << endl << endl;

	return;
}

/**
 * Imprime no ecra o historico do utente.
 * Caso  o historico esteja vazio e apresentada uma mensagem
 * Se o utente é Regular, tambem e apresentado o total pago por cada utilizacao.
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void Socio::displayHistoric() const{

	vector<Utilizacao> hist = historico;

	cout << "Histórico: " << endl << endl;

	for(unsigned int i = 0; i < hist.size(); i++)
	{
		hist.at(i).displayUtilizacao();
		cout << endl;
	}

	return;
}

/**
 * Imprime no ecra as utilizacoes por pagar do utente.
 * Esta opcao e apenas para socios. Se um utente regular acede a esta opcao,
 * e-lhe apresentada uma mensagem.
 * @param index indice do utente no vetor de utentes do sistema
 */
void Socio::displayPagPendentes(int index){

	if(utilizacoes.size() != 0)
	{
		cout << "Pagamentos pendentes:" << endl << endl;

		for(unsigned int i = 0; i < utilizacoes.size(); i++)
		{
			utilizacoes.at(i).displayUtilizacao();
			cout << endl;
		}
	}
	else
	{
		cout << "Este utente não possui qualquer pagamento pendente" << endl << endl;
	}

	return;
}

/**
 * Efetua o pagamento de mensalidades, para tal, sera impresso no ecra os anos que contem utilizacoes
 * por saldar, e depois do utente selecionar o ano, e-lhe apresentado os meses que pode tem em divida
 * depos de selecionar chama-se o metodo da classe utente pagaMensalidade que calcula a mensalidade
 * consoante o numero de horas de uso nesse mes (desconto) e consoante o tipo de bicicletas alugadas
 * (ver tabela de mensalidades (infoER)).
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param index indice do utente no vetor de utentes do sistema
 */
void Socio::efetuaPag(int index){

	cout << "Efetua pagamento" << endl << endl;

	unsigned int ano{}, mes{};
	string option {};
	vector<unsigned int> meses;
	vector<unsigned int> anos;

	if(disponivel == false)
	{
		cout << "Não é possível efetuar o pagamento uma vez que a bicicleta alugada ainda não foi devolvida" << endl << endl;
		return;
	}

	else if(utilizacoes.size() == 0){
		cout << "Este utente não possui qualquer pagamento pendente" << endl << endl;
		return;
	}

	//Verifica os anos com mensalidades em atraso
	for(unsigned int i = 0; i < utilizacoes.size(); i++)
	{
		if(anos.size() == 0)
			anos.push_back(utilizacoes.at(i).getData().getAno());

		bool cond {false};
		for(unsigned int k = 0; k < anos.size(); k++)
		{
			if(anos.at(k) == utilizacoes.at(i).getData().getAno()) {
				cond = true;
				break;
			}
		}
		if(cond == false)
			anos.push_back(utilizacoes.at(i).getData().getAno());

		cond = false;
	}

	//Organiza o vetor "anos" por ordem crescente
	sort(anos.begin(),anos.end());

	cout << "Anos com mensalidades em atraso: " << endl;
	for(unsigned int i = 0; i < anos.size(); i++)
	{
		cout << "-> " << anos.at(i) << endl;
	}

	cout << endl;

	//Executa até obter um ano válido
	while(1)
	{
		try{
			cout << "Liquidação de mensalidades do ano: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			ano = stoi(option);
			if(ano < 2017)
				throw OpcaoInvalida<int>(ano);

			cout << endl;
			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Ano inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Ano inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	//Verifica meses de utilização do respetivo ano
	for(unsigned int i = 0; i < utilizacoes.size(); i++)
	{
		if(utilizacoes.at(i).getData().getAno() == ano)
		{
			if(meses.size() == 0)
				meses.push_back(utilizacoes.at(i).getData().getMes());

			bool cond {false};
			for(unsigned int k = 0; k < meses.size(); k++)
			{
				if(meses.at(k) == utilizacoes.at(i).getData().getMes())
					cond = true;
			}

			if(cond == false)
				meses.push_back(utilizacoes.at(i).getData().getMes());

			cond = false;
		}
	}

	string monthNames[] = {"Janeiro","Fevereiro","Março","Abril", "Maio", "Junho",
			"Julho", "Agosto","Setembro","Outubro","Novembro", "Dezembro"};

	cout << "Meses com mensalidades em atraso: " << endl;

	for(unsigned int i = 0; i < meses.size(); i++)
	{
		cout << meses.at(i) << " - " << monthNames[meses.at(i)-1] << endl;
	}

	cout << endl;

	//Executa até obter um ano válido
	while(1)
	{
		try{
			cout << "Liquidação de mensalidades do mês: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			mes = stoi(option);

			bool cond {false};

			for(unsigned int i = 0; i < meses.size(); i++)
			{
				if(meses.at(i) == mes)
				{
					cond = true;
					break;
				}
			}

			if(cond == false)
				throw OpcaoInvalida<int>(mes);

			cout << endl;
			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Mês inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Mês inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};


	pagaMensalidade(ano,mes);

	return;
}

bool Socio::hasPendingPay() {
	return utilizacoes.size() > 0;
}

void Socio::addUse(Utilizacao use) {
	utilizacoes.push_back(use);
	return;

}


// METODOS GET //

/**
 * @return Retorna vetor de utilizacoes por pagar do utente
 */
vector<Utilizacao> Socio::getUtilizacoes() const {
	return utilizacoes;
}

Utilizacao Socio::getLastUse() {
	return utilizacoes.back();
}

/**
 * @return Retorna o tipo do utente (socio)
 */
string Socio::getTipoUtente() const {
	return "Socio";
}


////////////////////////
//// CLASSE REGULAR ////
////////////////////////

/**
 * Construtor padrao da classe Regular
 */
Regular::Regular() : Utente{} {}

Regular::Regular(string nome,Localizacao spot) : Utente{nome, spot} {}

/** Imprime no ecra o historico do utente.
 * Caso  o historico esteja vazio e apresentada uma mensagem
 * Se o utente é Regular, tambem e apresentado o total pago por cada utilizacao.
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void Regular::displayHistoric() const{

	vector<Utilizacao> hist = getHistorico();

	cout << "Histórico: " << endl << endl;

	for(unsigned int i = 0; i < hist.size(); i++)
	{
		hist.at(i).displayUtilizacao();
		cout << "Montante: " << hist.at(i).getPrice() << "€" << endl << endl;
	}

	return;
}

void Regular::displayPagPendentes(int index){

	cout << "Neste tipo de utente [Regular] não é possível ter pagamentos pendentes !" << endl << endl;

	return;
}

void Regular::efetuaPag(int index){

	cout << "Efetua pagamento" << endl << endl;

	cout << "O pagamento já foi feito na altura do aluguer!" << endl << endl;

	return;
}

bool Regular::hasPendingPay() {
	return false;
}

void Regular::addUse(Utilizacao use) {
	historico.push_back(use);

}


// METODOS GET //

/** @return Retorna o tipo do utente (regular)
 */
string Regular::getTipoUtente() const {
	return "Regular";
}

Utilizacao Regular::getLastUse() {
	return historico.back();
}
