#pragma once

#include "Includes.h"

class Bicicleta {
protected:
	string bikeName; 			/**< Nome da bicicleta, composto pelas iniciais do tipo e um numero (ex: "u5" = bicicleta Urbana numero 5 (existem 4 antes desta)) */
	int price;					/**< Preco referente ao valor de uma mensalidade associada a um tipo de bicicleta */
public:
	Bicicleta();				/**< Necessário para o overload do operador de extração na classe utente*/
	Bicicleta(string name);
	virtual ~Bicicleta() {};

	//Métodos Get
	string getBikeName() const;
	int getPrice() const;
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

