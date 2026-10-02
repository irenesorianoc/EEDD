#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente* p, NodoCola* sig){
	this->paciente=p;
	this->siguiente=sig;
}


NodoCola::~NodoCola()
{
}

