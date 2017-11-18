#pragma once

#include "Includes.h"

class Bicicleta {
	string bikeType; /**< Tipo de bicicleta*/
	string bikeName; /**< Nome da bicicleta, composto pelas iniciais do tipo e um numero (ex: "u5" = bicicleta Urbana numero 5 (existem 4 antes desta)) */
public:
	Bicicleta();/**< Necessário para o overload do operador de extração na classe utente*/
	Bicicleta(string tipo, string name);
	friend ostream & operator <<(ostream & o, const Bicicleta & b);
	friend istream & operator >>(istream & i, Bicicleta & b);

	//Métodos Get
	string getBikeType() const;
	string getBikeName() const;
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
