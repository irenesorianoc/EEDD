#include "Pila.hpp"

Pila::Pila()
{
	this->ultimo=NULL;
	this->longitud=0;
}

Pila::~Pila()
{
	vaciar();
}

void Pila::apilar(Paciente* p){
	NodoPila* nuevo= new NodoPila(p,ultimo);
	ultimo=nuevo;
	longitud++;
}

bool Pila::estaVacia(){
	if (ultimo == NULL) {
        return true;
    }
    return false;
}


Paciente* Pila::desapilar(){
	if(estaVacia()){
		return NULL;
	}
	
	NodoPila* aux = ultimo;
	Paciente* p =aux->paciente;
	
	ultimo= ultimo->siguiente;
	delete aux;
	longitud--;
	return p;
}

int Pila::getLongitud(){
	return longitud;
}

void Pila::vaciar(){
	while(!estaVacia()){
		Paciente* p = desapilar();
		delete p;
	}
}

void Pila::mostrar(){
	if(estaVacia()){
		cout<<"La pila esta vacia"<< endl;
		return;
	}
	NodoPila* actual= ultimo;
	while(actual!=NULL){
		actual->paciente->mostrar();
		actual= actual->siguiente;
	}
}
