#ifndef PACIENTE_HPP
#define PACIENTE_HPP
#include <iostream>
#include <cstdlib> 
#include <string>  
using namespace std;

class Paciente
{
public:
	Paciente();
	~Paciente();
	void setID(int id);
	int getID();
	void setNumHab(int num);
	int getNumHab();
	bool esEnfermedad();
	void mostrar();

private:
	string DNI;
	int ID;
	int numHab;
	bool enfermedad; // 0 apendicitis 1 hernia

private:
	string crearDNI();
	string getDNI();
	
};

#endif // PACIENTE_HPP
