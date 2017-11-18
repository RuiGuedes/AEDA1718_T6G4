#pragma once

#include "Includes.h"
#include "Localizacao.h"
#include "Bicicleta.h"
#include "Utilizacao.h"

class Utente;
class PontoPartilha;

class Sistema {
	vector<PontoPartilha* > pontosPartilha;
	vector<Utente* > utentes;
public:
	Sistema() {}
	void addPontoPartilha(PontoPartilha* spot);		/**< Criação de uma nova loja */
	void addNewUtente(Utente* utente);		/**< Adiciona um novo utente */
	void removePonto(int indexPP);
	void removeUtente(int indexUT);

	//Métodos Get
	vector<Utente* > getUtentes();
	vector<PontoPartilha* > getPontosPartilha();
	virtual string getNome() const {return "";};
};


class Utente : public Sistema{
	static int lastId;		/**< Numero de Identificacao do ultimo utente registado */
	int id;					/**< Numero de Identificacao do utente */
	string nome;			/**< Nome do utente */
	string tipoUtente;		/**< Tipo do utente (Socio ou Regular) */
	Localizacao local;		/**< Localizacao atual do utente */
	Bicicleta* bike;		/**< Bicicleta que o utente esta a usar, caso nao esteja a usar nenhuma, o valor de bike = 0 */
	vector<Utilizacao> utilizacoes;	/**<Apenas associadas aos sócios, vetor de utilizacoes por pagar */
	vector<Utilizacao> historico;	/**< Utilizacoes liquidadas do utente */
	bool disponivel = true;			/**< Se o utente esta a usar uma bicicleta disponivel = false, caso contrario disponivel = true */
public:
	Utente();	/**< Necessário para o overload do operador de extração na classe utente*/
	explicit Utente(string nome, string tipoUtente,Localizacao spot);
	void alugaBicicleta(string bikeType, Utilizacao ut, int idPP);
	int removeBicicleta(vector<int> index_distancias);
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


class PontoPartilha : public Sistema {
	Localizacao local;			/**< Localizacao do ponto de partilha */
	unsigned int capacidade;	/**< Capacidade do ponto de partilha */
	vector <vector<Bicicleta *> > bicicletas;	/**< Bicicletas existentes no ponto de partilha */
	string nome;				/**< Nome do ponto de partilha */
	static int UbikeNextID;		/**< Numero de identificacao da proxima bicicleta do tipo Urbana */
	static int USbikeNextID;	/**< Numero de identificacao da proxima bicicleta do tipo Urbana Simples */
	static int CbikeNextID;		/**< Numero de identificacao da proxima bicicleta do tipo Corrida */
	static int IbikeNextID;		/**< Numero de identificacao da proxima bicicleta do tipo Infantil */
public:
	PontoPartilha();	/**< Necessário para o overload do operador de extração na classe utente*/
	PontoPartilha(Localizacao spot,unsigned int storage,string name);

	void limpaVectorBike();
	friend ostream & operator <<(ostream & o, const PontoPartilha & p);
	friend istream & operator >>(istream & i, PontoPartilha & p);
	void removeBike(Bicicleta *bike);
	void adicionaBike(Bicicleta* bike);

	//Metodos Get
	static int getBikeNextId(string bike);
	Localizacao getLocal() const;
	string getNome() const;
	int getCapacidade() const;
	vector<int> getNumberOfBikes() const; // número de bicicletas de cada tipo
	vector <string> getBikeTypes();
	vector <vector<Bicicleta *> > getBikes() const;

	//Métodos Set
	void setNome(string name);
	static void setBikeNextId(string bike,const int value);
	static void setBikeNextIdForward(string bike);
	static void setBikeNextIdBackward(string bike);
};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo PontoPartilha nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream& operator <<(ostream & o, const PontoPartilha & p)
{
	o << p.nome << '/' << p.local << '/' << p.capacidade << '[' << p.bicicletas.at(0).size() << ','
			<< p.bicicletas.at(1).size() << ',' << p.bicicletas.at(2).size() << ',' << p.bicicletas.at(3).size() << ']';
	return o;
}

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo PontoPartilha,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, PontoPartilha & p)
{
	char b1, b2, b3, b4, b5, b6;
	unsigned int u,uc,c,inf; //4 tipos de bicicletas
	vector<Bicicleta *> v1,v2,v3,v4;
	vector <vector<Bicicleta *> > bikes{v1,v2,v3,v4};

	Bicicleta * b; //apontador genérico apenas para reservar espaço no vetor

	getline(i,p.nome,'/');
	i >> p.local >> b1 >> p.capacidade >> b2 >> u >> b3 >> uc >> b4 >> c >> b5 >> inf >> b6;

	for (unsigned int k=0 ; k<u ; k++){
		bikes.at(0).push_back(b);
	}
	for (unsigned int k=0 ; k<uc ; k++){
		bikes.at(1).push_back(b);
	}
	for (unsigned int k=0 ; k<c ; k++){
		bikes.at(2).push_back(b);
	}
	for (unsigned int k=0 ; k<inf ; k++){
		bikes.at(3).push_back(b);
	}

	p.bicicletas=bikes;
	return i;
}



