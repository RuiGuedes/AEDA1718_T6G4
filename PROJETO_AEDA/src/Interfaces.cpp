#include "Includes.h"
#include "Sistema.h"

/////////////////////////////////////
// IMPLEMENTAÇÃO DE FUNCOES GERAIS //
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
		cout << "8  - Comprar bicicletas" << endl;
		cout << "9  - Lojas com maior reputação" << endl;
		cout << "10 - Mudar o tipo de utente" << endl;
		cout << "11 - Informações sobre ECO_RIDES" << endl;
		cout << "12 - Logout" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma opção (1-12): ";
				cin >> option;
				cin.ignore(1000,'\n');

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 12)
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

		system("cls");
		mensagemInicial();

		//Opcões possiveis apresentadas no menu
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
			/*
			 * 	Comprar uma certa quantidade de bicicletas na loja com maior reputação e com stock disponível.
			 * 	A cada compra deve ser atribuída uma classificação (0-5) da satisfação para atualizar a reputação da respetiva loja.
			 */
			break;
		case 9:
			/*
			 *	Deve ser possível listar o top 5 das lojas com maior reputação.
			 */
			break;
		case 10:
			value = ER.mudaTipoUT(index);
			if(value == 0)
			{
				cout << "Será agora efetuado o logout do utente para atualização dos dados do mesmo !" << endl << endl;
				value = 13;
			}
			else
				value = 10;
			break;
		case 11:
			ER.getInfo();
			break;
		case 12:
			if(!utente->getAvailable()) {
				cout << endl << "Antes de efetuar logout o utente necessita primeiramente de devolver a bicicleta !" << endl;
				value = -1;
			}
			cout << endl;
			break;
		}

		if(value != 12)
			system("pause");

		system("cls");

	}while((value != 12) && (value != 13));

	cout << endl;
	system("cls");
	return;
}

void oficina_interface(Sistema &ER) {

	system("cls");

	string option;
	int value {};

	do
	{
		mensagemInicial();

		cout << "Oficina" << endl << endl;

		cout << "1 - Comprar peças" << endl;
		cout << "2 - Verificar qual o fornecedor que vendeu uma determinada peça ao preço mais baixo" << endl;
		cout << "3 - Adicionar peças" << endl;
		cout << "4 - Remover peças" << endl;
		cout << "5 - Informações acerca dos fornecedores" << endl;
		cout << "6 - Voltar" << endl;


		while(1)
		{
			try {

				cout << endl << "Introduza uma opção (1-6): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 6)
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

		system("cls");
		mensagemInicial();

		//Opcões possíveis apresentadas no menu
		switch (value)
		{
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			break;
		}

		system("cls");

	}while(value != 6);

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
		cout << "6 - Oficina" << endl;
		cout << "7 - Informações sobre ECO_RIDES" << endl;
		cout << "8 - Sair" << endl;


		while(1)
		{
			try {

				cout << endl << "Introduza uma opção (1-8): ";
				cin >> option;

				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);

				if(value < 1 || value > 8)
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

		system("cls");
		mensagemInicial();

		//Opcões possíveis apresentadas no menu
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
			oficina_interface(ER);
			break;
		case 7:
			ER.getInfo();
			break;
		case 8:
			cout << endl;
			break;
		}
		if((value != 8) && (value != 6))
			system("pause");

		system("cls");

	}while(value != 8);

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

		system("cls");

		//Opcões possiveis apresentadas no menu
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

