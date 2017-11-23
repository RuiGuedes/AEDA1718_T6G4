#pragma once

#include "Includes.h"

class Bicicleta {
protected:
	string bikeName; 			/**< Nome da bicicleta, composto pelas iniciais do tipo e um numero (ex: "u5" = bicicleta Urbana numero 5 (existem 4 antes desta)) */
	int price;
public:
	Bicicleta();				/**< Necessário para o overload do operador de extração na classe utente*/
	Bicicleta(string name);
	virtual ~Bicicleta() {};

	//Métodos Get
	string getBikeName() const;
	int getPrice() const;

	//Others
	friend ostream & operator <<(ostream & o, const Bicicleta & b);
	friend istream & operator >>(istream & i, Bicicleta & b);
};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Bicicleta nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream& operator <<(ostream & o, const Bicicleta & b)
{
	o << b.bikeName;
	return o;
};

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Bicicleta,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Bicicleta & b)
{
	getline(i,b.bikeName,'\n');
	return i;
};

class Urbana : public Bicicleta {
	static int id;
public :
	Urbana(string bikeName);
	~Urbana(){};

	//Métodos Get
	static int getID();
};

class UrbanaSimples : public Bicicleta {
	static int id;
public :
	~UrbanaSimples(){};
	UrbanaSimples(string bikeName);

	//Métodos Get
	static int getID();
};

class Corrida : public Bicicleta {
	static int id;
public :
	~Corrida(){};
	Corrida(string bikeName);

	//Métodos Get
	static int getID();
};

class Infantil : public Bicicleta {
	static int id;
public :
	~Infantil(){};
	Infantil(string bikeName);

	//Métodos Get
	static int getID();
};

