#include "Includes.h"
#include "Sistema.h"
#include "Utente.h"
#include "Exceções.h"

void registo_utente(Sistema & BS);
void menu_interface(Sistema &BS);
void alugaBike(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;


	if(ER.getUtentes().at(index)->getAvailable() == false)
	{
		cout << "Não é possível alugar duas bicicletas em simultãneo !" << endl;

		system("pause");
		system("cls");
		return;

	}
	else
	{
		cout << "Aluga Biciclea: " << endl << endl;

		//string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano)

		string bikeType;
		int numHours{}, dia{}, mes{}, ano {};
		int value {};
		string option {};

		cout << "Tipos de bicicleta: " << endl;
		cout << "     1 - Urbana" << endl;
		cout << "     2 - Urbana Simples" << endl;
		cout << "     3 - Corrida" << endl;
		cout << "     4 - Infantil" << endl << endl;


		while(1)
		{
			try{
				cout << endl << "Introduza uma opcao (1-4): ";
				cin >> option;
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
				cin.ignore(1000,'\n');
			}
			catch (OpcaoInvalida<string> &op){

				cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
				cin.clear();
				cin.ignore(1000,'\n');
			}
		};

		if(value == 1)
			bikeType = "Urbana";
		else if(value == 2)
			bikeType = "Urbana Simples";
		else if(value == 3)
			bikeType = "Corrida";
		else
			bikeType = "Infantil";


		while(1)
		{
			try{
				cout << endl << "Número de horas: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 24)
					throw OpcaoInvalida<int>(value);

				numHours = value;
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

		while(1)
		{
			try{
				cout << endl << "Ano: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 2017)
					throw OpcaoInvalida<int>(value);

				ano = value;
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

		while(1)
		{
			try{
				cout << endl << "Mes[1-12]: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 12)
					throw OpcaoInvalida<int>(value);

				mes = value;
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

		while(1)
		{
			try{
				cout << endl << "Dia: ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(mes == 2)
				{
					if(value < 1 || value > 28)
						throw OpcaoInvalida<int>(value);

					dia = value;
					break;
				}
				else if((mes == 1) ||(mes == 3) ||(mes == 5) ||(mes == 7) ||(mes == 8) ||(mes == 10) ||(mes == 12))
				{
					if(value < 1 || value > 31)
						throw OpcaoInvalida<int>(value);

					dia = value;
					break;
				}
				else
				{
					if(value < 1 || value > 30)
						throw OpcaoInvalida<int>(value);

					dia = value;
					break;
				}
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


		ER.getUtentes().at(index)->alugaBicicleta(bikeType,numHours,dia,mes,ano);
		ER.getUtentes().at(index)->setAvailable();

		cout << endl << "Bicicleta alugada com sucesso !" << endl << endl;

		system("pause");
		system("cls");
		return;
	}
}
void devolveBike(Sistema &ER,int index) {

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Devolve bicicleta: " << endl << endl;

	Utilizacao ut = ER.getUtentes().at(index)->getUtilizacoes().at(ER.getUtentes().at(index)->getUtilizacoes().size() - 1);

	cout << "Tipo de bicicleta: " << ut.getBikeType() << endl;
	cout << "Número de horas: " << ut.getUseTime() << endl;
	cout << "Data: " << ut.getdia() << "/" << ut.getmes() << "/" << ut.getano()<< endl;

	ER.getUtentes().at(index)->setAvailable();

	cout << endl << "Bicicleta devolvida com sucesso !" << endl << endl;

	system("pause");
	system("cls");
	return;

}
int ExistID(Sistema & sys, int identificacao) {

	for(unsigned int i = 0; i < sys.getUtentes().size() ; i++)
	{
		if(sys.getUtentes().at(i)->getId() == identificacao)
			return i;
	}

	return -1;
}
void displayPagPendentes(Sistema & sys, int identificacao){

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "!" << endl << endl;
}
void updateLocation(Sistema & sys, int identificacao) {

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Bem-Vindo !" << endl << endl;

}
void NearestPP(Sistema & sys, int identificacao) {

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Bem-Vindo !" << endl << endl;
}
void infoER(Sistema & sys, int identificacao) {

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Bem-Vindo !" << endl << endl;
}




void openInterface(){

	int value { };
	string option;

	Sistema ER { };

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
		cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
		cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
		cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
		cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

		cout << "1 - Registar " << endl;
		cout << "2 - Entrar" << endl;
		cout << "3 - Sair" << endl;

		while(1)
		{
			try{
				cout << endl << "Introduza uma opcao (1-3): ";
				cin >> option;
				if(valid_number(option) == false)
					throw OpcaoInvalida<string>(option);

				value = stoi(option);
				if(value < 1 || value > 3)
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

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			registo_utente(ER);
			break;
		case 2:
			system("cls");
			menu_interface(ER);
			break;
		case 3:
			cout << endl;
			break;
		}
	}while(value != 3);
}

void registo_utente(Sistema & ER){

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Regista novo utente:" << endl;

	string nome, tipoUtente;
	int value {};
	string option {};

	while(1)
	{
		try {
			cout << "Nome: " ;
			cin >> nome;
			if(valid_word(nome) == false)
				throw OpcaoInvalida<string>(nome);
			break;
		}
		catch (OpcaoInvalida<string> &op) {
			cout << "Opção inválida(" << op.opcao << ") ! Tente novamente." << endl;
			cin.clear();
			cin.ignore(1000,'\n');
		}
	}
	cout << endl << "Tipo de Utente :"<< endl ;
	cout << "     1 - Regular" << endl;
	cout << "     2 - Sócio" << endl << endl;

	while(1)
	{
		try{
			cout << endl << "Introduza uma opcao (1-3): ";
			cin >> option;
			if(valid_number(option) == false)
				throw OpcaoInvalida<string>(option);

			value = stoi(option);
			if(value < 1 || value > 3)
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

	if(value==1)
		tipoUtente = "Regular";
	else
		tipoUtente = "Socio";

	Utente* u1 = new Utente(nome,tipoUtente);

	ER.addNewUtente(u1);

	cout << endl << "Utente #" << u1->getId() << " registado com sucesso." << endl << endl;

	system("pause");
	system("cls");
	return;
}

void menu_interface(Sistema &ER){

	system("CLS");

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	int attempts { 0 };
	int identificacao { };
	int index {};	//Indice do utente no vector de utentes do sistema
	string info;

	while(attempts <= 3)
	{
		try{
			cout << "Username: ";
			cin >> info;

			if(valid_number(info) == false)
				throw OpcaoInvalida<string>(info);

			identificacao = stoi(info);

			if(ExistID(ER,identificacao) == -1)
				throw OpcaoInvalida<int>(identificacao);

			index = ExistID(ER,identificacao);
			break;
		}
		catch (OpcaoInvalida<int> &op){

			cout << "Username inválido (" << op.opcao << ") ! Tente novamente." << endl;
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

	string option;
	int value {};

	do
	{
		//Informacao inicial apresentadada ao utilizador
		cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
		cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
		cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
		cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
		cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

		cout << "Bem-Vindo !" << endl << endl;

		cout << "1 - Alugar bicicleta" << endl;
		cout << "2 - Devolver bicicleta" << endl;
		cout << "3 - Historial" << endl;
		cout << "4 - Pagamentos pendentes" << endl;
		cout << "5 - Atualiza Localização" << endl;
		cout << "6 - Ponto de partilha mais próximo" << endl;
		cout << "7 - Obter informações sobre ECO RIDES" << endl;
		cout << "8 - Sair" << endl << endl;

		while(1)
		{
			try {

				cout << endl << "Introduza uma opcao (1-8): ";
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

		//Opcões possiveis apresentadas no menu
		switch (value)
		{
		case 1:
			system("cls");
			alugaBike(ER,index);
			break;
		case 2:
			system("cls");
			devolveBike(ER,index);
			break;
		case 3:
			system("cls");
			ER.getUtentes().at(index)->displayHistoric();
			break;
		case 4:
			system("cls");
			displayPagPendentes(ER,index);
			break;
		case 5:
			system("cls");
			updateLocation(ER,index);
			break;
		case 6:
			system("cls");
			NearestPP(ER,index);
			break;
		case 7:
			system("cls");
			infoER(ER,index);
			break;
		case 8:
			cout << endl;
			break;
		}
	}while(value != 8);
	system("pause");
	system("cls");
	return;

}

bool valid_number(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if (!(isdigit(number.at(i))))
			return false;
	}
	return true;
}

bool valid_word(string word)
{
	for (unsigned int i = 0; i < word.size(); i++){
		if (isdigit(word.at(i)))
			return false;
	}
	return true;
}
