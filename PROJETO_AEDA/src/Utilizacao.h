#pragma once

#include "Includes.h"

class Data {
protected:
	unsigned int dia, mes, ano;
public:
	Data();
	Data(unsigned int dia,unsigned int mes,unsigned int ano);
	friend ostream & operator<<(ostream & o, const Data & d);
	friend istream & operator>>(istream & i, Data & d);

	//M�todos Get
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;

	//M�todos Set
	void setDia(unsigned int d);
	void setMes(unsigned int m);
	void setAno(unsigned int a);

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
	string pontoPartilha;
	string localizacao;
public:
	Utilizacao(); // necess�rio para o overload do operador de extra��o na classe utente
	Utilizacao(string bikeType, unsigned int numHours, Data d);
	Utilizacao(string bikeType, unsigned int numHours, Data d, string pp, string loc);
	friend ostream & operator <<(ostream & o, const Utilizacao & u);
	friend istream & operator >>(istream & i, Utilizacao & u);
	void displayUtilizacao();

	//M�todos Get
	Data getData() const;
	unsigned int getUseTime() const;
	string getBikeType() const;
	double getPrice() const;
};

inline ostream& operator <<(ostream & o, const Utilizacao & u)
{
	o << u.bikeType << '-' <<  u.pontoPartilha << '-' <<  u.localizacao << '-' << u.useTime << '-' <<  u.data ;
	return o;
}

inline istream& operator >>(istream & i, Utilizacao & u)
{
	char b1;
	getline(i,u.bikeType,'-');
	getline(i,u.pontoPartilha,'-');
	getline(i,u.localizacao,'-');
	i >> u.useTime >> b1 >> u.data;
	return i;
}
