#include <string>
#include <vector>
#include "Localizacao.h"
#include "Utilizacao.h"
#include "Bicicleta.h"

using namespace std;

class Utente {
	static int lastId;
	int id;
	string nome;
	string tipoUtente;
	Localizacao local;		//Localizacao é uma classe
	Bicicleta* bike;		//Bicicleta é uma classe
	vector<Utilizacao> utilizacoes; //dia, mes, ano, horas de uso, tipo de bike //Queremos para ver pagamentos em falta
	vector<Utilizacao> historico;
	//...
public:
	explicit Utente(string nome, string tipoUtente);
	void alugaBicicleta();
	void devolveBicicleta();
	void updateHistoric();

	/* MÉTODOS GET */
	static int getLastId() {return lastId;}
	int getId() const;
	string getUtenteNome() const;
	string getTipoUtente() const;
	Localizacao getLocalizacao() const;

	/* MÉTODOS SET */
	void setUtenteLocation();
	void setTipoUtente();  //Necessita de pagar dividas anteriores antes de poder mudar de tipo


};
