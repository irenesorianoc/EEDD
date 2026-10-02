#include "NodoPila.hpp"

NodoPila::NodoPila(Paciente* p, NodoPila* sig)
{
	this->paciente=p;
	this->siguiente=sig;
}

NodoPila::~NodoPila()
{
}

