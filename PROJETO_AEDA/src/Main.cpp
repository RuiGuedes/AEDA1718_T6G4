#include "Includes.h"
#include "Sistema.h"

using namespace std;

int main()
{
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

	///////////////////////////////////////
	// Zona de inicialização do programa //
	///////////////////////////////////////

	cout << "Utentes = " << sys.getUtentes().size() << endl;
	cout << "Pontos Partilha = " << sys.getPontosPartilha().size() << endl;
	cout << "Capacidade = " << sys.getPontosPartilha().at(0)->getCapacidade() << endl;

	return 0;
}
