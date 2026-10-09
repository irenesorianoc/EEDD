#include "Lista.hpp"

Lista::Lista()
{
	this->primero=NULL;
	this->longitud=0;
}

Lista::~Lista()
{
	vaciar();
}

bool Lista::estaVacia(){
	if(primero==NULL){
		return true;
	}
	return false;
}

int Lista::getLongitud(){
	return longitud;
}

void lista::insertar(Paciente* p){
	if(estaVacia()||p->getID() < primero->paciente->getID()){
		primero= new NodoLista(p,primero);
	}else{
		NodoLista* actual= primero;
		while(actual->siguiente !=NULL && actual->siguiente->paciente->getID()<p->getID()){
			actual=actual->siguiente;
		}
		actual->siguiente=new Nodolista(p,actual->siguiente);
	}
	longitud++;
}

Paciente* Lista::extraerPrimero(){
	if(estaVacia()){
		return NULL;
	}
	NodoLista* aux=primero;
	Paciente* p= aux->paciente;
	primero=primero->siguiente;
	delete aux;
	longitud--;
	return p;
}

Paciente* Lista::eliminar(int id){
	if(estaVacia()){
		return NULL;
	}
	
	NodoLista* aux=primero;
	NodoLista* anterior=NULL;
	
	while(aux!=NULL && aux->paciente->getID() != id){
		anterior = aux;
		aux= aux->siguiente;
	}
	
	if(aux==NULL){
		return NULL;
	}
	if(anterior==NULL){
		primero=primero->siguiente;
	}else{
		anterior->siguiente=aux->siguiente;
	}
	
	Paciente* p =aux->paciente;
	delete aux;
	longitud--;
	return p;
}

Paciente* Lista::verPrimero() {
    if (estaVacia()){
		return NULL;
	}
    return primero->paciente;
}

Paciente* Lista::verUltimo() {
    if (estaVacia()){
		return NULL;
	}
    NodoLista* aux = primero;
    while (aux->siguiente != NULL) {
        aux = aux->siguiente;
    }
    return aux->paciente;
}

void Lista::mostrar(){
	if(estaVacia()){
		cout<<"La lista esta vacia"<<endl;
		return;
	}
	
	NodoLista* aux= primero;
	while(aux!=NULL){
		aux->paciente->mostrar();
		aux=aux->siguiente;
	}
}

void Lista::vaciar(){
	while(!estaVacia()){
		Paciente* p =extraerPrimero();
		delete p;
	}
}