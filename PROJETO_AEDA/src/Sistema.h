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
	void addPontoPartilha(PontoPartilha* spot); 	 //Criacao de uma nova loja
	void addNewUtente(Utente* utente);	 		 	//Adiciona um novo utente
	void removePonto(int indexPP);
	void removeUtente(int indexUT);

	//Metodos Get
	vector<Utente* > getUtentes();
	vector<PontoPartilha* > getPontosPartilha();

};


class Utente : public Sistema{
	static int lastId;
	int id;
	string nome;
	string tipoUtente;
	Localizacao local;		//Localizacao é uma classe
	Bicicleta* bike;		//Bicicleta é uma classe
	vector<Utilizacao> utilizacoes;	//Apenas associadas aos sócios
	vector<Utilizacao> historico;
	bool disponivel = true;
public:
	Utente();
	explicit Utente(string nome, string tipoUtente,Localizacao spot);
	void alugaBicicleta(Sistema &ER,string bikeType, Utilizacao ut, int idPP);
	int removeBicicleta(Sistema &ER, vector<int> index_distancias); 			//Retorna o indice do ponto de partilha afetado
	void devolveBicicleta();
	void pagaMensalidade(Sistema &ER, unsigned int ano, unsigned int mes);
	void updateHistoric();
	friend ostream & operator <<(ostream & o, const Utente & u);
	friend istream & operator >>(istream & i, Utente & u);

	//Metodos Get
	static int getLastId();
	int getId() const;
	string getUtenteNome() const;
	string getTipoUtente() const;
	Localizacao getLocalizacao() const;
	Bicicleta* getBike() const;
	vector<Utilizacao> getUtilizacoes();
	bool getAvailable() const;
	vector<Utilizacao> getHistorico();

	//Metodos Set
	static void setLastId();
	void setIDBackward();
	void setID(int identificacao);
	void setUtenteLocation(Localizacao spot);
	void setTipoUtente(string tipo);  	//Necessita de pagar dividas anteriores antes de poder mudar de tipo
	void setAvailable();
	void setBike(Bicicleta* bike);
	void setHistoric(Utilizacao ut);
	void setUtilizacoes(Utilizacao ut);
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
	Localizacao local;
	unsigned int capacidade;
	vector <vector<Bicicleta *> > bicicletas;
	string nome;
	static int UbikelastID;
	static int USbikelastID;
	static int CbikelastID;
	static int IbikelastID;
public:
	PontoPartilha();
	PontoPartilha(Localizacao spot,unsigned int storage,string name);

	void limpaVectorBike();
	friend ostream & operator <<(ostream & o, const PontoPartilha & p);
	friend istream & operator >>(istream & i, PontoPartilha & p);
	void removeBike(Bicicleta *bike);
	void adicionaBike(Bicicleta* bike);

	//Metodos Get
	static int getBikeLastId(string bike);
	Localizacao getLocal() const;
	string getNome() const { return nome; }
	int getCapacidade() const;
	vector<int> getNumberOfBikes() const; // numero de bicicletas de cada tipo
	vector <string> getBikeTypes();
	vector <vector<Bicicleta *> > getBikes() const;

	//Metodos Set
	void setNome(string name);
	static void setBikeLastIdFoward(string bike);
	static void setBikeLastIdBackward(string bike);
};

inline ostream& operator <<(ostream & o, const PontoPartilha & p)
{
	o << p.nome << '/' << p.local << '/' << p.capacidade << '[' << p.bicicletas.at(0).size() << ','
			<< p.bicicletas.at(1).size() << ',' << p.bicicletas.at(2).size() << ',' << p.bicicletas.at(3).size() << ']';
	return o;
}

inline istream& operator >>(istream & i, PontoPartilha & p)
{
	char b1, b2, b3, b4, b5, b6;
	unsigned int u,uc,c,inf; //4 tipos de bicicletas
	vector<Bicicleta *> v1,v2,v3,v4;
	vector <vector<Bicicleta *> > bikes{v1,v2,v3,v4};

	Bicicleta * b; //apontador generico apenas para reservar espaco no vetor

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



