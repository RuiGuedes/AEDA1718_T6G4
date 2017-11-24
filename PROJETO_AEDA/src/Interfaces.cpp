#include "Includes.h"
#include "Sistema.h"

/////////////////////////////////////
// IMPLEMENTA��O DE FUNCOES GERAIS //
/////////////////////////////////////

/**
 * Verifica se a string number contem apenas digitos ou se contem simbolos ou caracteres nao
 * aceites para a situacao.
 * @param number string extraida da stream de input
 * @return Retorna true se number e um numero e false se number contem alguma coisa para alem de digitos.
 */
bool valid_number(string number)
{
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
 * @return Retorna true se number e um numero decimal negativo ou positivo e false se number contem alguma coisa para alem de digitos.
 */
bool valid_number_double(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if ((!(isdigit(number.at(i)))) && (number.at(i) != '.') && (number.at(i) != '-'))
			return false;
	}
	return true;
}

/**
 * Verifica se a string word nao contem numeros.
 * @param word string extraida da stream de input
 * @return Retorna true se nao contem numeros e false caso contrario.
 */
bool valid_word(string word)
{
	for (unsigned int i = 0; i < word.size(); i++){
		if (isdigit(word.at(i)))
			return false;
	}
	return true;
}

/**
 * Verifica se o nome da bicicleta e correto, nao pode comecar por um numero.
 * @param bike string extraida da stream de input
 * @return Retorna true se nao comeca por um numero e false caso contrario.
 */
bool valid_bike(string bike)
{
	if (isdigit(bike.at(0)))
		return false;

	return true;
}

/**
 * Funcao que imprime no ecra o logotipo da empresa ECO RIDES.
 */
void mensagemInicial(){
	//Informacao inicial apresentada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "#####   ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;
}


/////////////////////////
// INTERFACES -> MENUS //
/////////////////////////

/**
 * Primeiramente imprime a informacao de todos os utentes e pede ao utente que insira um id
 * para efetuar o login.
 * Apresenta no ecra os casos de utilizacao para o utente escolher a opcao que pretende (10 opcoes no total).
 * Depois de introduzida a opcao por parte do utente, e efetuado o procedimento que
 * corresponde a opcao escolhida. Para cada uma das 9 primeiras opcoes e chamado um metodo da classe Sistema
 * ou Utente, que executa o procedimento necessario para o que o utente pretende, e a ultima opcao ,
 * 10 - Logout, retorna a funcao openInterfaces, onde esta foi invocada.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e e lancada uma excecao.
 * @param ER sistema em execucao
 */
void menu_interface(Sistema &ER){

	mensagemInicial();

	int attempts { 0 };
	int identificacao { };
	int index {};	//Indice do utente no vector de utentes do sistema
	string info;

	cout << "Utentes: " << endl << endl;

	ER.displayUtentes();

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

			index = ER.getUtenteIndex(identificacao);

			if(index == -1)
				throw OpcaoInvalida<int>(identificacao);

			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "ID inv�lido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();

		}
		catch (OpcaoInvalida<string> &op){

			cout << "ID inv�lido (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
		}
	};

	if(attempts >= 3)
	{
		cout << endl << "Acesso negado: n�mero de tentativas esgotado" << endl << endl;
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
		cout << "3  - Hist�rico" << endl;
		cout << "4  - Pagamentos pendentes" << endl;
		cout << "5  - Efetuar pagamento das mensalidades" << endl;
		cout << "6  - Atualiza localiza��o" << endl;
		cout << "7  - Pontos de partilha mais pr�ximos" << endl;
		cout << "8  - Mudar o tipo de utente" << endl;
		cout << "9  - Informa��es sobre ECO_RIDES" << endl;
		cout << "10 - Logout" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma op��o (1-10): ";
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

				cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		system("cls");
		mensagemInicial();

		//Opc�es possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			ER.alugaBike(index);
			break;
		case 2:
			ER.devolveBike(index);
			break;
		case 3:
			utente->displayHistoric();
			break;
		case 4:
			utente->displayPagPendentes(index);
			break;
		case 5:
			utente->efetuaPag(index);
			break;
		case 6:
			utente->updateLocation(index);
			break;
		case 7:
			ER.displayNearestPP(index);
			break;
		case 8:
			ER.mudaTipoUT(index);
			cout << "Ser� agora efetuado o logout do utente para atualiza��o dos dados do mesmo !" << endl << endl;
			value = 11;
			break;
		case 9:
			ER.getInfo();
			break;
		case 10:
			if(!utente->getAvailable()) {
				cout << endl << "Antes de efetuar logout o utente necessita primeiramente de devolver a bicicleta !" << endl;
				value = -1;
			}
			cout << endl;
			break;
		}

		if(value != 10)
			system("pause");

		system("cls");

	}while((value != 10) && (value != 11));

	cout << endl;
	system("cls");
	return;
}

/**
 * Primeiramente pede ao utilizador que insira a senha ("1234") para aceder a opcoes administrativas.
 * Apresenta no ecra os casos de utilizacao para aministrador escolher a opcao que pretende (7 opcoes no total).
 * Depois de introduzida a opcao, e efetuado o procedimento que corresponde a opcao escolhida.
 * Para cada uma das 6 primeiras opcoes e chamado um metodo da classe Sistema que
 * executa o procedimento necessario para o que e pretendido, e a ultima opcao , 7 - Sair,
 * retorna a funcao openInterfaces, onde esta foi invocada.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e e lancada uma excecao.
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

			cout << "Password inv�lida (" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	};

	if(attempts >= 3)
	{
		cout << endl << "Acesso negado: n�mero de tentativas esgotado" << endl << endl;
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

		cout << "Administra��o" << endl << endl;

		cout << "1 - Adiciona bicicleta" << endl;
		cout << "2 - Adiciona ponto partilha" << endl;
		cout << "3 - Remove bicicleta" << endl;
		cout << "4 - Remove ponto de partilha" << endl;
		cout << "5 - Remove utente" << endl;
		cout << "6 - Informa��es sobre ECO_RIDES" << endl;
		cout << "7 - Sair" << endl;


		while(1)
		{
			try {

				cout << endl << "Introduza uma op��o (1-7): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 7)
					throw OpcaoInvalida<int>(value);

				break;
			}
			catch (OpcaoInvalida<int> &op){

				cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		system("cls");
		mensagemInicial();

		//Opc�es poss�veis apresentadas no menu
		switch (value)
		{
		case 1:
			ER.adicionaBike();
			break;
		case 2:
			ER.addPontoPartilha();
			break;
		case 3:
			ER.removeBike();
			break;
		case 4:
			ER.removePonto();
			break;
		case 5:
			ER.removeUtente();
			break;
		case 6:
			ER.getInfo();
			break;
		case 7:
			cout << endl;
			break;
		}
		if(value != 7)
			system("pause");

		system("cls");

	}while(value != 7);

	system("cls");
	return;
}

/**
 * Apresenta no ecra a pagina inicial do programa, e aguarda que o utente decida qual a opcao
 * que deseja. Depois de introduzida a opcao por parte do utente, e efetuado o procedimento que
 * corresponde a opcao escolhida. 1-Registar chama a funcao registaUtente; 2-Entrar chama a funcao
 * menu_interfaces; 3- Administrador chama a funcao admin_interfaces; 4 - Sair retorna a funcao main,
 * onde esta ,openinterfaces, e invocada.
 * Para cada introducao do utente e verificado se o mesmo introduziu o formato de dados pedido
 * e se os dados sao validos, caso contrario e impressa uma mensagem e e lancada uma excecao.
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
				cout << endl << "Introduza uma op��o (1-4): ";
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

				cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Op��o inv�lida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
			}
		};

		system("cls");

		//Opc�es possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			ER.addNewUtente();
			break;
		case 2:
			menu_interface(ER);
			break;
		case 3:
			admin_interface(ER);
			break;
		case 4:
			cout << endl;
			break;
		}
	}while(value != 4);

	return;
}

