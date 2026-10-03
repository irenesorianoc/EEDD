#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>
#include "Paciente.hpp"

class NodoCola
{
public:
	NodoCola(Paciente* p, NodoCola* sig = NULL);
	~NodoCola();

private:
	NodoCola* siguiente;
	Paciente* paciente;
	
	friend class Cola;
};

#endif // NODOCOLA_HPP
