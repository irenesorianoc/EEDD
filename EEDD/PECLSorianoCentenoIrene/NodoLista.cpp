#include "NodoLista.hpp"

NodoLista::NodoLista(Paciente* p, NodoLista sig)
{
	this->paciente=p;
	this->siguiente=sig;
}

NodoLista::~NodoLista()
{
}

