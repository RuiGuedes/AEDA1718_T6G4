#include "Sistema.h"


/////////////////
// METODOS ADD //
/////////////////

/**
 * Apresenta os passos necessarios para criacao de um novo ponto de partilha, pedindo para introduzir
 * o nome, a localizacao e a capacidade. Invoca-se o metodo da classe Sistema addPontoPartilha.
 * Inclui 5 bicicletas de cada tipo no ponto de partilha criado.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 *
 * Adiciona um novo ponto de partilha ao sistema
 * @param spot ponto de partilha que pretende adicionar
 */
void Sistema::addPontoPartilha() {

	cout << "Adiciona Ponto de Partilha:" << endl << endl;

	string nome,locname;
	int value {};
	string option {};
	bool cond {false};

	cin.ignore(1000,'\n');

	while(1)
	{
		try {
			cout << "Nome: " ;
			getline(cin,nome);
			if(valid_word(nome) == false)
				throw OpcaoInvalida<string>(nome);

			for(unsigned int i = 0; i < pontosPartilha.size(); i++)
			{
				if(pontosPartilha.at(i)->getNome() == nome)
					cond = true;
			}

			if(cond == true)
				throw OpcaoInvalida<string>(nome);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			if(cond == true)
				cout << "Já existe esse nome (" << op.opcao << ") ! Tente novamente." << endl;
			else
				cout << "Nome inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cond = false;
			cin.clear();
		}
	}

	Localizacao spot{};
	bool diffloc {true};

	cout << endl << "Localização: " << endl << endl;

	while(1)
	{
		try {
			cout << "Nome: " ;
			getline(cin , locname);
			if(valid_word(locname) == false)
				throw OpcaoInvalida<string>(nome);

			for(unsigned int i = 0; i < pontosPartilha.size(); i++)
			{
				if(pontosPartilha.at(i)->getLocal().getNome() == locname)
				{
					diffloc = false;
					spot.setNome(locname);
					spot.setX(pontosPartilha.at(i)->getLocal().getX());
					spot.setY(pontosPartilha.at(i)->getLocal().getY());
					cout << endl << "Coordenada X: " << spot.getX() << endl << endl;
					cout << "Coordenada Y: " << spot.getY() << endl << endl;
					break;
				}
			}


			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Nome inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	if(diffloc == true)
	{
		bool newcord{true};
		double coordX { }, coordY { };

		do
		{
			newcord = true;
			cout << "Indique as coordenadas GPS:" << endl;

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


			for(unsigned int i = 0; i < pontosPartilha.size(); i++)
			{
				if((pontosPartilha.at(i)->getLocal().getX() == coordX) && (pontosPartilha.at(i)->getLocal().getY() == coordY))
				{
					newcord = false;
					cout << "Essas coordenadas já pertencem à localização: " << pontosPartilha.at(i)->getLocal().getNome() << endl << endl;
					break;
				}
			}

		}while(newcord == false);

		spot.setNome(locname);
		spot.setX(coordX);
		spot.setY(coordY);
	}

	while(1)
	{
		try{
			cout << endl << "Capacidade [20,30]: ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);

			if((value < 20) || (value > 30))
				throw OpcaoInvalida<string>(option);

			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Capacidade inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	PontoPartilha* pp = new PontoPartilha(spot,value,nome);

	pontosPartilha.push_back(pp);

	for(unsigned int i = 0; i < 5; i++)
	{
		string u = "u" + to_string(pontosPartilha.at(0)->getBikeNextId("Urbana"));
		string us = "us" + to_string(pontosPartilha.at(0)->getBikeNextId("Urbana Simples"));
		string c = "c" + to_string(pontosPartilha.at(0)->getBikeNextId("Corrida"));
		string inf = "i" + to_string(pontosPartilha.at(0)->getBikeNextId("Infantil"));

		Bicicleta* b1 = new Urbana(u);
		Bicicleta* b2 = new UrbanaSimples(us);
		Bicicleta* b3 = new Corrida(c);
		Bicicleta* b4 = new Infantil(inf);

		pontosPartilha.at(pontosPartilha.size() - 1)->adicionaBike(b1);
		pontosPartilha.at(pontosPartilha.size() - 1)->adicionaBike(b2);
		pontosPartilha.at(pontosPartilha.size() - 1)->adicionaBike(b3);
		pontosPartilha.at(pontosPartilha.size() - 1)->adicionaBike(b4);

		pontosPartilha.at(0)->setBikeNextIdForward("Urbana");
		pontosPartilha.at(0)->setBikeNextIdForward("Urbana Simples");
		pontosPartilha.at(0)->setBikeNextIdForward("Corrida");
		pontosPartilha.at(0)->setBikeNextIdForward("Infantil");
	}

	cout << endl << "Novo ponto de partilha adicionado ao sistema" << endl << endl;

	return;
}

/**
 * Adiciona um utente ao sistema, pedindo ao utente que introduza os seus dados necessarios
 * para o registo (nome, tipo de utente e localizacao).
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 *
 * Adiciona um novo utente ao sistema
 * @param utente utente que pretende adicionar
 */
void Sistema::addNewUtente() {

	mensagemInicial();

	cout << "Regista novo utente:" << endl << endl;

	string nome, tipoUtente;
	int value {};
	string option {};
	double coordX { }, coordY { };

	while(1)
	{
		try {
			cout << "Nome: " ;
			getline(cin,nome);
			if(valid_word(nome) == false)
				throw OpcaoInvalida<string>(nome);
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Nome inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}
	cout << endl << "Tipo de Utente :"<< endl ;
	cout << "     1 - Regular" << endl;
	cout << "     2 - Sócio" << endl << endl;

	while(1)
	{
		try{
			cout << endl << "Introduza uma opção (1-2): ";
			cin >> option;
			cin.ignore(1000,'\n');
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);
			if(value < 1 || value > 2)
				throw OpcaoInvalida<int>(value);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	if(value==1)
		tipoUtente = "Regular";
	else
		tipoUtente = "Socio";

	cout << endl << "Localização: " << endl << endl;

	cout << "Indique as coordenadas GPS:" << endl;

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

	Localizacao spot;

	for(unsigned int i = 0; i < pontosPartilha.size(); i++)
	{
		if((pontosPartilha.at(i)->getLocal().getX() == coordX) && (pontosPartilha.at(i)->getLocal().getY() == coordY))
		{
			spot.setNome(pontosPartilha.at(i)->getLocal().getNome());
			break;
		}
	}

	spot.setX(coordX);
	spot.setY(coordY);

	Utente* u12;
	if(tipoUtente == "Socio")
		u12 = new Socio(nome, spot);
	else
		u12 = new Regular(nome, spot);

	utentes.push_back(u12);

	cout << endl << "Utente #" << u12->getId() << " registado com sucesso." << endl << endl;

	return;
}

/**
 * Pede o nome do ponto de partilha onde vai adicionar a bicicleta e o tipo de bicicleta que
 * pretende adicionar. Cria uma bicicleta com do tipo pedido e chama o metodo da classe
 * PontoPartilha, adicionaBike para adionar a bicicleta criada.
 * Se a capaciadade do ponto de partilha esteja no maximo e apresentada uma mensagem.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 */
void Sistema::adicionaBike() {

	cout << "Adiciona bicicleta: " << endl << endl;

	string biketype;
	string nomePP;
	int indexPP {-1};
	int indexBB {-1};
	int numberbikes {0};

	cin.ignore(1000,'\n');

	//Verifica ponto de partilha ao qual quer adicionar
	while(1)
	{
		try {
			cout << "Nome do Ponto de Partilha: " ;
			getline(cin,nomePP);

			if(valid_word(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < pontosPartilha.size(); i++)
			{
				if(pontosPartilha.at(i)->getNome() == nomePP)
					indexPP = i;
			}

			if(indexPP == -1)
				throw OpcaoInvalida<string>(nomePP);
			cout << endl;

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Ponto de partilha inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	for(unsigned int i = 0; i < pontosPartilha.at(indexPP)->getBikes().size(); i++)
	{
		numberbikes += pontosPartilha.at(indexPP)->getBikes().at(i).size();
	}

	if(pontosPartilha.at(indexPP)->getCapacidade() == numberbikes)
	{
		cout << "A capacidade deste ponto de partilha já foi alcançada ! Tente adicionar a outro ponto de partilha." << endl << endl;

		return;
	}

	//Verifica tipo de bicicleta a adicionar
	while(1)
	{
		try {
			cout << "Tipo de Bicicleta: " ;
			getline(cin,biketype);
			if(valid_word(biketype) == false)
				throw OpcaoInvalida<string>(biketype);


			if(biketype == "Urbana")
			{
				indexBB = 0;
				nomePP = "u" + to_string(pontosPartilha.at(0)->getBikeNextId("Urbana"));
			}
			else if(biketype == "Urbana Simples")
			{
				indexBB = 1;
				nomePP = "us" + to_string(pontosPartilha.at(0)->getBikeNextId("Urbana Simples"));
			}
			else if(biketype == "Corrida")
			{
				indexBB = 2;
				nomePP = "c" + to_string(pontosPartilha.at(0)->getBikeNextId("Corrida"));
			}
			else if(biketype == "Infantil")
			{
				indexBB = 3;
				nomePP = "i" + to_string(pontosPartilha.at(0)->getBikeNextId("Infantil"));
			}

			if(indexBB == -1)
				throw OpcaoInvalida<string>(biketype);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Tipo inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	//pontosPartilha.at(0)->setBikeNextIdForward("Urbana");

	Bicicleta* bc;

	if(biketype == "Urbana")
		bc = new Urbana(nomePP);
	else if(biketype == "Urbana Simples")
		bc = new UrbanaSimples(nomePP);
	else if(biketype == "Corrida")
		bc = new Corrida(nomePP);
	else
		bc = new Infantil(nomePP);


	pontosPartilha.at(indexPP)->adicionaBike(bc);

	cout << endl << "Bicicleta adicionada com sucesso !" << endl << endl;

	return;
}

void Sistema::addNewUtente(Utente* u1){
	utentes.push_back(u1);
}

void Sistema::addPontoPartilha(PontoPartilha* p){
	pontosPartilha.push_back(p);
}

////////////////////
// METODOS REMOVE //
////////////////////

/**
 * Pede o nome do ponto de partilha que se quer remover e chama o metodo da
 * classe Sistema removePonto.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 *
 * Remove um novo ponto de partilha do sistema
 * @param indexPP indice do ponto de partilha que pretende remover
 */
void Sistema::removePonto() {

	cout << "Remove Ponto de Partilha:" << endl << endl;

	string nomePP;
	int indexPP {-1};

	if(pontosPartilha.size() == 0)
	{
		cout << "Neste momento não existem pontos de partilha !" << endl << endl;

		return;
	}

	cin.ignore(1000,'\n');

	//Verifica ponto de partilha que quer remover
	while(1)
	{
		try {
			cout << "Nome do Ponto de Partilha: " ;
			getline(cin,nomePP);
			if(valid_word(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < pontosPartilha.size(); i++)
			{
				if(pontosPartilha.at(i)->getNome() == nomePP)
					indexPP = i;
			}

			if(indexPP == -1)
				throw OpcaoInvalida<string>(nomePP);
			cout << endl;
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Ponto de partilha inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	pontosPartilha.erase(pontosPartilha.begin() + indexPP);

	cout << "Ponto de partilha removido com sucesso !" << endl << endl;

	return;
}

/**
 * Apresenta a informacao de todos os utentes registados (nome, id, tipo e localizacao) e  pede para
 * introduzir o id do utente que se pretende remover e chama o metodo removeUtente
 * da classe Sistema.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 *
 * Remove um novo utente ao sistema
 * @param indexUT indice do utente que pretende remover
 */
void Sistema::removeUtente() {

	cout << "Remove utente " << endl << endl;

	if(utentes.size() == 0)
	{
		cout << "Neste momento não existem utentes !" << endl << endl;

		return;
	}

	cout << left << setw(15) << "   Nome" << setw(6) << " ID" << setw(27) << " Tipo de utente" << setw (20) << " GPS" << endl;

	for (unsigned int i=0 ; i< utentes.size() ; i++)
	{
		cout << "-> " << setw(13) << utentes.at(i)->getNome();
		cout << setw(10) << utentes.at(i)->getId();
		cout << setw(14) <<utentes.at(i)->getTipoUtente();
		cout << '(' << setw(9) << utentes.at(i)->getLocalizacao().getX();
		cout << "," << setw(9) << utentes.at(i)->getLocalizacao().getY() << setw(5) << ')' << endl;
	}

	cout << endl;

	string id;
	int idUT {};
	int indexUT {-1};

	cin.ignore(1000,'\n');

	//Verifica o nome do utente que quer remover
	while(1)
	{
		try {
			cout << "ID do Utente: " ;
			getline(cin,id);
			if(valid_number(id) == false)
				throw OpcaoInvalida<string>(id);

			idUT = stoi(id);
			for(unsigned int i = 0; i < utentes.size(); i++)
			{
				if(utentes.at(i)->getId() == idUT)
					indexUT = i;
			}

			if(indexUT == -1)
				throw OpcaoInvalida<int>(idUT);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "ID inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();

		}
		catch (OpcaoInvalida<string> &op){

			cout << "ID inválido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	utentes.erase(utentes.begin() + indexUT);

	if((unsigned int)indexUT == utentes.size())
	{

		utentes.at(0)->setLastId();

		cout << endl << "Utente removido com sucesso !" << endl << endl;

		return;
	}

	for(unsigned int i = indexUT; i < utentes.size(); i++)
	{
		utentes.at(i)->setIDBackward();
	}

	utentes.at(0)->setLastId();

	cout << endl << "Utente removido com sucesso !" << endl << endl;

	return;
}

/**
 * Pede o tipo e o nome da bicicleta que se pretende remover e chama-se o metodo
 * da classe PontoPartilha, removeBike.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 */
void Sistema::removeBike() {

	cout << "Remove bicicleta " << endl << endl;

	string nomePP, biketype;
	bool cond {false};
	int indexPP {-1};
	int indexBB {-1};

	cin.ignore(1000,'\n');

	//Verifica tipo de bicicleta a remover
	while(1)
	{
		try {
			cout << "Tipo de Bicicleta: " ;
			getline(cin,biketype);
			if(valid_word(biketype) == false)
				throw OpcaoInvalida<string>(biketype);

			if(biketype == "Urbana")
				indexBB = 0;
			else if(biketype == "Urbana Simples")
				indexBB = 1;
			else if(biketype == "Corrida")
				indexBB = 2;
			else if(biketype == "Infantil")
				indexBB = 3;

			if(indexBB == -1)
				throw OpcaoInvalida<string>(biketype);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Tipo inválido(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	//Verifica se o nome da bicicleta a remover existe
	while(1)
	{
		try {
			cout << "Nome da Bicicleta: " ;
			getline(cin,nomePP);

			if(valid_bike(nomePP) == false)
				throw OpcaoInvalida<string>(nomePP);

			for(unsigned int i = 0; i < pontosPartilha.size(); i++)
			{
				for(unsigned int k = 0; k < pontosPartilha.at(i)->getBikes().at(indexBB).size(); k++)
				{
					if(pontosPartilha.at(i)->getBikes().at(indexBB).at(k)->getBikeName() == nomePP)
					{
						indexPP = i;
						cond = true;
					}
				}
			}

			if(cond == false)
				throw OpcaoInvalida<string>(nomePP);

			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Bicicleta inexistente(" << op.opcao << ") ! Tente novamente." << endl;
			cond = false;
			cin.clear();
		}
	}

	pontosPartilha.at(indexPP)->removeBike(nomePP);

	cout << endl << "Bicicleta removida com sucesso !" << endl << endl;

	return;

}


/////////////////
// METODOS GET //
/////////////////

/**
 * Imprime no ecra toda a informacao referente ao sistema, nome da empresa, pontos de partilha
 * (incluindo nome, localizacao (nome e coordenadas) e quantidades de cada tipo de bicicletas),
 *  utentes (incluindo nome, id, tipo e coordenadas GPS), tabela de precos por hora e mensalidades
 *  e por fim, os fundadores.
 * @param ER sistema em execucao
 */
void Sistema::getInfo() const {

	cout << "Informações:" << endl << endl;

	cout << "Nome da empresa: ECO RIDES" << endl << endl;
	cout << "Número total de pontos de Partilha: " << pontosPartilha.size() << endl << endl;
	cout << "Pontos de Partilha:" << endl << endl;
	cout << setw (15) << left << "Nome" << setw (22) << "Local" << setw (13) << "GPS";
	cout << setw (10) << "Urbana" << setw (18) << "Urbana Simples" <<
			setw (9) << "Corrida" << setw(10) << "Infantil" << "Capacidade" << endl;

	for (unsigned int i=0 ; i<pontosPartilha.size() ; i++){
		cout << setw(5) << pontosPartilha.at(i)->getNome();
		cout << setw(23) << pontosPartilha.at(i)->getLocal().getNome();
		cout << '(' << setw(9) << pontosPartilha.at(i)->getLocal().getX();
		cout << "," << setw(9) << pontosPartilha.at(i)->getLocal().getY() << setw(5) << ')';

		vector<int> numtypes = pontosPartilha.at(i)->getNumberOfBikes();

		cout << setw(13) << numtypes.at(0);
		cout << setw(15) << numtypes.at(1);
		cout << setw(9) << numtypes.at(2);
		cout << setw(11) << numtypes.at(3);
		cout << pontosPartilha.at(i)->getCapacidade();

		cout << endl;
	}

	cout << endl;

	cout << "Número total de utentes registados: " << utentes.size() << endl << endl;

	displayUtentes();

	cout << endl;

	cout << "Tabela de Preços:" << endl << endl;

	cout << setw(20) << left << "Tipo de bicicleta" << "Preço por hora" << endl;
	cout << setw(26) << "Urbana" << "4€" << endl <<
			setw(26) << "Urbana Simples" << "3€" << endl <<
			setw(26) << "Corrida" << "5€" << endl <<
			setw(26) << "Infantil" << "2€" << endl << endl;

	cout << setw(18) << left << "Mensalidade" << "Acessos" << endl;
	cout << setw(4) << " " << setw(11) << "20€" << "Infantil" << endl;
	cout << setw(4) << " " << setw(11) << "30€" << "Infantil + Urbana Simples" << endl;
	cout << setw(4) << " " << setw(11) << "40€" << "Infantil + Urbana Simples + Urbana" << endl;
	cout << setw(4) << " " << setw(11) << "50€" << "Infantil + Urbana Simples + Urbana + Corrida" << endl << endl;

	cout << "Fundadores: " << endl;
	cout << "  - Rui Guedes" << endl;
	cout << "  - César Pinho" << endl;
	cout << "  - Bernardo Santos" << endl << endl;

	return;
}

/**
 * Retorna o vetor de apontadores para os utentes registados no sistema
 *
 * @return Retorna um vetor de utentes
 */
vector<Utente* > Sistema::getUtentes() const{
	return utentes;
}

/**
 * Retorna o vetor de apontadores para os pontos de partilha existentes no sistema
 *
 * @return Retorna um vetor de pontos de partilha
 */
vector<PontoPartilha* > Sistema::getPontosPartilha() const {
	return pontosPartilha;
}

/**
 * Retorna um vector com os indices dos pontos de partilha organizados por ordem crescente
 * de distancia ao utente com indice = index.
 *
 * @param ER sistema em execucao
 * @param index indice do utente
 * @return Retorna um vetor com os indices dos pontos de partilha
 */
vector<int> Sistema::getOrderedPP(int index) const {

	//Retorna um vector com os indices dos pontos de partilha organizados por ordem crescente de distancia ao utente com indice = index
	vector<double> distancias;
	vector<int> indices;

	for(unsigned int i = 0; i < pontosPartilha.size(); i++)
	{
		distancias.push_back(utentes.at(index)->getLocalizacao().distancia(pontosPartilha.at(i)->getLocal()));
	}

	sort(distancias.begin(),distancias.end());

	for(unsigned int i = 0; i < distancias.size(); i++)
	{
		for(unsigned int k = 0; k < pontosPartilha.size(); k++)
		{
			if(distancias.at(i) == utentes.at(index)->getLocalizacao().distancia(pontosPartilha.at(k)->getLocal()))
			{
				indices.push_back(k);
			}
		}
	}
	return indices;
}

/**
 * Verifica se existe o utente com numero de identificacao = identificacao no sistema ER
 * @param sys sistema em execucao
 * @param identificacao numero de identificacao de um utente
 * @return Retorna o indice do utente no vetor de utentes do sistema se este existir e -1 caso contrario
 */
int Sistema::getUtenteIndex(int identificacao) const {

	for(unsigned int i = 0; i < utentes.size() ; i++)
	{
		if(utentes.at(i)->getId() == identificacao)
			return i;
	}

	return -1;
}


////////////
// OTHERS //
////////////

/**
 * Apresenta os passos e pede ao utente que preencha os campos apresentados
 * de modo a obter a necessaria para o aluger de uma bicicleta (tipo de bicicleta,
 * numero de horas e data).
 * E chamado o metodo da classe utente alugaBicicleta.
 * O aluguer e feito no ponto de partilha mais proximo do utente.
 * Caso o utente seja Regular e apresentado o total a pagar pelo aluguer.
 * No final, chama a funcao Sistem_Manager para gerir as bicicletas.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param index indice do utente no vetor de utentes do sistema
 */
void Sistema::alugaBike(int index) {

	vector<int> distancias = getOrderedPP(index);

	if(utentes.at(index)->getAvailable() == false)
	{
		cout << "Não é possível alugar duas bicicletas em simultâneo !"  << endl << endl;

		return;
	}
	else
	{
		cout << "Aluga Bicicleta: " << endl << endl;

		cout << "Preencha os seguintes campos: " << endl << endl;
		string bikeType;
		Data d1;
		int numHours{};
		int value {};
		string option {};

		cout << "Tipos de bicicleta: " << endl;
		cout << "     1 - Urbana" << endl;
		cout << "     2 - Urbana Simples" << endl;
		cout << "     3 - Corrida" << endl;
		cout << "     4 - Infantil" << endl << endl;

		//Executa até obter um tipo de bicicleta válido
		while(1)
		{
			try{
				cout << endl << "Introduza uma opção [1-4]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 4)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		//Verifica o tipo de bicicleta selecionada
		if(value == 1)
			bikeType = "Urbana";
		else if(value == 2)
			bikeType = "Urbana Simples";
		else if(value == 3)
			bikeType = "Corrida";
		else
			bikeType = "Infantil";

		//Executa até obter um número de horas válido
		while(1)
		{
			try{
				cout << endl << "Número de horas [1-24]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 24)
					throw OpcaoInvalida<int>(value);

				numHours = value;
				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Número de horas inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Número de horas inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		//Executa até obter um ano válido
		while(1)
		{
			try{
				cout << endl << "Ano [2017 - ...]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 2017)
					throw OpcaoInvalida<int>(value);

				d1.setAno(value);
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

		//Executa até obter um mês válido
		while(1)
		{
			try{
				cout << endl << "Mês [1-12]: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 12)
					throw OpcaoInvalida<int>(value);

				d1.setMes(value);
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

		/* Executa até obter um dia válido
		 * Considera que fevereiro tem 28 dias
		 */
		while(1)
		{
			try{
				cout << endl << "Dia: ";
				cin >> option;
				cin.ignore(1000,'\n');
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(d1.getMes() == 2)
				{
					if(value < 1 || value > 28)
						throw OpcaoInvalida<int>(value);

					d1.setDia(value);
					break;
				}
				else if((d1.getMes() == 1) ||(d1.getMes() == 3) ||(d1.getMes() == 5) ||(d1.getMes() == 7) ||(d1.getMes() == 8) ||(d1.getMes() == 10) ||(d1.getMes() == 12))
				{
					if(value < 1 || value > 31)
						throw OpcaoInvalida<int>(value);

					d1.setDia(value);
					break;
				}
				else
				{
					if(value < 1 || value > 30)
						throw OpcaoInvalida<int>(value);

					d1.setDia(value);
					break;
				}
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Dia inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Dia inválido (" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		int idPP {};
		vector<string> bikesType;

		//Verifica se tem o tipo de bicicleta pretendida por ordem de distância
		for (unsigned int i=0 ; i < distancias.size(); i++)
		{
			bikesType = pontosPartilha.at(distancias.at(i))->getBikeTypes();

			idPP = SequentialSearch(bikesType,bikeType);

			if(idPP != -1){
				idPP = distancias.at(i);
				break;
			}
		}

		if(idPP == -1)
		{
			cout << endl << "Neste momento não existe nenhuma bicicleta do tipo " << bikeType << " disponível." << endl << endl;
		}
		else
		{
			Utilizacao p(bikeType, numHours, d1,pontosPartilha.at(idPP)->getNome(),pontosPartilha.at(idPP)->getLocal().getNome());
			double price {0};

			Bicicleta* bike {};

			if(bikeType == "Urbana")
				bike = pontosPartilha.at(idPP)->getBikes().at(0).at(0);
			else if(bikeType == "Urbana Simples")
				bike = pontosPartilha.at(idPP)->getBikes().at(1).at(0);
			else if(bikeType == "Corrida")
				bike = pontosPartilha.at(idPP)->getBikes().at(2).at(0);
			else
				bike = pontosPartilha.at(idPP)->getBikes().at(3).at(0);

			utentes.at(index)->alugaBicicleta(bike,p);

			pontosPartilha.at(idPP)->removeBike(bike->getBikeName());

			if(utentes.at(index)->getTipoUtente() == "Regular")
			{
				price = p.getPrice();
			}

			cout << endl;
			system("cls");

			mensagemInicial();

			cout << "Aluga Bicicleta: " << endl << endl;
			cout << "Resumo do aluguer: " << endl << endl;

			p.displayUtilizacao();

			if(price !=0)
				cout << "Montante: " << price << "€" << endl;

			system_Manager(idPP,bikeType);

			cout << endl << "Bicicleta alugada com sucesso !" << endl << endl;
		}

		return;
	}
}

/**
 * Apresenta a informacao do aluger e chama-se o metodo da classe utente removeBicicleta.
 * A devolucao e feita no ponto de partilha mais proximo do utente.
 * No final, chama a funcao Sistem_Manager para gerir as bicicletas.
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void Sistema::devolveBike(int index) {

	if(utentes.at(index)->getAvailable() == true)
	{
		cout << "Neste momento o utente não tem nenhuma bicicleta para entregar" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	int index_pp {-1};
	vector<int> index_distancias = getOrderedPP(index);
	Bicicleta* bike {};

	bike = utentes.at(index)->removeBicicleta(index_distancias);

	for(unsigned int i = 0; i < index_distancias.size(); i++)
	{
		int lotacao {0};

		for(unsigned int k = 0; k < pontosPartilha.at(index_distancias.at(i))->getNumberOfBikes().size(); k++)
		{
			lotacao += pontosPartilha.at(index_distancias.at(i))->getNumberOfBikes().at(k);
		}

		if(pontosPartilha.at(index_distancias.at(i))->getCapacidade() > lotacao)
		{
			index_pp = index_distancias.at(i);
			pontosPartilha.at(index_distancias.at(i))->adicionaBike(bike);

			break;
		}
	}

	cout << "Devolve bicicleta: " << endl << endl;
	cout << "Resumo do último aluguer: " << endl << endl;

	string bikeType;

	//Verifica o tipo de utente e apresenta a respetiva informação

	Utilizacao ut = utentes.at(index)->getLastUse();
	bikeType = ut.getBikeType();
	ut.displayUtilizacao();

	if(utentes.at(index)->getTipoUtente() == "Regular")
	{
		cout << "Montante: " << ut.getPrice() << "€" << endl;

	}

	cout << endl << "Bicicleta devolvida com sucesso no ponto de partilha ECO_RIDES_" << pontosPartilha.at(index_pp)->getNome() << " !" << endl << endl;

	system_Manager(index_pp,bikeType);

	return;
}

/**
 * Apresenta o tipo de utente atual e pergunta para qual o tipo que pretende mudar, pede confirmacao da decisao e
 * chama o metodo da classe utente setTipoUtente.
 * Se o utente Socio tentar mudar para Regular e ainda tiver pagamentos pendentes e-lhe apresentada uma mensagem
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void Sistema::mudaTipoUT(int index){

	cout << "Muda tipo de utente" << endl << endl;

	string option;
	string tipo = utentes.at(index)->getTipoUtente();

	if(utentes.at(index)->getAvailable() == false)
	{
		cout << "Não é possível mudar o tipo de utente uma vez que a bicicleta alugada ainda não foi devolvida" << endl << endl;
		return;
	}

	if(utentes.at(index)->hasPendingPay())
	{
		cout << "Neste momento não é possível mudar o tipo de utente visto que existem pagamentos pendentes" << endl << endl;
		return;
	}

	//if(tipo == "Socio")
	//	if(utentes.at(index)->getUtilizacoes().size() != 0){
	//		cout << "Neste momento não é possível mudar o tipo de utente visto que existem pagamentos pendentes" << endl << endl;
	//		return;
	//	}

	cout << "Neste momento encontra-se definido como: " << tipo << endl << endl;

	while(1)
	{
		try {
			if(tipo == "Regular")
				cout << "Tem a certeza que pretende mudar para Sócio [Y/N]: ";
			else
				cout << "Tem a certeza que pretende mudar para Regular [Y/N]: ";

			cin >> option;
			cin.ignore(1000,'\n');

			if(valid_word(option) == false)
				throw OpcaoInvalida<string>(option);

			if((option == "Y") || (option == "N"))
				break;

			throw OpcaoInvalida<string>(option);
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Opção inválida (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	}

	if(option == "Y")
	{
		if(tipo == "Regular") {
			int id = utentes.at(index)->getId();
			string nome = utentes.at(index)->getNome();
			Localizacao local = utentes.at(index)->getLocalizacao();
			vector<Utilizacao> hist = utentes.at(index)->getHistorico();
			utentes.erase(utentes.begin()+index);

			Utente* u = new Socio(nome,local);
			u->setID(id);
			u->setLastId();
			for(unsigned int i=0; i < hist.size() ; i++){
				u->setHistoric(hist.at(i));
			}

			utentes.at(index)=u;

			cout << endl << "Mudança efetuada com sucesso. Agora o seu tipo é: Sócio" << endl << endl;
		}
		else
		{
			int id = utentes.at(index)->getId();
			string nome = utentes.at(index)->getNome();
			Localizacao local = utentes.at(index)->getLocalizacao();
			vector<Utilizacao> hist = utentes.at(index)->getHistorico();
			utentes.erase(utentes.begin()+index);

			Utente* u = new Regular(nome,local);
			u->setID(id);
			u->setLastId();
			for(unsigned int i=0; i < hist.size() ; i++){
				u->setHistoric(hist.at(i));
			}

			utentes.at(index)=u;
			cout << endl << "Mudança efetuada com sucesso. Agora o seu tipo é: Regular" << endl << endl;
		}
	}
	else
		cout << endl << "Mudança cancelada com sucesso " << endl << endl;

	return;
}

/**
 * Verifica se exite excesso (<=8) ou defice (>=2) de bicicletas do tipo bikeType nos pontos de partilha,
 * caso se verifique as bicicletas sao distribuidas pelos pontos de partilha uniformemente.
 * @param ER sistema em execucao
 * @param index indice do ponto de partilha em que ocorreu o ultimo movimento (aluguer ou devolucao)
 * @param bikeType tipo de bicicleta que se pretende verificar
 */
void Sistema::system_Manager(unsigned int index, string bikeType) {

	int value {-1};
	int tamanho{-1};
	vector<int> indicesSup5, indicesInf5;

	if(bikeType == "Urbana")
		value = 0;
	else if(bikeType == "Urbana Simples")
		value = 1;
	else if(bikeType == "Corrida")
		value = 2;
	else
		value = 3;

	tamanho = pontosPartilha.at(index)->getBikes().at(value).size();

	//Guarda os indices dos pontos de partilha nos vetores indicesSup5 e indicesInf5
	for(unsigned int i = 0; i < pontosPartilha.size(); i++)
	{
		if(i != index)
		{
			if(pontosPartilha.at(i)->getBikes().at(value).size() > 5)
				indicesSup5.push_back(i);
			else if(pontosPartilha.at(i)->getBikes().at(value).size() < 5)
				indicesInf5.push_back(i);
		}

	}

	//Ordena os vectores por ordem crescente
	sort(indicesSup5.begin(), indicesSup5.end());
	sort(indicesInf5.begin(), indicesInf5.end());

	//Necessita de receber bicicletas
	if(tamanho <= 2)
	{
		//Distribui bicicletas
		for(int k = indicesSup5.size() - 1; k >= 0; k--)
		{
			while(pontosPartilha.at(indicesSup5.at(k))->getBikes().at(value).size() > 5)
			{
				if(pontosPartilha.at(index)->getBikes().at(value).size() == 5)
					break;

				pontosPartilha.at(index)->adicionaBike(pontosPartilha.at(indicesSup5.at(k))->getBikes().at(value).at(0));
				pontosPartilha.at(indicesSup5.at(k))->removeBike(pontosPartilha.at(indicesSup5.at(k))->getBikes().at(value).at(0)->getBikeName());
			}

			if(pontosPartilha.at(index)->getBikes().at(value).size() == 5)
				break;
		}
	}
	else if(tamanho >= 8)	//Necessita de fornecer bicicletas
	{
		//Distribui bicicletas
		for(unsigned int k = 0; k < indicesInf5.size(); k++)
		{
			while(pontosPartilha.at(indicesInf5.at(k))->getBikes().at(value).size() < 5)
			{
				if(pontosPartilha.at(index)->getBikes().at(value).size() == 5)
					break;

				pontosPartilha.at(indicesInf5.at(k))->adicionaBike(pontosPartilha.at(index)->getBikes().at(value).at(0));
				pontosPartilha.at(index)->removeBike(pontosPartilha.at(index)->getBikes().at(value).at(0)->getBikeName());
			}

			if(pontosPartilha.at(index)->getBikes().at(value).size() == 5)
				break;
		}
	}

	return;
}

/** Imprime por ordem crescente de distancia do utente, os pontos de partilha (nome e nome da localizacao).
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void Sistema::displayNearestPP(int index) const {

	cout << "Pontos de partilha mais próximos: " << endl << endl;

	vector<int> distancias = getOrderedPP(index);

	cout << "Ordem  Nome" << setw(16) << "Local"<< endl;

	for(unsigned int i = 0; i < distancias.size(); i++)
	{
		string nomePP = pontosPartilha.at(distancias.at(i))->getNome();
		string localName = pontosPartilha.at(distancias.at(i))->getLocal().getNome();

		cout << "  " << setw(5) << left << (i+1) << "ECO_RIDES_" << setw(5) << nomePP;
		cout << localName << endl;
	}

	cout << endl;

	return;
}

void Sistema::displayUtentes() const {

	cout << left << setw(15) << "   Nome" << setw(6) << " ID" << setw(27) << " Tipo de utente" << setw (20) << " GPS" << endl;

	for (unsigned int i=0 ; i	< utentes.size() ; i++)
	{
		cout << "-> " << setw(13) << utentes.at(i)->getNome();
		cout << setw(10) << utentes.at(i)->getId();
		cout << setw(14) << utentes.at(i)->getTipoUtente();
		cout << '(' << setw(9) << utentes.at(i)->getLocalizacao().getX();
		cout << "," << setw(9) << utentes.at(i)->getLocalizacao().getY() << setw(5) << ')' << endl;
	}

	cout << endl;

}
