#ifndef LISTA_HPP
#define LISTA_HPP
#include <iostream>
#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
	
	void insertar(Paciente* p);
	Paciente* eliminar(int id);
	Paciente* extraerPrimero();
	Paciente* verPrimero();
	Paciente* verUltimo();
	bool estaVacia();
	int getLongitud();
	void mostrar();
	void vaciar();

private:
	NodoLista* primero;
	int longitud;
};

#endif // LISTA_HPP
