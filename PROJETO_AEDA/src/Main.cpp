#include "Includes.h"
#include "Sistema.h"
#include "Exceções.h"

using namespace std;

void openInterface(Sistema & ER);
void checkinSys(Sistema & ER);
void checkoutSys(Sistema & ER);

int main()
{
	//Códigos para aceitação de caracteres da língua portuguesa
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	///////////////////////////////////////
	// Zona de inicialização do programa //
	///////////////////////////////////////

	//Informacao inicial apresentadada ao utilizador
	cout << "######  ####### #######      ##########  ##  #####    ######  #######" << endl;
	cout << "##      ##      ##   ##      ##      ##  ##  ##  ##   ##      ##     " << endl;
	cout << "######  ##      ##   ##      ##  ######  ##  ##   ##  #####   #######" << endl;
	cout << "##      ##      ##   ##      ##    ##    ##  ##  ##   ##           ##" << endl;
	cout << "######  ####### #######      ##     ###  ##  #####    ######  #######" << endl << endl;

	Sistema sys;
	cout << "APPLICATION LOADING";
	cout << " .";checkinSys(sys) ; cout << "\b.."; Sleep(1000); cout << "\b\b...";Sleep(500);
	system("cls");
	openInterface(sys);

	checkoutSys(sys);

	return 0;
}

void checkinSys(Sistema & ER){
	ifstream f_utentes;

	try{
		f_utentes.open("utentes.txt");
		if (!f_utentes.is_open())
			throw AberturaFalhada<string>("utentes.txt");
	}
	catch (AberturaFalhada<string> &a){
		cout << "Falha ao abrir o ficheiro " << a.getFicheiro() << "." << endl;
		cout << "Tente mais tarde.\n";
		return;
	}

	while(!f_utentes.eof()){
		Utente u1;
		f_utentes >> u1;
		if (u1.getUtenteNome()!=""){
			Utente * u = new Utente(u1);
			ER.addNewUtente(u);
		}
		else{
			Utente::setLastId();
		}
		f_utentes.ignore(100,'\n');
	}

	f_utentes.close();

	ifstream f_pontos_partilha;

	ifstream f_bicicletas;

	try{
		f_pontos_partilha.open("pontosPartilha.txt");
		if (!f_pontos_partilha.is_open())
			throw AberturaFalhada<string>("pontos_partilha.txt");

		f_bicicletas.open("bicicletas.txt");
		if (!f_bicicletas.is_open())
			throw AberturaFalhada<string>("bicicletas.txt");
	}
	catch (AberturaFalhada<string> &a){
		cout << "Falha ao abrir o ficheiro " << a.getFicheiro() << "." << endl;
		cout << "Tente mais tarde.\n";
		return;
	}

	int lastId;
	char b;
	f_bicicletas >> lastId >> b;
	PontoPartilha::setBikeLastId("Urbana",lastId) ;
	f_bicicletas >> lastId >> b;
	PontoPartilha::setBikeLastId("Urbana Simples",lastId) ;
	f_bicicletas >> lastId >> b;
	PontoPartilha::setBikeLastId("Corrida",lastId) ;
	f_bicicletas >> lastId;
	PontoPartilha::setBikeLastId("Infantil",lastId) ;
	f_bicicletas.ignore();


	while(!f_pontos_partilha.eof()){
		PontoPartilha p1;
		f_pontos_partilha >> p1;

		if(p1.getNome()==""){
			break;
		}
		f_pontos_partilha.ignore();

		vector<int> numType = p1.getNumberOfBikes();
		p1.limpaVectorBike();

		for (unsigned int j=0 ; j<numType.size() ; j++){
			for (int k=0 ; k < numType.at(j) ; k++){
				Bicicleta* b = new Bicicleta();

				f_bicicletas >> (*b);
				if(b->getBikeName()==""){
					continue;
				}
				f_bicicletas.ignore();

				p1.adicionaBike(b);
			}
		}

		PontoPartilha * p = new PontoPartilha(p1);
		ER.addPontoPartilha(p);
	}

	f_pontos_partilha.close();

	f_bicicletas.close();

	return;
};

void checkoutSys(Sistema & ER){

	ofstream f_utentes;

	try{
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
		f_utentes << *(ER.getUtentes().at(it)) << endl;
	}

	f_utentes.close();

	ofstream f_pontos_partilha;

	ofstream f_bicicletas;

	try{
		f_pontos_partilha.open("pontosPartilha.txt");
		if (!f_pontos_partilha.is_open())
			throw AberturaFalhada<string>("pontos_partilha.txt");

		f_bicicletas.open("bicicletas.txt");
		if (!f_bicicletas.is_open())
			throw AberturaFalhada<string>("bicicletas.txt");
	}
	catch (AberturaFalhada<string> &a){
		cout << "Falha ao abrir o ficheiro " << a.getFicheiro() << "." << endl;
		cout << "Tente mais tarde./n";
		return;
	}

	f_bicicletas << PontoPartilha::getBikeLastId("Urbana") << '/';
	f_bicicletas << PontoPartilha::getBikeLastId("Urbana Simples") << '/';
	f_bicicletas << PontoPartilha::getBikeLastId("Corrida") << '/';
	f_bicicletas << PontoPartilha::getBikeLastId("Infantil") << endl;

	for(unsigned int it=0 ; it<ER.getPontosPartilha().size() ; it++){
		f_pontos_partilha << (*ER.getPontosPartilha().at(it)) << endl;

		PontoPartilha p(*ER.getPontosPartilha().at(it));

		for(unsigned int j=0 ; j<p.getBikes().size() ; j++)
			for(unsigned int k=0 ; k <p.getBikes().at(j).size() ; k++){
				f_bicicletas << (*p.getBikes().at(j).at(k)) << endl;
			}
	}

	f_pontos_partilha.close();

	f_bicicletas.close();

	return;
}


