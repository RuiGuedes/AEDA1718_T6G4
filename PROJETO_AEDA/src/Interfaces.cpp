#include "Includes.h"
#include "Sistema.h"
#include "Utente.h"
#include "Exceções.h"

void registo_utente(Sistema & BS);
void menu_interface(Sistema &BS);
void alugaBike(Sistema &ER,int index) {

}
void devolveBike(Sistema &ER,int index) {

}
int ExistID(Sistema & sys, int identificacao) {

	for(unsigned int i = 0; i < sys.getUtentes().size() ; i++)
	{
		if(sys.getUtentes().at(i)->getId() == identificacao)
			return i;
	}

	return -1;
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

	string option;
	int value {};

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
		break;
	case 5:
		system("cls");
		break;
	case 6:
		system("cls");
		break;
	case 7:
		system("cls");
		break;
	case 8:
		cout << endl;
		break;
	}

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
