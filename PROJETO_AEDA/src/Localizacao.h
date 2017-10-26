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
};
