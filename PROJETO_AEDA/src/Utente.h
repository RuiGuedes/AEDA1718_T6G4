#pragma once

#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utilizacao.h"

struct data {
	int dia;
	int mes;
	int ano;
};

class Utente {
	static int lastId;
	int id;
	string nome;
	string tipoUtente;
	Localizacao local;		//Localizacao é uma classe
	Bicicleta* bike;		//Bicicleta é uma classe
	vector<Utilizacao> utilizacoes; //dia, mes, ano, horas de uso, tipo de bike //Queremos para ver pagamentos em falta
	vector<Utilizacao> historico;
	bool disponivel = true;
public:
	explicit Utente(string nome, string tipoUtente,Localizacao spot);
	void alugaBicicleta(string bikeType, unsigned int numHours, struct data, vector<int> distancias);
	void devolveBicicleta();
	void updateHistoric();
	void displayHistoric() const {

	}

	/* MÉTODOS GET */
	static int getLastId() {return lastId;}
	int getId() const;
	string getUtenteNome() const;
	string getTipoUtente() const;
	Localizacao getLocalizacao() const;
	Bicicleta* getBike() const;
	vector<Utilizacao> getUtilizacoes();
	bool getAvailable() const;

	/* MÉTODOS SET */
	void setUtenteLocation(Localizacao spot);
	void setTipoUtente(int tipo);  //Necessita de pagar dividas anteriores antes de poder mudar de tipo
	void setAvailable();
	void setBike(Bicicleta* bike);
	void setHistoric(Utilizacao ut);
	void setUtilizacoes(Utilizacao ut);

};
