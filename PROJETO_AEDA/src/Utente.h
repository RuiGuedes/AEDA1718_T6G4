#pragma once

#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utilizacao.h"

//struct data {int dia; int mes; int ano;};

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

	void displayHistoric();

	/* MÉTODOS GET */
	static int getLastId() {return lastId;}
	int getId() const;
	string getUtenteNome() const;
	string getTipoUtente() const;
	Localizacao getLocalizacao() const;
	Bicicleta* getBike() const;
	vector<Utilizacao> getUtilizacoes();
	bool getAvailable() const;
	vector<Utilizacao> getHistorico();

	/* MÉTODOS SET */
	void setUtenteLocation(Localizacao spot);
	void setTipoUtente(int tipo);  //Necessita de pagar dividas anteriores antes de poder mudar de tipo
	void setAvailable();
	void setBike(Bicicleta* bike);
	void setHistoric(Utilizacao ut);
	void setUtilizacoes(Utilizacao ut);
	void alugaBicicleta(string bikeType, unsigned int numHours, Data d, vector<int> distancias);
	void devolveBicicleta();
	void updateHistoric();

	friend ostream & operator <<(ostream & o, const Utente & u);
	friend istream & operator >>(istream & i, Utente & u);
};

inline ostream& operator <<(ostream & o, const Utente & u)
{
	o << u.nome << ',' <<  u.tipoUtente << ',' << u.local << ',' ;

	o << u.utilizacoes.size() << ',' ;
	for (unsigned int k=0 ; k< u.utilizacoes.size() ; k++){
		o << u.utilizacoes.at(k) << ';' ;
	}

	o << u.historico.size() << ',' ;
	for (unsigned int k=0 ; k< u.historico.size() ; k++){
		o << u.historico.at(k) << ';' ;
	}

	return o;
}

inline istream& operator >>(istream & i, Utente & u)
{
	char b1, b2, b3, b4, b5, b6, b7;
	unsigned int utiliz, hist;
	Utilizacao ut;

	i >>  u.nome >> b1 >> u.tipoUtente >> b2 >> u.local >> b3 >> utiliz >> b4;

	for(unsigned int k=0 ; k < utiliz ; k++){
		i >> ut >> b5;
		u.utilizacoes.push_back(ut);
	}

	i >> hist >> b6;

	for(unsigned int k=0 ; k < hist ; k++){
		i >> ut >> b7;
		u.historico.push_back(ut);
	}

	return i;
}













