#pragma once

#include "Includes.h"

class Localizacao {
	string nome;
	double x, y;
public:
	Localizacao();  //default
	Localizacao(string nome, double x, double y);
	double distancia(Localizacao local) const;
	Localizacao & operator =(Localizacao & l);
	friend ostream & operator <<(ostream & o, const Localizacao & l);
	friend istream & operator >>(istream & i, Localizacao & l);

	//Métodos Get
	string getNome() const;
	double getX() const;
	double getY() const;

	//Métodos Set
	void setNome(string nome);
	void setX(double x);
	void setY(double y);

};

inline ostream& operator <<(ostream & o, const Localizacao & l)
{
	o << l.nome << '/' << l.x << '/' <<  l.y;
	return o;
}

inline istream& operator >>(istream & i, Localizacao & l)
{
	char b1;
	getline(i,l.nome,'/');
	i >> l.x >> b1 >> l.y;
	return i;
}
