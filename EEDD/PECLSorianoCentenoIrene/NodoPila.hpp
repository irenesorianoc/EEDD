#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Paciente.hpp"

class NodoPila
{
public:
	NodoPila(Paciente* p, NodoPila* sig = NULL);
	~NodoPila();

private:
	Paciente* paciente;
	NodoPila* siguiente;

	friend class Pila
};



#endif // NODOPILA_HPP
