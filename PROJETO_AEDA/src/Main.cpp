#include "Sistema.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Sistema sys();

	Utente* u1 = new Utente("Andre", "Socio");
	Utente* u2 = new Utente("Andre", "Socio");
	Utente* u3 = new Utente("Andre", "Socio");

	cout << u1->getId() << endl << u2->getId() << endl << u3->getId() << endl ;

	return 0;
}
