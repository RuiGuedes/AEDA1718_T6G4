#include <string>

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
	Utente();
	Localizacao getLocalizacao() const;
	void setTipoUtente();   //Faz pagamento;
};
