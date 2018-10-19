#include "control.h"


///<summary>Constructor de la clase Control</summary>
///<remarks>Inicializa una instancia a la clase del modelo</remarks>
Control::Control() {
	mundoA = new MundoAnimales();
}

///<summary>Destructor de la clase Control</summary>
///<remarks>Destruye la instancia a la clase del modelo</remarks>
Control::~Control() {
	delete mundoA;
}

///<summary>Metodo que agregar una nueva caracteristica al arbol del sistema</summary>
bool Control::agregar(std::string caracteristica, std::string animal) {
	if (!mundoA->existePalabra(caracteristica)  && !mundoA->existePalabra(animal)) {
		return mundoA->insertarNuevo(caracteristica, animal);
	}
	return false;
}

void Control::reiniciar() {
	mundoA->reiniciar();
}

void Control::terminar() {
}

void Control::mover(unsigned int actual, unsigned int nueva) {
	if (actual  == nueva) {
		throw "No se pueden mover caracteristicas iguales";
	}
	else if((actual < 1 || actual > 6) || (nueva < 1 || nueva > 6)){
		throw "Los niveles de las caracteristicas generales van de 1 a 6";
	}
	else{
		//mundoA->moverCaracteristica(actual, nueva, )
	}
}

std::string Control::siguientePalabra(char obtener) {
	return mundoA->adivinar(obtener);
}

bool Control::finDelJuego() {
	return mundoA->finDelJuego();
}

void Control:: imprimirArbol() {
	mundoA->imprimirArbol();
}


