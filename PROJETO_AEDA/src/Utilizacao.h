#pragma once

#include "Includes.h"

class Utilizacao {
private:
	unsigned int dia, mes, ano;
	unsigned int useTime;
	string bikeType;
public:
	Utilizacao(string bikeType, unsigned int numHours, unsigned int dia, unsigned int mes, unsigned int ano);

	//Metodos get
	unsigned int getdia() const;
	unsigned int getmes() const;
	unsigned int getano() const;
	unsigned int getUseTime() const;
	string getBikeType() const;
};


class Data {
	unsigned int dia, mes, ano;
public:
	Data();
	Data(unsigned int dia,unsigned int mes,unsigned int ano);
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;
	void setDia(unsigned int d);
	void setMes(unsigned int m);
	void setAno(unsigned int a);
	friend ostream & operator<<(ostream & o, const Data & d);
	friend istream & operator>>(istream & i, Data & d);
};

//ostream & operator<<(ostream & o, const Data & d)
//{
//	o << d.dia << '/' << d.mes << '/' << d.ano;
//	return o;
//}
//
//istream & operator>>(istream & i, Data & d)
//{
//	char b1, b2;
//	i >> d.dia >> b1 >> d.mes >> b2 >> d.ano;
//	return i;
//}
