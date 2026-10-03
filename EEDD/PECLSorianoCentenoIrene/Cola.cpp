#include "Cola.hpp"

Cola::Cola()
{
	this->primero=NULL;
	this->ultimo=NULL;
	this->longitud=0;
}

Cola::~Cola()
{
	vaciar();
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
	primero=primero->siguiente;
	delete aux;
	
	if(primero==NULL){
		ultimo=NULL;
	}
	
	longitud--;
	return p;
	
}

Paciente* Cola::verPrimero(){
	if(estaVacia()){
		return NULL;
	}
	Paciente* p= primero->paciente;
	return p;
}

int Cola::getLongitud(){
	return longitud;
}


void Cola::mostrar() {
    if (estaVacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    NodoCola* aux = primero;
    while (aux != NULL) {
        aux->paciente->mostrar();
        aux = aux->siguiente;
    }
}

void Cola::vaciar(){
	while (!estaVacia()) {
        Paciente* p = desencolar();
        delete p; 
    }
}