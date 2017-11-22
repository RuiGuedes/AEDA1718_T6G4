#include "Sistema.h"

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

	for(unsigned int i = 0; i < getPontosPartilha().size(); i++)
	{
		if((getPontosPartilha().at(i)->getLocal().getX() == coordX) && (getPontosPartilha().at(i)->getLocal().getY() == coordY))
		{
			spot.setNome(getPontosPartilha().at(i)->getLocal().getNome());
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

	system("pause");
	system("cls");
	return;

}


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

			for(unsigned int i = 0; i < getPontosPartilha().size(); i++)
			{
				if(getPontosPartilha().at(i)->getNome() == nome)
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

			for(unsigned int i = 0; i < getPontosPartilha().size(); i++)
			{
				if(getPontosPartilha().at(i)->getLocal().getNome() == locname)
				{
					diffloc = false;
					spot.setNome(locname);
					spot.setX(getPontosPartilha().at(i)->getLocal().getX());
					spot.setY(getPontosPartilha().at(i)->getLocal().getY());
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


			for(unsigned int i = 0; i < getPontosPartilha().size(); i++)
			{
				if((getPontosPartilha().at(i)->getLocal().getX() == coordX) && (getPontosPartilha().at(i)->getLocal().getY() == coordY))
				{
					newcord = false;
					cout << "Essas coordenadas já pertencem à localização: " << getPontosPartilha().at(i)->getLocal().getNome() << endl << endl;
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
		string u = "u" + to_string(getPontosPartilha().at(0)->getBikeNextId("Urbana"));
		string us = "us" + to_string(getPontosPartilha().at(0)->getBikeNextId("Urbana Simples"));
		string c = "c" + to_string(getPontosPartilha().at(0)->getBikeNextId("Corrida"));
		string inf = "i" + to_string(getPontosPartilha().at(0)->getBikeNextId("Infantil"));

		Bicicleta* b1 = new Bicicleta("Urbana",u);
		Bicicleta* b2 = new Bicicleta("Urbana Simples",us);
		Bicicleta* b3 = new Bicicleta("Corrida",c);
		Bicicleta* b4 = new Bicicleta("Infantil",inf);

		getPontosPartilha().at(getPontosPartilha().size() - 1)->adicionaBike(b1);
		getPontosPartilha().at(getPontosPartilha().size() - 1)->adicionaBike(b2);
		getPontosPartilha().at(getPontosPartilha().size() - 1)->adicionaBike(b3);
		getPontosPartilha().at(getPontosPartilha().size() - 1)->adicionaBike(b4);

		getPontosPartilha().at(0)->setBikeNextIdForward("Urbana");
		getPontosPartilha().at(0)->setBikeNextIdForward("Urbana Simples");
		getPontosPartilha().at(0)->setBikeNextIdForward("Corrida");
		getPontosPartilha().at(0)->setBikeNextIdForward("Infantil");
	}

	cout << endl << "Novo ponto de partilha adicionado ao sistema" << endl << endl;

	system("pause");
	system("cls");
	return;

}


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

	if(getPontosPartilha().size() == 0)
	{
		cout << "Neste momento não existem pontos de partilha !" << endl << endl;

		system("pause");
		system("cls");
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

			for(unsigned int i = 0; i < getPontosPartilha().size(); i++)
			{
				if(getPontosPartilha().at(i)->getNome() == nomePP)
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

	system("pause");
	system("cls");
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

	if(getUtentes().size() == 0)
	{
		cout << "Neste momento não existem utentes !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	cout << left << setw(15) << "   Nome" << setw(6) << " ID" << setw(27) << " Tipo de utente" << setw (20) << " GPS" << endl;

	for (unsigned int i=0 ; i< getUtentes().size() ; i++)
	{
		cout << "-> " << setw(13) << getUtentes().at(i)->getNome();
		cout << setw(10) << getUtentes().at(i)->getId();
		cout << setw(14) <<getUtentes().at(i)->getTipoUtente();
		cout << '(' << setw(9) << getUtentes().at(i)->getLocalizacao().getX();
		cout << "," << setw(9) << getUtentes().at(i)->getLocalizacao().getY() << setw(5) << ')' << endl;
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
			for(unsigned int i = 0; i < getUtentes().size(); i++)
			{
				if(getUtentes().at(i)->getId() == idUT)
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

	if((unsigned int)indexUT == getUtentes().size())
	{

		getUtentes().at(0)->setLastId();

		cout << endl << "Utente removido com sucesso !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}

	for(unsigned int i = indexUT; i < getUtentes().size(); i++)
	{
		getUtentes().at(i)->setIDBackward();
	}

	getUtentes().at(0)->setLastId();

	cout << endl << "Utente removido com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;

}


/**
 * Verifica se exite excesso (<=8) ou defice (>=2) de bicicletas do tipo bikeType nos pontos de partilha,
 * caso se verifique as bicicletas sao distribuidas pelos pontos de partilha uniformemente.
 * @param ER sistema em execucao
 * @param index indice do ponto de partilha em que ocorreu o ultimo movimento (aluguer ou devolucao)
 * @param bikeType tipo de bicicleta que se pretende verificar
 */
void Sistema::System_Manager(unsigned int index, string bikeType) {

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

	tamanho = getPontosPartilha().at(index)->getBikes().at(value).size();

	//Guarda os indices dos pontos de partilha nos vetores indicesSup5 e indicesInf5
	for(unsigned int i = 0; i < getPontosPartilha().size(); i++)
	{
		if(i != index)
		{
			if(getPontosPartilha().at(i)->getBikes().at(value).size() > 5)
				indicesSup5.push_back(i);
			else if(getPontosPartilha().at(i)->getBikes().at(value).size() < 5)
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
			while(getPontosPartilha().at(indicesSup5.at(k))->getBikes().at(value).size() > 5)
			{
				if(getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
					break;

				getPontosPartilha().at(index)->adicionaBike(getPontosPartilha().at(indicesSup5.at(k))->getBikes().at(value).at(0));
				getPontosPartilha().at(indicesSup5.at(k))->removeBike(getPontosPartilha().at(indicesSup5.at(k))->getBikes().at(value).at(0));
			}

			if(getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
				break;
		}
	}
	else if(tamanho >= 8)	//Necessita de fornecer bicicletas
	{
		//Distribui bicicletas
		for(unsigned int k = 0; k < indicesInf5.size(); k++)
		{
			while(getPontosPartilha().at(indicesInf5.at(k))->getBikes().at(value).size() < 5)
			{
				if(getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
					break;

				getPontosPartilha().at(indicesInf5.at(k))->adicionaBike(getPontosPartilha().at(index)->getBikes().at(value).at(0));
				getPontosPartilha().at(index)->removeBike(getPontosPartilha().at(index)->getBikes().at(value).at(0));
			}

			if(getPontosPartilha().at(index)->getBikes().at(value).size() == 5)
				break;
		}
	}

	return;
}


/**
 * Imprime no ecra toda a informacao referente ao sistema, nome da empresa, pontos de partilha
 * (incluindo nome, localizacao (nome e coordenadas) e quantidades de cada tipo de bicicletas),
 *  utentes (incluindo nome, id, tipo e coordenadas GPS), tabela de precos por hora e mensalidades
 *  e por fim, os fundadores.
 * @param ER sistema em execucao
 */
void Sistema::infoER(){

	cout << "Informações:" << endl << endl;

	cout << "Nome da empresa: ECO RIDES" << endl << endl;
	cout << "Número total de pontos de Partilha: " << getPontosPartilha().size() << endl << endl;
	cout << "Pontos de Partilha:" << endl << endl;
	cout << setw (15) << left << "Nome" << setw (22) << "Local" << setw (13) << "GPS";
	cout << setw (10) << "Urbana" << setw (18) << "Urbana Simples" <<
			setw (9) << "Corrida" << setw(10) << "Infantil" << "Capacidade" << endl;

	for (unsigned int i=0 ; i<getPontosPartilha().size() ; i++){
		cout << setw(5) << getPontosPartilha().at(i)->getNome();
		cout << setw(23) << getPontosPartilha().at(i)->getLocal().getNome();
		cout << '(' << setw(9) << getPontosPartilha().at(i)->getLocal().getX();
		cout << "," << setw(9) << getPontosPartilha().at(i)->getLocal().getY() << setw(5) << ')';

		vector<int> numtypes = getPontosPartilha().at(i)->getNumberOfBikes();

		cout << setw(13) << numtypes.at(0);
		cout << setw(15) << numtypes.at(1);
		cout << setw(9) << numtypes.at(2);
		cout << setw(11) << numtypes.at(3);
		cout << getPontosPartilha().at(i)->getCapacidade();

		cout << endl;
	}

	cout << endl;

	cout << "Número total de utentes registados: " << getUtentes().size() << endl << endl;

	cout << left << setw(15) << "  Nome" << setw(6) << "ID" << setw(27) << "Tipo de utente" << setw (20) << "GPS" << endl;

	for (unsigned int i=0 ; i<getUtentes().size() ; i++){
		cout << setw(15) << getUtentes().at(i)->getNome();
		cout << setw(10) << getUtentes().at(i)->getId();
		cout << setw(14) <<getUtentes().at(i)->getTipoUtente();
		cout << '(' << setw(9) << getUtentes().at(i)->getLocalizacao().getX();
		cout << "," << setw(9) << getUtentes().at(i)->getLocalizacao().getY() << setw(5) << ')' << endl;
	}

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

	system("pause");
	system("cls");
	return;

}


void Sistema::addNewUtente(Utente* u1){
	utentes.push_back(u1);
}

void Sistema::addPontoPartilha(PontoPartilha* p){
	pontosPartilha.push_back(p);
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



