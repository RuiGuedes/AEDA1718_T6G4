#include <string>
#include <vector>
#include "Localizacao.h"
#include "Utilizacao.h"
#include "Bicicleta.h"

using namespace std;

class Utente {
	static int id;
	string nome;
	string tipoUtente;
	Localizacao local;		//Localizacao é uma classe
	Bicicleta* bike;		//Bicicleta é uma classe
	vector<Utilizacao> utilizacoes; //dia, mes, ano, horas de uso, tipo de bike //Queremos para ver pagamentos em falta
	vector<Utilizacao> historico;
	//...
public:
	void alugaBicicleta();
	void devolveBicicleta();
	string getTipoUtente() const;
	Utente(string nome, string tipoUtente);
	void setUtenteLocation();
	Localizacao getLocalizacao() const;
	void setTipoUtente();  //Necessita de pagar dividas anteriores antes de poder mudar de tipo
	void updateHistoric();

};
