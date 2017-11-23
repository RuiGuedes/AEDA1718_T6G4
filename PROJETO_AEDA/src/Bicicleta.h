#pragma once

#include "Includes.h"

class Bicicleta {
protected:
	string bikeName; 			/**< Nome da bicicleta, composto pelas iniciais do tipo e um numero (ex: "u5" = bicicleta Urbana numero 5 (existem 4 antes desta)) */
	int price;					/**< Preco referente ao valor de uma mensalidade associada a um tipo de bicicleta */
public:
	Bicicleta();				/**< Necess�rio para o overload do operador de extra��o na classe utente*/
	Bicicleta(string name);
	virtual ~Bicicleta() {}; 	/**<Destrutor virtual */

	//M�todos Get
	string getBikeName() const;
	int getPrice() const;
};

class Urbana : public Bicicleta {
	static int id;				/**< Identificador da proxima bicicleta do tipo urbana */
public :
	Urbana(string bikeName);
	~Urbana(){};				/**<Destrutor da classe Urbana */

	//M�todos Get
	static int getID();
};

class UrbanaSimples : public Bicicleta {
	static int id;				/**< Identificador da proxima bicicleta do tipo urbana simples */
public :
	UrbanaSimples(string bikeName);
	~UrbanaSimples(){};			/**<Destrutor da classe UrbanaSimples */

	//M�todos Get
	static int getID();
};

class Corrida : public Bicicleta {
	static int id;				/**< Identificador da proxima bicicleta do tipo corrida */
public :
	Corrida(string bikeName);
	~Corrida(){};				/**<Destrutor da classe Corrida */

	//M�todos Get
	static int getID();
};

class Infantil : public Bicicleta {
	static int id;				/**< Identificador da proxima bicicleta do tipo infantil */
public :
	Infantil(string bikeName);
	~Infantil(){};				/**<Destrutor da classe Infantil */

	//M�todos Get
	static int getID();
};

