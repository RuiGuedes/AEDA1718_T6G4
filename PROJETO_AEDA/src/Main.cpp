#include "Sistema.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Sistema sys();

	Utente* u1 = new Utente("Andre", "Socio");

	cout << u1->getTipoUtente() << endl;

	return 0;
}
