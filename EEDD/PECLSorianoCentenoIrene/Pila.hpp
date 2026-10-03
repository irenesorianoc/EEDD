#ifndef PILA_HPP
#define PILA_HPP
#include <iostream>
#include "NodoPila.hpp"

class Pila
{
public:
	Pila();
	~Pila();
	void apilar(Paciente* p);
	Paciente* desapilar();
	bool estaVacia();
	int getLongitud();
	void mostrar();
	void vaciar();

private:
	NodoPila* ultimo;
	int longitud;
	
};

#endif // PILA_HPP
