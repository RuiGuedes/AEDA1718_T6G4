#include "Localizacao.h"

Localizacao::Localizacao(){
	this->nome = "";
	this->x = 0.0;
	this->y = 0.0;
}

Localizacao::Localizacao(string nome, double x, double y){
	this->nome = nome;
	this->x = x;
	this->y = y;
}


/////////////////
// METODOS GET //
/////////////////

string Localizacao::getNome() const{
	return nome;
}

double Localizacao::getX() const{
	return x;
}

double Localizacao::getY() const{
	return y;
}


/////////////////
// METODOS SET //
/////////////////

void Localizacao::setNome(string nome) {
	this->nome = nome;
}

void Localizacao::setX(double x) {
	this->x = x;
}

void Localizacao::setY(double y) {
	this->y = y;
}


////////////
// OUTROS //
////////////

Localizacao & Localizacao::operator =(Localizacao & l) {
	setNome(l.nome);
	setX(l.x);
	setY(l.y);
	return *this;
}


double Localizacao::distancia(Localizacao local) const{
	return sqrt(pow((local.x - x),2) + pow((local.y - y),2));
}
