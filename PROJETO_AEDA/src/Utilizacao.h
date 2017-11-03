#pragma once

#include "Includes.h"

class Data {
protected:
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

inline ostream & operator<< (ostream & o, const Data & d){
	o << d.dia << '/' << d.mes << '/' << d.ano;
	return o;
}

inline istream & operator>> (istream & i, Data & d)
{
	char b1, b2;
	return i >> d.dia >> b1 >> d.mes >> b2 >> d.ano;
}


class Utilizacao : protected Data{
private:
	Data data;
	unsigned int useTime;
	string bikeType;
public:
	Utilizacao(); // necessario para o overload do operador de extracao na classe utente
	Utilizacao(string bikeType, unsigned int numHours, Data d);

	//Metodos get
	Data getData() const;
	unsigned int getUseTime() const;
	string getBikeType() const;
	friend ostream & operator <<(ostream & o, const Utilizacao & u);
	friend istream & operator >>(istream & i, Utilizacao & u);
};

inline ostream& operator <<(ostream & o, const Utilizacao & u)
{
	o << u.bikeType << '-' << u.useTime << '-' <<  u.data;
	return o;
}

inline istream& operator >>(istream & i, Utilizacao & u)
{
	char b1, b2;
	i >>  u.bikeType >> b1 >> u.useTime >> b2 >> u.data;
	return i;
}
