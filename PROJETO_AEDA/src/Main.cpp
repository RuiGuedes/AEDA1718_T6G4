#include "Includes.h"
#include "Sistema.h"

using namespace std;

void openInterface(Sistema & ER);
void checkinSys(Sistema & ER);
void checkoutSys(Sistema & ER);

/**
 * Inicializacao do programa, checkin do sistema , apresentacao de interface ,
 * execucao das funcoes selecionadas e no final checkout do sistema.
 */
int main()
{
	//Códigos para aceitação de caracteres da língua portuguesa
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	///////////////////////////////////////
	// Zona de inicialização do programa //
	///////////////////////////////////////

	mensagemInicial();

	Sistema sys;

	cout << "APPLICATION LOADING";
	cout << " .";checkinSys(sys) ; cout << "\b.."; Sleep(1000); cout << "\b\b...";Sleep(500);
	system("cls");

	openInterface(sys);

	checkoutSys(sys);

	return 0;
}

/**
 * Efetua a leitura dos 3 ficheiros se texto que contem a informacao sobre o sistema
 * e coloca-a corretamente no sistema.
 * Para efetuar a extracao da informacao, a funcao recorre ao operador de extracao >>
 * que foi redefenido para todas as classes usadas no sistema.
 * @param ER sistema que se pretende completar
 */
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
		char tipoUtente;
		tipoUtente = f_utentes.get();
		f_utentes.get();

		if(tipoUtente == 'R'){
			Regular u1;
			f_utentes >> u1;
			if (u1.getNome() != ""){
				Utente * u = new Regular(u1);
				ER.addNewUtente(u);
			}
			else{
				Utente::setLastId();
				break;
			}
		}
		else {
			Socio u1;
			f_utentes >> u1;
			if (u1.getNome()!=""){
				Utente * u = new Socio(u1);
				ER.addNewUtente(u);
			}
			else{
				Utente::setLastId();
				break;
			}
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
				string b;
				Bicicleta* bike;
				getline(f_bicicletas, b,'\n');

				if(b.at(0) == 'u')
				{
					if(b.at(1) == 's')
					{
						bike = new UrbanaSimples(b);
					}
					else
						bike = new Urbana(b);
				}
				else if(b.at(0) == 'c')
					bike = new Corrida(b);
				else
					bike = new Infantil(b);

				if(bike->getBikeName()==""){
					continue;
				}

				p1.adicionaBike(bike);
			}
		}

		PontoPartilha * p = new PontoPartilha(p1);
		ER.addPontoPartilha(p);
	}

	f_pontos_partilha.close();

	f_bicicletas.close();

	return;
};

/**
 * Insere nos ficheiros de texto a informacao contida no sistema formatadamente.
 * Para efetuar a insercao da informacao, a funcao recorre ao operador de insercao <<
 * que foi redefenido para todas as classes usadas no sistema.
 * @param ER sistema que se pretende guardar
 */
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
		if(ER.getUtentes().at(it)->getTipoUtente() == "Socio" ){
			Socio s = *static_cast<Socio *> (ER.getUtentes().at(it));
			f_utentes << s << endl;
		}
		else {
			Regular r = *static_cast<Regular *> (ER.getUtentes().at(it));
			f_utentes << r << endl;
		}
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

	for(unsigned int it=0 ; it<ER.getPontosPartilha().size() ; it++){
		f_pontos_partilha << (*ER.getPontosPartilha().at(it)) << endl;

		PontoPartilha p(*ER.getPontosPartilha().at(it));

		for(unsigned int j=0 ; j<p.getBikes().size() ; j++)
			for(unsigned int k=0 ; k <p.getBikes().at(j).size() ; k++){
				f_bicicletas << (*p.getBikes().at(j).at(k)).getBikeName() << endl;
			}
	}

	f_pontos_partilha.close();

	f_bicicletas.close();

	return;
}
