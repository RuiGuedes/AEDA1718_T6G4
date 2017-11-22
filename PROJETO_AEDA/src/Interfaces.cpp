#include "Includes.h"
#include "Sistema.h"

///**
// * Procura um valor x num vetor v de elementos comparaveis com os operadores de comparacao.
// * @param v vetor de elementos
// * @param x valor a procurar no vetor
// * @return Retorna o indice da primeira ocorrencia de x em v, se encontrar; senao, retorna -1.
// */
//template <class T>
//int SequentialSearch(const vector<T> &v, T x)
//{
//	for (unsigned int i = 0; i < v.size(); i++)
//		if (v[i] == x)
//			return i;// encontrou
//	return -1; // não encontrou
//}


/////////////////////////////////////////////////////
// PROTOTIPOS DAS FUNCOES UTILIZADAS EM INTERFACES //
/////////////////////////////////////////////////////
void menu_interface(Sistema &BS);
void admin_interface(Sistema &BS);


/////////////////////////////////////
// IMPLEMENTAÇÃO DE FUNCOES GERAIS //
/////////////////////////////////////

/**
 * Verifica se a string number contem apenas digitos ou se contem simbolos ou caracteres nao
 * aceites para a situacao.
 * @param number string extraida da stream de input
 * @return Retorna true se number e um numero e false se number contem alguma coisa para alem de digitos
 */
bool valid_number(string number)
{
	//Verifica se um número é positivo e contem apenas algarismos
	for (unsigned int i = 0; i < number.size(); i++){
		if (!(isdigit(number.at(i))))
			return false;
	}
	return true;
}

/**
 * Verifica se a string number contem apenas digitos e um ponto ou um hifen,
 * ou se contem simbolos ou caracteres nao aceites para a situacao.
 * @param number string extraida da stream de input
 * @return Retorna true se number e um numero decimal negativo ou positivo e false se number contem alguma coisa para alem de digitos
 */
bool valid_number_double(string number)
{
	//Verifica se um número é positivo/negativo e contem apenas algarismos ou apenas "." e "-"
	for (unsigned int i = 0; i < number.size(); i++){
		if ((!(isdigit(number.at(i)))) && (number.at(i) != '.') && (number.at(i) != '-'))
			return false;
	}
	return true;
}

/**
 * Verifica se a string word nao contem numeros
 * @param word string extraida da stream de input
 * @return Retorna true se nao contem numeros e false caso contrario
 */
bool valid_word(string word)
{
	//Verifica se é string e não contem numeros
	for (unsigned int i = 0; i < word.size(); i++){
		if (isdigit(word.at(i)))
			return false;
	}
	return true;
}

/**
 * Verifica se o nome da bicicleta e correto, nao pode comecar por um numero
 * @param bike string extraida da stream de input
 * @return Retorna true se nao comeca por um numero e false caso contrario
 */
bool valid_bike(string bike)
{
	//Verifica se o nome da bicicleta é correto - não pode começar por um número
	if (isdigit(bike.at(0)))
		return false;

	return true;
}

/**
 * Funcao que imprime no ecra o logotipo da empresa ECO RIDES
 * (nome defenido pelo grupo)
 */
void mensagemInicial(){
	//Informacao inicial apresentada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "#####   ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
}

/**
 * Verifica se existe o utente com numero de identificacao =identificacao no sistema ER
 * @param sys sistema em execucao
 * @param identificacao numero de identificacao de um utente
 * @return Retorna o indice do utente no vetor de utentes do sistema se este existir e -1 caso contrario
 */
int ExistID(Sistema & sys, int identificacao) {

	for(unsigned int i = 0; i < sys.getUtentes().size() ; i++)
	{
		if(sys.getUtentes().at(i)->getId() == identificacao)
			return i;
	}

	return -1;
}


////////////////////////////////////////////////////////////
// IMPLEMENTACAO DE FUNCOES COMUNS AS DIVERSAS INTERFACES //
////////////////////////////////////////////////////////////


/////////////////////////////////////////////////
// IMPLEMENTACAO DAS FUNCOES -> MENU INTERFACE //
/////////////////////////////////////////////////

/**
 * Imprime por ordem crescente de distancia do utente, os pontos de partilha (nome e nome da localizacao).
 * @param ER sistema em execucao
 * @param index indice do utente no vetor de utentes do sistema
 */
void NearestPP(Sistema &ER,int index) {

	cout << "Pontos de partilha mais próximos: " << endl << endl;

	vector<double> distancias;

	for(unsigned int i = 0; i < ER.getPontosPartilha().size(); i++)
	{
		distancias.push_back(ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(i)->getLocal()));
	}

	sort(distancias.begin(),distancias.end());

	cout << "Ordem  Nome" << setw(16) << "Local"<< endl;

	for(unsigned int i = 0; i < distancias.size(); i++)
	{
		for(unsigned int k = 0; k < ER.getPontosPartilha().size(); k++)
		{
			if(distancias.at(i) == ER.getUtentes().at(index)->getLocalizacao().distancia(ER.getPontosPartilha().at(k)->getLocal()))
			{
				cout << "  " << setw(5) << left << (i+1) << "ECO_RIDES_" << setw(5) << ER.getPontosPartilha().at(k)->getNome();
				cout << ER.getPontosPartilha().at(k)->getLocal().getNome() << endl;
			}

		}
	}

	cout << endl;

	return;
}



//////////////////////////////////////////////////
// IMPLEMENTACAO DAS FUNCOES -> ADMIN INTERFACE //
//////////////////////////////////////////////////


/////////////////////////
// INTERFACES -> MENUS //
/////////////////////////

/**
 * Apresenta no ecra a pagina inicial do programa, e aguarda que o utente decida qual a opcao
 * que deseja. Depois de introduzida a opcao por parte do utente, e efetuado o procedimento que
 * corresponde a opcao escolhida. 1-Registar chama a funcao registaUtente; 2-Entrar chama a funcao
 * menu_interfaces; 3- Administrador chama a funcao admin_interfaces; 4 - Sair retorna a funcao main,
 * onde esta ,openinterfaces, e invocada.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 */
void openInterface(Sistema & ER){

	int value { };
	string option;

	do
	{
		mensagemInicial();

		cout << "1 - Registar " << endl;
		cout << "2 - Entrar" << endl;
		cout << "3 - Administrador" << endl;
		cout << "4 - Sair" << endl;

		while(1)
		{
			try{
				cout << endl << "Introduza uma opção (1-4): ";
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

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			mensagemInicial();
			ER.addNewUtente();
			break;
		case 2:
			system("cls");
			menu_interface(ER);
			break;
		case 3:
			system("cls");
			admin_interface(ER);
			break;
		case 4:
			cout << endl;
			break;
		}
	}while(value != 4);
	return;
}

/**
 * Primeiramente imprime a informacao de todos os utentes e pede ao utente que insira um id
 * para efetuar o login.
 * Apresenta no ecra os casos de utilizacao para o utente escolher a opcao que pretende (10 opcoes no total).
 * Depois de introduzida a opcao por parte do utente, e efetuado o procedimento que
 * corresponde a opcao escolhida. Para cada uma das 9 primeiras opcoes e chamada uma outra funcao que
 * executa o procedimento necessario para o que o utente pretende, e a ultima opcao , 10 - Logout,
 * retorna a funcao openInterfaces, onde esta foi invocada.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 */
void menu_interface(Sistema &ER){

	mensagemInicial();

	int attempts { 0 };
	int identificacao { };
	int index {};	//Indice do utente no vector de utentes do sistema
	string info;

	cout << "Utentes: " << endl << endl;

	cout << left << setw(15) << "   Nome" << setw(6) << " ID" << setw(27) << " Tipo de utente" << setw (20) << " GPS" << endl;

	for (unsigned int i=0 ; i<ER.getUtentes().size() ; i++)
	{
		cout << "-> " << setw(13) << ER.getUtentes().at(i)->getNome();
		cout << setw(10) << ER.getUtentes().at(i)->getId();
		cout << setw(14) <<ER.getUtentes().at(i)->getTipoUtente();
		cout << '(' << setw(9) << ER.getUtentes().at(i)->getLocalizacao().getX();
		cout << "," << setw(9) << ER.getUtentes().at(i)->getLocalizacao().getY() << setw(5) << ')' << endl;
	}

	cout << endl;

	while(attempts < 3)
	{
		try{
			attempts++;
			cout << "Login [Utente ID]: ";
			cin >> info;
			cin.ignore(1000,'\n');

			if(valid_number(info) == false)
				throw OpcaoInvalida<string>(info);

			identificacao = stoi(info);

			index = ExistID(ER,identificacao);

			if(index == -1)
				throw OpcaoInvalida<int>(identificacao);

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
	};

	if(attempts >= 3)
	{
		cout << endl << "Acesso negado: número de tentativas esgotado" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	system("cls");

	Utente* utente = ER.getUtentes().at(index);

	string option;
	int value {};

	do
	{
		mensagemInicial();

		cout << "Bem-Vindo !" << endl << endl;

		cout << "1  - Alugar bicicleta" << endl;
		cout << "2  - Devolver bicicleta" << endl;
		cout << "3  - Histórico" << endl;
		cout << "4  - Pagamentos pendentes" << endl;
		cout << "5  - Efetuar pagamento das mensalidades" << endl;
		cout << "6  - Atualiza localização" << endl;
		cout << "7  - Pontos de partilha mais próximos" << endl;
		cout << "8  - Mudar o tipo de utente" << endl;
		cout << "9  - Informações sobre ECO_RIDES" << endl;
		cout << "10 - Logout" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma opção (1-10): ";
				cin >> option;
				cin.ignore(1000,'\n');

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 10)
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

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			mensagemInicial();
			ER.alugaBike(index);
			break;
		case 2:
			system("cls");
			mensagemInicial();
			ER.devolveBike(index);
			break;
		case 3:
			system("cls");
			mensagemInicial();
			utente->displayHistoric();
			break;
		case 4:
			system("cls");
			mensagemInicial();
			utente->displayPagPendentes(index);
			break;
		case 5:
			system("cls");
			mensagemInicial();
			utente->efetuaPag(index);
			break;
		case 6:
			system("cls");
			mensagemInicial();
			utente->updateLocation(index);
			break;
		case 7:
			system("cls");
			mensagemInicial();
			NearestPP(ER,index);
			break;
		case 8:
			system("cls");
			mensagemInicial();
			ER.mudaTipoUT(index);
			break;
		case 9:
			system("cls");
			mensagemInicial();
			ER.infoER();
			break;
		case 10:
			if(utente->getAvailable() == false)
			{
				cout << endl << "Antes de efetuar logout o utente necessita primeiramente de devolver a bicicleta !" << endl << endl;
				value = -1;
			}
			else
				cout << endl;
			break;
		}

		system("pause");
		system("cls");

	}while(value != 10);

	cout << endl;
	system("cls");
	return;

}

/**
 * Primeiramente pede ao utilizador que insira a senha ("1234") para aceder a opcoes administrativas.
 * Apresenta no ecra os casos de utilizacao para aministrador escolher a opcao que pretende (7 opcoes no total).
 * Depois de introduzida a opcao, e efetuado o procedimento que corresponde a opcao escolhida.
 * Para cada uma das 6 primeiras opcoes e chamada uma outra funcao que
 * executa o procedimento necessario para o que e pretendido, e a ultima opcao , 7 - Sair,
 * retorna a funcao openInterfaces, onde esta foi invocada.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e levantada uma excecao.
 * @param ER sistema em execucao
 */
void admin_interface(Sistema &ER) {

	mensagemInicial();

	int attempts { 0 };
	string info;

	while(attempts < 3)
	{
		try{
			attempts++;
			cout << "Admin (Password): ";
			cin >> info;

			if(valid_number(info) == false)
				throw OpcaoInvalida<string>(info);

			if(info != "1234")
				throw OpcaoInvalida<string>(info);

			break;
		}
		catch (OpcaoInvalida<string> &op){

			cout << "Password inválida (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	if(attempts >= 3)
	{
		cout << endl << "Acesso negado: número de tentativas esgotado" << endl << endl;
		system("pause");
		system("cls");
		return;
	}

	system("cls");

	string option;
	int value {};

	do
	{
		mensagemInicial();

		cout << "Administração" << endl << endl;

		cout << "1 - Adiciona bicicleta" << endl;
		cout << "2 - Adiciona ponto partilha" << endl;
		cout << "3 - Remove bicicleta" << endl;
		cout << "4 - Remove ponto de partilha" << endl;
		cout << "5 - Remove utente" << endl;
		cout << "6 - Informações sobre ECO_RIDES" << endl;
		cout << "7 - Sair" << endl;


		while(1)
		{
			try {

				cout << endl << "Introduza uma opção (1-7): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 7)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};


		//Opcões possíveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			mensagemInicial();
			ER.adicionaBike();
			break;
		case 2:
			system("cls");
			mensagemInicial();
			ER.addPontoPartilha();
			break;
		case 3:
			system("cls");
			mensagemInicial();
			ER.removeBike();
			break;
		case 4:
			system("cls");
			mensagemInicial();
			ER.removePonto();
			break;
		case 5:
			system("cls");
			mensagemInicial();
			ER.removeUtente();
			break;
		case 6:
			system("cls");
			mensagemInicial();
			ER.infoER();
			break;
		case 7:
			cout << endl;
			break;
		}
		system("pause");
		system("cls");
	}while(value != 7);

	system("cls");
	return;
}
