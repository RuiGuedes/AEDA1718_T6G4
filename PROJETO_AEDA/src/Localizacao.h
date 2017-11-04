#pragma once

#include "Includes.h"

class Localizacao {
	string nome;
	double x, y;
public:
	Localizacao();  //default
	Localizacao(string nome, double x, double y);

	//Metodos get
	string getNome() const;
	double getX() const;
	double getY() const;

	//Metodos set
	void setNome(string nome);
	void setX(double x);
	void setY(double y);

	//Outros
	double distancia(Localizacao local) const;
	Localizacao & operator =(Localizacao & l);
	friend ostream & operator <<(ostream & o, const Localizacao & l);
	friend istream & operator >>(istream & i, Localizacao & l);
};

inline ostream& operator <<(ostream & o, const Localizacao & l)
{
	o << l.nome << '/' << l.x << '/' <<  l.y;
	return o;
}

inline istream& operator >>(istream & i, Localizacao & l)
{
	char b1, b2;
	i >>  l.nome >> b1 >> l.x >> b2 >> l.y;
	return i;
}
