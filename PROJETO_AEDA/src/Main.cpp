#include "Includes.h"
#include "Sistema.h"
#include "Exceções.h"
using namespace std;

void openInterface(Sistema & ER);
void checkoutSys(Sistema & ER);

int main()
{
	//Códigos para aceitação de caracteres da língua portugesa
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	///////////////////////////////////////
	// Zona de inicialização do programa //
	///////////////////////////////////////

	Sistema sys;

	Localizacao loc1("Paranhos", 41.175384, -8.607519);
	Localizacao loc2("Ramalde", 41.172147, -8.648064);
	Localizacao loc3("Campanhã", 41.155517, -8.571384);
	Localizacao loc4("Cedofeita", 41.155603, -8.614435);
	Localizacao loc5("Santo Ildefonso", 41.152241, -8.608235);
	Localizacao loc6("Bonfim", 41.151044, -8.594061);
	Localizacao loc7("S. Mamede de Infesta", 41.191473, -8.613362);
	Localizacao loc8("Pedrouços", 41.188799, -8.587511);
	Localizacao loc9("Rio Tinto", 41.181107, -8.565446);

	Utente* u1 = new Utente("Andre", "Socio",loc1);
	Utente* u2 = new Utente("Jose", "Regular",loc2);
	Utente* u3 = new Utente("Ana", "Socio",loc3);

	sys.addNewUtente(u1);
	sys.addNewUtente(u2);
	sys.addNewUtente(u3);

	PontoPartilha *p1 = new PontoPartilha(loc1, 100,"A");
	PontoPartilha *p2 = new PontoPartilha(loc2, 20, "B");
	PontoPartilha *p3 = new PontoPartilha(loc3, 17, "C");
	PontoPartilha *p4 = new PontoPartilha(loc4, 44,"D");
	PontoPartilha *p5 = new PontoPartilha(loc5, 32,"E");
	PontoPartilha *p6 = new PontoPartilha(loc6, 70,"F");
	PontoPartilha *p7 = new PontoPartilha(loc7, 48,"G");
	PontoPartilha *p8 = new PontoPartilha(loc8, 29,"H");
	PontoPartilha *p9 = new PontoPartilha(loc9, 85,"I");

	sys.addPontoPartilha(p1);
	sys.addPontoPartilha(p2);
	sys.addPontoPartilha(p3);
	sys.addPontoPartilha(p4);
	sys.addPontoPartilha(p5);
	sys.addPontoPartilha(p6);
	sys.addPontoPartilha(p7);
	sys.addPontoPartilha(p8);
	sys.addPontoPartilha(p9);



	Bicicleta *bike1 = new Bicicleta("Urbana Simples", "us1");
	Bicicleta *bike2 = new Bicicleta("Urbana Simples", "us2");
	Bicicleta *bike3 = new Bicicleta("Urbana Simples", "us3");
	Bicicleta *bike4 = new Bicicleta("Urbana", "u1");
	Bicicleta *bike5 = new Bicicleta("Urbana", "u2");
	Bicicleta *bike6 = new Bicicleta("Urbana", "u3");
	Bicicleta *bike7 = new Bicicleta("Corrida", "c1");
	Bicicleta *bike8 = new Bicicleta("Corrida", "c2");
	Bicicleta *bike9 = new Bicicleta("Urbana Simples", "us4");
	Bicicleta *bike10 = new Bicicleta("Infantil", "i1");

	sys.getPontosPartilha().at(0)->adicionaBike(bike1);
	sys.getPontosPartilha().at(0)->adicionaBike(bike2);
	sys.getPontosPartilha().at(0)->adicionaBike(bike3);
	sys.getPontosPartilha().at(0)->adicionaBike(bike4);
	sys.getPontosPartilha().at(0)->adicionaBike(bike5);
	sys.getPontosPartilha().at(0)->adicionaBike(bike6);
	sys.getPontosPartilha().at(0)->adicionaBike(bike7);
	sys.getPontosPartilha().at(0)->adicionaBike(bike8);
	sys.getPontosPartilha().at(0)->adicionaBike(bike9);
	sys.getPontosPartilha().at(0)->adicionaBike(bike10);

	openInterface(sys);

	checkoutSys(sys);

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



void checkinSys(Sistema & ER){
	ifstream f_pontos_partilha;

	ifstream f_utentes;

	ifstream f_bicicletas;

	try{
		f_pontos_partilha.open("pontosPartilha.txt");
		if (!f_pontos_partilha.is_open())
			throw AberturaFalhada<string>("pontos_partilha.txt");

		f_bicicletas.open("bicicletas.txt");
		if (!f_bicicletas.is_open())
			throw AberturaFalhada<string>("bicicletas.txt");

		f_utentes.open("utentes.txt");
		if (!f_utentes.is_open())
			throw AberturaFalhada<string>("utentes.txt");
	}
	catch (AberturaFalhada<string> &a){
		cout << "Falha ao abrir o ficheiro " << a.getFicheiro() << "." << endl;
		cout << "Tente mais tarde./n";
		return;
	}









}

void checkoutSys(Sistema & ER){

	///////////////////////////////////////////////////////////////
	//antes de fazer check out , os utentes tem que devolver bike//
	///////////////////////////////////////////////////////////////

	ofstream f_pontos_partilha;

	ofstream f_utentes;

	ofstream f_bicicletas;

	try{
		f_pontos_partilha.open("pontosPartilha.txt");
		if (!f_pontos_partilha.is_open())
			throw AberturaFalhada<string>("pontos_partilha.txt");

		f_bicicletas.open("bicicletas.txt");
		if (!f_bicicletas.is_open())
			throw AberturaFalhada<string>("bicicletas.txt");

		f_utentes.open("utentes.txt");
		if (!f_utentes.is_open())
			throw AberturaFalhada<string>("utentes.txt");
	}
	catch (AberturaFalhada<string> &a){
		cout << "Falha ao abrir o ficheiro " << a.getFicheiro() << "." << endl;
		cout << "Tente mais tarde./n";
		return;
	}


	for(unsigned int it=0 ; it<ER.getUtentes().size() ; it++){
		f_utentes << *ER.getUtentes().at(it) << endl;
	}

	for(unsigned int it=0 ; it<ER.getPontosPartilha().size() ; it++){
		f_pontos_partilha << *ER.getPontosPartilha().at(it) << endl;

		PontoPartilha p(*ER.getPontosPartilha().at(it));

		for(unsigned int j=0 ; j<p.getBikes().size() ; j++)
			for(unsigned int k=0 ; k <p.getBikes().at(j).size() ; k++){
				f_bicicletas << *p.getBikes().at(j).at(k) << endl;
			}
	}

	f_pontos_partilha.close();

	f_utentes.close();

	f_bicicletas.close();

	return;
}
































