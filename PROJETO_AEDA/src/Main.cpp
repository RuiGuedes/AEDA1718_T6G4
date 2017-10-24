#include "Includes.h"
#include "Sistema.h"

using namespace std;

int main()
{
	//Códigos para aceitação de caracteres da língua portugesa
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);


	///////////////////////////////////////
	// Zona de inicialização do programa //
	///////////////////////////////////////

	Sistema sys;

	Utente* u1 = new Utente("Andre", "Socio");
	Utente* u2 = new Utente("Andre", "Socio");
	Utente* u3 = new Utente("Andre", "Socio");

	sys.addNewUtente(u1);
	sys.addNewUtente(u2);
	sys.addNewUtente(u3);

	Localizacao loc("Porto");

	PontoPartilha *p1 = new PontoPartilha(loc, 100);
	PontoPartilha *p2 = new PontoPartilha(loc, 20);
	PontoPartilha *p3 = new PontoPartilha(loc, 17);

	sys.addPontoPartilha(p1);
	sys.addPontoPartilha(p2);
	sys.addPontoPartilha(p3);

	Bicicleta* b1 = new Bicicleta("urbana", "u1");
	p1->adicionaBike(b1);

	u1->alugaBicicleta("urbana", 5,1,12,2017);

	///////////////////////////////////////
	// Zona de inicialização do programa //
	///////////////////////////////////////

	cout << "Tipo de bike = " << p1->getBikeTypes().at(0) << endl;
	cout << "Utentes = " << sys.getUtentes().size() << endl;
	cout << "Pontos Partilha = " << sys.getPontosPartilha().size() << endl;
	cout << "Capacidade = " << sys.getPontosPartilha().at(0)->getCapacidade() << endl << endl;
	cout << "Data = " << u1->getUtilizacoes().at(0).getdia()  << " - " << u1->getUtilizacoes().at(0).getmes()  << " - ";
	cout << u1->getUtilizacoes().at(0).getano() << ".\nBicicleta = " << u1->getUtilizacoes().at(0).getBikeType()  << endl;

	return 0;
}


void openInterface(){
	int option;
	do
	{
		char value[10];

		//Informacao inicial apresentadada ao utilizador
		cout << setfill('#') << setw(59) << endl;
		cout << setw(20) << "    BIKE SYSTEM    " << setw(20);
		cout << setfill('#') << setw(59) << endl;


		cout << endl << "Funcionalidades disponiveis: " << endl << endl;

		cout << "1 - " << endl;
		cout << "2 - Visualizacao de informacao" << endl;
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
			gestao_condutores(SR);
			break;
		case 2:
			visu_info(SR);
			break;
		case 3:
			cout << endl;
			break;
		}
	} while (option != 3);
}
