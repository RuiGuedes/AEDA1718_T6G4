#include "Includes.h"
#include "Sistema.h"
#include "Exceções.h"
using namespace std;

void openInterface(Sistema & ER);

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

	Localizacao loc1("Paranhos", 41.175384, -8.607519);
	Localizacao loc2("Ramalde", 41.172147, -8.648064);
	Localizacao loc3("Campanhã", 41.155517, -8.571384);
	Localizacao loc4("Cedofeita", 41.155603, -8.614435);
	Localizacao loc5("Santo Ildefonso", 41.152241, -8.608235);
	Localizacao loc6("Bonfim", 41.151044, -8.594061);
	Localizacao loc7("S. Mamede de Infesta", 41.191473, -8.613362);
	Localizacao loc8("Pedrouços", 41.188799, -8.587511);
	Localizacao loc9("Rio Tinto", 41.181107, -8.565446);

	PontoPartilha *p1 = new PontoPartilha(loc1, 100);
	PontoPartilha *p2 = new PontoPartilha(loc2, 20);
	PontoPartilha *p3 = new PontoPartilha(loc3, 17);
	PontoPartilha *p4 = new PontoPartilha(loc4, 44);
	PontoPartilha *p5 = new PontoPartilha(loc5, 32);
	PontoPartilha *p6 = new PontoPartilha(loc6, 70);
	PontoPartilha *p7 = new PontoPartilha(loc7, 48);
	PontoPartilha *p8 = new PontoPartilha(loc8, 29);
	PontoPartilha *p9 = new PontoPartilha(loc9, 85);

	sys.addPontoPartilha(p1);
	sys.addPontoPartilha(p2);
	sys.addPontoPartilha(p3);
	sys.addPontoPartilha(p4);
	sys.addPontoPartilha(p5);
	sys.addPontoPartilha(p6);
	sys.addPontoPartilha(p7);
	sys.addPontoPartilha(p8);
	sys.addPontoPartilha(p9);

	openInterface(sys);

//
//	Bicicleta* b1 = new Bicicleta("urbana", "u1");
//	p1->adicionaBike(b1);
//
//	u1->alugaBicicleta("urbana", 5,1,12,2017);
//
//	///////////////////////////////////////
//	// Zona de inicialização do programa //
//	///////////////////////////////////////
//
//	cout << "Tipo de bike = " << p1->getBikeTypes().at(0) << endl;
//	cout << "Utentes = " << sys.getUtentes().size() << endl;
//	cout << "Pontos Partilha = " << sys.getPontosPartilha().size() << endl;
//	cout << "Capacidade = " << sys.getPontosPartilha().at(0)->getCapacidade() << endl << endl;
//	cout << "Data = " << u1->getUtilizacoes().at(0).getdia()  << " - " << u1->getUtilizacoes().at(0).getmes()  << " - ";
//	cout << u1->getUtilizacoes().at(0).getano() << ".\nBicicleta = " << u1->getUtilizacoes().at(0).getBikeType()  << endl;

	return 0;
}



