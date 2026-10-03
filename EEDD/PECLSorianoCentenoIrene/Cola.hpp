#ifndef COLA_HPP
#define COLA_HPP

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
	
private:
	NodoCola* primero;
	NodoCola* ultimo;
	int longitud;
	
};

#endif // COLA_HPP
