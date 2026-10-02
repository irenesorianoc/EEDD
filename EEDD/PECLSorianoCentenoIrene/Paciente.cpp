#include "Paciente.hpp"


Paciente::Paciente(bool enfermedad)
{
	this->enfermedad=enfermedad;
	this->DNI=crearDNI();
	
}

Paciente::~Paciente()
{
}

string Paciente::crearDNI(){
	string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    string dni = "";
    int numero = 0;

    for (int i = 0; i < 8; i++) {
        int digito = rand() % 10;
        dni += to_string(digito);
        numero = numero * 10 + digito;
    }


    dni += letras[numero % 23];

    return dni;
}

void Paciente::setID(int id){
	this->ID=id;
}

int Paciente::getID(){
	return ID;
}

string Paciente::getDNI(){
	return DNI;
}

void Paciente::setNumHab(int num){
	this->numHab=num;
}

int Paciente::getNumHab(){
	return numHab;
}

bool Paciente::esEnfermedad(){
	return enfermedad;
}

void Paciente::mostrar(){
	string enfer;
	if(esEnfermedad()){
		enfer="hernias";
	}else{
		enfer="apendicitis";
	}
	cout<<"El paciente cuyo DNI es "<<getDNI()<< " tiene "<<enfer<<endl;
}


