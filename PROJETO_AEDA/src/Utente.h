#pragma once

#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utilizacao.h"

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
	void alugaBicicleta(string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano);
	void devolveBicicleta();
	void updateHistoric();
	void displayHistoric() const;

	/* MÉTODOS GET */
	static int getLastId() {return lastId;}
	int getId() const;
	string getUtenteNome() const;
	string getTipoUtente() const;
	Localizacao getLocalizacao() const;
	Bicicleta* getBike() const;
	vector<Utilizacao> getUtilizacoes() const;

	/* MÉTODOS SET */
	void setUtenteLocation(Localizacao spot);
	void setTipoUtente(int tipo);  //Necessita de pagar dividas anteriores antes de poder mudar de tipo


};
