#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP
#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <ctime>     
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
using namespace std;

class Controlador
{
public:
	Controlador();
	~Controlador();
	int pacientesEnPila();
    int pacientesEnSalaA();
    int pacientesEnSalaB();
    int pacientesEnSalaC();
    int pacientesEnSalaD();
    int pacientesEnListaApendicitis();
    int pacientesEnListaHernias();


    void genera12Pacientes();         
    void muestraPacientes();           
    void borraPacientesPila();         
    void encolarPacientes();           
    void muestraPacientesSalasAyB();   
    void muestraPacientesSalasCyD();   
    void borraPacientesColas();        
    void enlistarPacientes();          
    void muestraPacientesApendicitis();
    void muestraPacientesHernias();    
    void buscarPacientes();            
    void reiniciar();

private:
	Pila pila;
	Cola salaA;
	Cola salaB;
	Cola salaC;
	Cola salaD;
	Lista quirofanoApendicitis;
	Lista quirofanoHernias;
	vector<int> idsDisponibles;
	vector<int> habitacionesDisponibles;
	void inicializarAleatorios();
};

#endif // CONTROLADOR_HPP
