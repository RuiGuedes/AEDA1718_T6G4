#pragma once

#include "Includes.h"

enum Biketype {
	URBANA = 0, URBANA_SIMPLES = 1, CORRIDA = 2, INFANTIL = 3
};

class Bicicleta {
protected:
	string bikeType; /**< Tipo de bicicleta*/
	string bikeName; /**< Nome da bicicleta, composto pelas iniciais do tipo e um numero (ex: "u5" = bicicleta Urbana numero 5 (existem 4 antes desta)) */
	int price;
public:
	Bicicleta();/**< Necessário para o overload do operador de extração na classe utente*/
	Bicicleta(string name);
	virtual ~Bicicleta() {};
	friend ostream & operator <<(ostream & o, const Bicicleta & b);
	friend istream & operator >>(istream & i, Bicicleta & b);

	//Métodos Get
	string getBikeType() const;
	string getBikeName() const;

	int getPrice() const;


};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Bicicleta nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream& operator <<(ostream & o, const Bicicleta & b)
{
	o << b.bikeName << '/' << b.bikeType << '/';
	return o;
};

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Bicicleta,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Bicicleta & b)
{
	getline(i,b.bikeName,'/');
	getline(i,b.bikeType,'/');
	return i;
};

class Urbana : public Bicicleta {
	static int id;
public :
	Urbana(string bikeName);
	~Urbana(){};
};

class UrbanaSimples : public Bicicleta {
	static int id;
public :
	~UrbanaSimples(){};
	UrbanaSimples(string bikeName);

};

class Corrida : public Bicicleta {
	static int id;
public :
	~Corrida(){};
	Corrida(string bikeName);


};

class Infantil : public Bicicleta {
	static int id;
public :
	~Infantil(){};
	Infantil(string bikeName);

};

