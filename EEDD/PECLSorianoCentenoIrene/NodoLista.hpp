#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include <iostream>
#include "Paciente.hpp"

class NodoLista
{
public:
	NodoLista(Paciente* p, NodoLista sig=NULL);
	~NodoLista();

private:
	Paciente* paciente;
	NodoLista* siguiente;
	
	friend class Lista;

};

#endif // NODOLISTA_HPP
