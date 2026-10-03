#include "Cola.hpp"

Cola::Cola()
{
	this->primero=NULL;
	this->ultimo=NULL;
	this->longitud=0;
}

Cola::~Cola()
{
}

void Cola::encolar(Paciente* p){
	NodoCola* nuevo= new NodoCola(p);
	
	if(ultimo){
		ultimo->siguiente=nuevo;
	}
	ultimo=nuevo;
	if(!primero){
		primero=nuevo;
	}
	longitud++;
	
}

bool Cola::estaVacia(){
	if(primero==NULL){
		return true;
	}
	return false;
}

Paciente* Cola::desencolar(){
	
	if(estaVacia()){
		cout<<"Cola vacia"<<endl;
		return NULL;
	}
	NodoCola* aux=primero;
	Paciente* p= aux->paciente;
	primero=aux->siguiente;
	
	longitud--;
	return p;
	
}

Persona* Cola::verPrimero(){
	if(estaVacia()){
		return NULL;
	}
	Paciente* p= primero->paciente;
	return p;
}

int Cola::getLongitud(){
	return longitud;
}

void Cola::mostrar(){
	NodoCola* aux=primero;
	while(!estaVacia()){
		aux->paciente->mostrar();
		aux=aux->siguiente;
	}
}
