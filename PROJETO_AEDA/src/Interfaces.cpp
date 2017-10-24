#include "Includes.h"


void openInterface(){
	int option;

	char value[10];

	Sistema BS;

	//Informacao inicial apresentadada ao utilizador
	cout << setfill('#') << setw(60) << endl;
	cout << setw(20) << "    BIKE  SYSTEM    " << setw(20);
	cout << setfill('#') << setw(60) << endl << endl;


	cout << "1 - Registar " << endl;
	cout << "2 - Entrar" << endl;
	cout << "3 - Sair" << endl;
	cout << endl << "Introduza uma opcao (1-3): ";        //Opção returnada pelo utilizador

	cin.ignore(1000, '\n');
	cin.get(value, 10);

	//Executa este ciclo até receber um valor válido
	while ((valid_number(value) == false) || (atoi(value) < 1) || (atoi(value) > 3))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcao invalida ! Tente novamente. " << endl;
		cout << "Introduza uma opcao (1-3): ";
		cin.get(value, 10);
	}

	option = atoi(value);

	//Opcões possiveis apresentadas no menu
	switch (option)
	{
	case 1:
		system("CLS");
		registo_utente(BS);
		menu_interface(BS);
		break;
	case 2:
		system("CLS");
		menu_interface(BS);
		break;
	case 3:
		cout << endl;
		break;
	}

}

void registo_utente(Sistema & BS){

	string nome, tipoUtente;
	int option;

	char value[10];

	//Informacao inicial apresentadada ao utilizador
	cout << setfill('#') << setw(60) << endl;
	cout << setw(20) << "    BIKE  SYSTEM    " << setw(20);
	cout << setfill('#') << setw(60) << endl << endl;

	cout << Nome: ;
	cin >> nome;

	cout << endl << "Tipo de Utente :"<< endl ;
	cout << "1 - Regular" << endl;
	cout << "2 - Sócio" << endl;
	cout << "Introduza uma opcao (1-2): ";

	cin.ignore(1000, '\n');
	cin.get(value, 10);

	//Executa este ciclo até receber um valor válido
	while ((valid_number(value) == false) || (atoi(value) < 1) || (atoi(value) > 3))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcao invalida ! Tente novamente. " << endl;
		cout << "Introduza uma opcao (1-2): ";
		cin.get(value, 10);
	}

	option = atoi(value);

	if(option==1)
		tipoUtente = "Regular";
	else
		tipoUtente = "Socio";

	Utente* u1 = new Utente(nome,tipoUtente);

	BS.addNewUtente(u1);

	cout << endl << "Número de identificação : " << u1.getId() << endl;

	system("CLS");
	return;
}

void menu_interface(Sistema &BS){

	int option;

	char value[10];

	//Informacao inicial apresentadada ao utilizador
	cout << setfill('#') << setw(60) << endl;
	cout << setw(20) << "    BIKE  SYSTEM    " << setw(20);
	cout << setfill('#') << setw(60) << endl << endl;






}



bool valid_number(string number)
{
	for (int i = 0; i < number.size(); i++)
	{
		if (!(isdigit(number.at(i))))
		{
			return false;
		}
	}
	return true;
}
