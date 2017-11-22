#pragma once

#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utilizacao.h"
#include "PontoPartilha.h"
//#include "Sistema.h"


class Utente {
protected:
	static int lastId;		/**< Numero de Identificacao do ultimo utente registado */
	int id;					/**< Numero de Identificacao do utente */
	string nome;			/**< Nome do utente */
	string tipoUtente;		/**< Tipo do utente (Socio ou Regular) */
	Localizacao local;		/**< Localizacao atual do utente */
	Bicicleta* bike;		/**< Bicicleta que o utente esta a usar, caso nao esteja a usar nenhuma, o valor de bike = 0 */
	vector<Utilizacao> historico;	/**< Utilizacoes liquidadas do utente */
	bool disponivel = true;			/**< Se o utente esta a usar uma bicicleta disponivel = false, caso contrario disponivel = true */
public:
	Utente();	/**< Necessário para o overload do operador de extração na classe utente*/
	explicit Utente(string nome, string tipoUtente,Localizacao spot);
	void alugaBicicleta(Sistema &ER, string bikeType, Utilizacao ut, int idPP);
	int removeBicicleta(Sistema &ER, vector<int> index_distancias);
	void pagaMensalidade(unsigned int ano, unsigned int mes);
	friend ostream & operator <<(ostream & o, const Utente & u);
	friend istream & operator >>(istream & i, Utente & u);

	//Métodos Get
	static int getLastId();
	int getId() const;
	string getNome() const;
	string getTipoUtente() const;
	Localizacao getLocalizacao() const;
	Bicicleta* getBike() const;
	vector<Utilizacao> getUtilizacoes();
	bool getAvailable() const;
	vector<Utilizacao> getHistorico();

	//Métodos Set
	static void setLastId();
	void setIDBackward();
	void setID(int identificacao);
	void setUtenteLocation(Localizacao spot);
	void setTipoUtente(string tipo);	/**<Necessita de pagar dívidas anteriores antes de poder mudar de tipo (so se for socio)*/
	void setAvailable();
	void setBike(Bicicleta* bike);
	void setHistoric(Utilizacao ut);
	void setUtilizacoes(Utilizacao ut);
};

class Socio : protected Utente {
	vector<Utilizacao> utilizacoes;	/**<Apenas associadas aos sócios, vetor de utilizacoes por pagar */
};



/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Utente nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
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

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Utente,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Utente & u)
{
	char b1, b2, b3, b4, b5;
	unsigned int utiliz, hist;
	Utilizacao ut;

	getline(i,u.nome,',');
	getline(i,u.tipoUtente,',');
	i >> u.local >> b1 >> utiliz >> b2;

	for(unsigned int k=0 ; k < utiliz ; k++){
		i >> ut >> b3;
		u.utilizacoes.push_back(ut);
	}

	i >> hist >> b4;

	for(unsigned int k=0 ; k < hist ; k++){
		i >> ut >> b5;
		u.historico.push_back(ut);
	}

	return i;
}
