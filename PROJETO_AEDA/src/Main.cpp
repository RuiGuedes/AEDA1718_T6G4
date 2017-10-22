#include "Includes.h"
#include "Sistema.h"
#include "Utente.h"

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

	cout << sys.getUtentes().size() << endl;

	return 0;
}
