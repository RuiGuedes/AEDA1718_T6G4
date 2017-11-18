#include "Includes.h"

template<class T>
class OpcaoInvalida {
public:
	T opcao;
	OpcaoInvalida(T op) { opcao = op;}
};


template<class T>
class AberturaFalhada {
	T ficheiro;
public:
	/**
	 * Contrutor da classe AberturaFalhada
	 */
	AberturaFalhada(T file) { ficheiro = file;}
	/**
	 * Método get que o nome do ficheiro cuja abertura falhou
	 * @return nome do ficheiro
	 */
	T getFicheiro() const {return ficheiro;}
};
