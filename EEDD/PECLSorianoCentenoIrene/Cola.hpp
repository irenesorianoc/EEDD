#ifndef COLA_HPP
#define COLA_HPP
#include <iostream>
#include "NodoCola.hpp"

class Cola
{
public:
	Cola();
	~Cola();
	void encolar(Paciente* p);
	bool estaVacia();
	Paciente* desencolar();
	Paciente* verPrimero();
	int getLongitud();
	void mostrar();
	void vaciar();
	
private:
	NodoCola* primero;
	NodoCola* ultimo;
	int longitud;
	
};

#endif // COLA_HPP
