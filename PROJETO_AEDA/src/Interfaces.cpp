#include "Includes.h"
#include "Sistema.h"
#include "Utente.h"
#include "Exceções.h"

void registo_utente(Sistema & BS);
void menu_interface(Sistema &BS);

void openInterface(int attempts){

	int option;

	Sistema ER;

	if(attempts == 0)
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
	}

	cout << endl << "Introduza uma opcao (1-3): ";        //Opção returnada pelo utilizador

	if(!(cin >>option))
		throw OpcaoInvalida(option);

	if(option < 1 || option > 3)
		throw OpcaoInvalida(option);


	//Opcões possiveis apresentadas no menu
	switch (option)
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
}


void registo_utente(Sistema & BS){

	string nome, tipoUtente;
	int option;

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;

	cout << "Nome: " ;
	cin >> nome;

	cout << endl << "Tipo de Utente :"<< endl ;
	cout << "1 - Regular" << endl;
	cout << "2 - Sócio" << endl;
	cout << "Introduza uma opcao (1-2): ";


	if(!(cin >>option))
		throw OpcaoInvalida(option);

	if(option < 1 || option > 2)
		throw OpcaoInvalida(option);

	if(option==1)
		tipoUtente = "Regular";
	else
		tipoUtente = "Socio";

	Utente* u1 = new Utente(nome,tipoUtente);

	BS.addNewUtente(u1);

	cout << endl << "Número de identificação : " << u1->getId() << endl;

	system("CLS");
	return;
}

void menu_interface(Sistema &BS){

	system("CLS");

	int option;

	//Informacao inicial apresentadada ao utilizador
	cout << "#######  ####### #######      ##########  ##  #####     #######  #######" << endl;
	cout << "###      ##      ##   ##      ##      ##  ##  ##  ###   ###      ##     " << endl;
	cout << "#######  ##      ##   ##      ##   #####  ##  ##    ##  ######   #######" << endl;
	cout << "###      ##      ##   ##      ##   ##     ##  ##  ###   ###           ##" << endl;
	cout << "#######  ####### #######      ##     ###  ##  #####     #######  #######" << endl << endl;






}



bool valid_number(string number)
{
	for (unsigned int i = 0; i < number.size(); i++){
		if (!(isdigit(number.at(i))))
			return false;
	}
	return true;
}
