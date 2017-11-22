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
	Localizacao local;		/**< Localizacao atual do utente */
	Bicicleta* bike;		/**< Bicicleta que o utente esta a usar, caso nao esteja a usar nenhuma, o valor de bike = 0 */
	vector<Utilizacao> historico;	/**< Utilizacoes liquidadas do utente */
	bool disponivel = true;			/**< Se o utente esta a usar uma bicicleta disponivel = false, caso contrario disponivel = true */
public:
	Utente();	/**< Necess�rio para o overload do operador de extra��o na classe utente*/
	explicit Utente(string nome, Localizacao spot);
//	void alugaBicicleta(string bikeType, Utilizacao ut, int idPP);
//	int removeBicicleta(vector<int> index_distancias);

	//M�todos Get
	static int getLastId();
	int getId() const;
	string getNome() const;
	virtual string getTipoUtente() const;
	Localizacao getLocalizacao() const;
	Bicicleta* getBike() const;
	bool getAvailable() const;
	vector<Utilizacao> getHistorico();

	//M�todos Set
	static void setLastId();
	void setIDBackward();
	void setID(int identificacao);
	void setUtenteLocation(Localizacao spot);
	void setTipoUtente(string tipo);	/**<Necessita de pagar d�vidas anteriores antes de poder mudar de tipo (so se for socio)*/
	void setAvailable();
	void setBike(Bicicleta* bike);
	void setHistoric(Utilizacao ut);
};




class Socio : protected Utente {
	vector<Utilizacao> utilizacoes;	/**<Vetor de utilizacoes por pagar */
public:
	Socio();
	Socio(string nome,Localizacao spot);
	void pagaMensalidade(unsigned int ano, unsigned int mes);

	friend ostream & operator <<(ostream & o, const Socio & u);
	friend istream & operator >>(istream & i, Socio & u);

	string getTipoUtente() const;
	vector<Utilizacao> getUtilizacoes();

	void setUtilizacoes(Utilizacao ut);
};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Socio nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream& operator <<(ostream & o, const Socio & u)
{
	o << 'S' << ',' <<  u.nome << ',' << u.local << ',' ;

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
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Socio,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Socio & u)
{
	char b1, b2, b3, b4, b5;
	unsigned int utiliz, hist;
	Utilizacao ut;

	getline(i,u.nome,',');
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




class Regular : protected Utente {
public:
	Regular();
	Regular(string nome,Localizacao spot);
	friend ostream & operator <<(ostream & o, const Regular & u);
	friend istream & operator >>(istream & i, Regular & u);

	int pagamento();
	string getTipoUtente() const;
};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Regular nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream& operator <<(ostream & o, const Regular & u)
{
	o << 'R' << ',' <<  u.nome << ',' << u.local << ',' ;

	o << u.historico.size() << ',' ;
	for (unsigned int k=0 ; k< u.historico.size() ; k++){
		o << u.historico.at(k) << ';' ;
	}

	return o;
}

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Regular,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Regular & u)
{
	char b1, b2, b3, b4;
	unsigned int utiliz, hist;
	Utilizacao ut;

	getline(i,u.nome,',');
	i >> u.local >> b1 >> utiliz >> b2;

	i >> hist >> b3;

	for(unsigned int k=0 ; k < hist ; k++){
		i >> ut >> b4;
		u.historico.push_back(ut);
	}

	return i;
}


