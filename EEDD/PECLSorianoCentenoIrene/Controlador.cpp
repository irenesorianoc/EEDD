#include "Controlador.hpp"

Controlador::Controlador()
{
	srand(time(NULL));
	inicializarAleatorios();
}

Controlador::~Controlador()
{
	reiniciar();
}

void Controlador::inicializarAleatorios(){
	idsDisponibles.clear();
	habitacionesDisponibles.clear();
	for(int i=1;i<=100;i++){
		idsDisponibles.push_back(i);
	}
	for(int i=101;i<=200;i++){
		habitacionesDisponibles.push_back(i);
	}
	
	random_shuffle(idsDisponibles.begin(), idsDisponibles.end());
	random_shuffle(habitacionesDisponibles.begin(), habitacionesDisponibles.end());
}

int Controlador::pacientesEnPila(){
	return pila.getLongitud();
}

int Controlador::pacientesEnSalaA(){
	return salaA.getLongitud();
}

int Controlador::pacientesEnSalaB(){
	return salaB.getLongitud();
}

int Controlador::pacientesEnSalaC(){
	return salaC.getLongitud();
}

int Controlador::pacientesEnSalaD(){
	return salaD.getLongitud();
}

int Contolador::pacientesEnListaApendicitis(){
	return quirofanoApendicitis.getLongitud();
}

int Controlador::pacientesEnListaHernias(){
	return quirofanoHernias.getLongitud();
}

void Controlador::generar12Pacientes(){
	for(int i=0;i<12;i++){
		bool enf = rand()%2; // 0 apendicitis 1 hernia
		Paciente* p =new Paciente(enf);
		pila.apilar(p);
	}
	cout<<"Se han generado y apilado 12 pacientes correctamente"<<endl;
}

void Controlador::muestraPacientes(){
	pila.mostrar();
}

void Controlador::borrarPacientesPila(){
	pila.vaciar();
	cout<<"Se han borrado los pacientes de la pila"<<endl;
}


void Controlador::encolarPacientes(){
	if(pila.estaVacia()){
		cout<<"No hay pacientes en la pila para enviar a las salas"<<endl;
		return;
	}
	while(!pila.estaVacia()){
		Paciente* p=pila.desapilar();
		p->setID(idsDisponibles.back());
		idsDisponibles.pop_back();
		p->setNumHab(habitacionesDisponibles.back());
		habitacionesDisponibles.pop_back();
		if(!p->esEnfermedad(){
			if(salaA.getLongitud()<=salaB.getLongitud()){
				salaA.encolar(p);
			}else{
				salaB.encolar(p);
			}
		}else{
			if(salaC.getLongitud()<=salaD.getLongitud()){
				salaC.encolar(p);
			}else{
				salaD.encolar(p);
			}
		}
	}
	cout<<"Pacientes distribuidos en las salas de preoperatorio"<<endl;
}

void Controlador::muestraPacientesSalasAyB(){
	cout<<"\n --- SALA C (Hernias) ---"<<endl;
	salaC.mostrar();
	cout<<"\n --- SALA D (Hernias) ---"<<endl;
	salaD.mostar();
}

void Controlador::borrarPacientesColas(){
	salaA.vaciar();
	salaB.vaciar();
	salaC.vaciar();
	salaD.vaciar();
	cout<<"Se han vaciado todas las salas de preoperatorio"<<endl;
}

void Controlador::enlistarPacientes(){
	while(!salaA.estaVacia()){
		quirofanoApendicitis.insertar(salaA.desencolar());
	}
	while(!salaB.estaVacia()){
		quirofanoApendicitis.insertar(salaB.desencolar());
	}
	while(!salaC.estaVacia()){
		quirofanoHernias.insertar(salaC.desencolar());
	}
	while(!salaD.estaVacia()){
		quirofanoHernias.insertar(salaD.desencolar());
	}
	cout<<"Pacientes trasladados a los quirofanos correspondientes"<<endl;
}

void Controlador::muestraPacientesHernias(){
	cout<<"\n --- QUIROFANO HERNIAS ---"<<endl;
	quirofanoHernias.mostrar();
}

void Controlador::muestraPacientesApendicitis(){
	cout<< "\n --- QUIROFANO APENDICITIS ---"<<endl;
	quirofanoApendicitis.mostrar();
}

void Controlador::buscarPacientes() {
    cout << "\n\t--- BUSQUEDA DE PRIORIDADES EN QUIROFANOS ---\n\n";
    if (quirofanoApendicitis.estaVacia()) {
        cout << "\tNo hay pacientes en el quirofano de apendicitis.\n";
    } else {
        Paciente* pApendicitis = quirofanoApendicitis.verUltimo();
        cout << "\tPaciente con apendicitis de MENOR prioridad (ID mas alto):\n\t";
        pApendicitis->mostrar();
    }

    cout << endl;
    if (quirofanoHernias.estaVacia()) {
        cout << "\tNo hay pacientes en el quirofano de hernias.\n";
    } else {
        Paciente* pHernia = quirofanoHernias.verPrimero();
        cout << "\tPaciente con hernia de MAYOR prioridad (ID mas bajo):\n\t";
        pHernia->mostrar();
    }
}

void Controlador::reiniciar(){
	pila.vaciar();
	salaA.vaciar();
	salaB.vaciar();
	salaC.vaciar();
	salaD.vaciar();
	quirofanoApendicitis.vaciar();
	quirofanoHernias.vaciar();
	inicializarAleatorios();
	cout<<"Sistema reiniciado por completo"<<endl;
}