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

///<summary>Metodo que agrega una nueva caracteristica al arbol del sistema</summary>
bool Control::agregar(std::string caracteristica, std::string animal) {
	if (!mundoA->existePalabra(caracteristica)  && !mundoA->existePalabra(animal)) {
		return mundoA->insertarNuevo(caracteristica, animal);
	}
	return false;
}

///<summary></summary>
///<returns></returns>
void Control::reiniciar() {
	mundoA->reiniciar();
}

///<summary></summary>
///<returns></returns>
void Control::mover(unsigned int actual, unsigned int nueva) {
	if (actual  == nueva) {
		throw "No se pueden mover caracteristicas iguales";
	}
	else if((actual < 1 && actual > 6) || (nueva < 1 && nueva > 6)){
		throw "Los niveles de las caracteristicas generales van de 1 a 6";
	}
	else if (actual > nueva){
		mundoA->moverCaracteristica(actual, nueva, true);
	}
	else {
		mundoA->moverCaracteristica(actual, nueva, false);
	}
}

///<summary></summary>
///<returns></returns>
std::string Control::siguientePalabra(char obtener) {
	return mundoA->adivinar(obtener);
}

///<summary></summary>
///<returns></returns>
bool Control::finDelJuego() {
	return mundoA->finDelJuego();
}

///<summary></summary>
///<returns></returns>
void Control:: imprimirArbol() {
	mundoA->imprimirArbol();
}

void Control::guardarArbol() {
	mundoA->guardarArchivo();
}
