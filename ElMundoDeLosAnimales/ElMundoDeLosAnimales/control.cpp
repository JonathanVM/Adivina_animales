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
void Control::agregar(std::string caracteristica, std::string animal) {
	mundoA->insertarNuevo(caracteristica,animal);
}

void Control::reiniciar() {
	mundoA->reiniciar();
}

void Control::terminar() {
}

void Control::mover(unsigned int, unsigned int) {

}

std::string Control::siguientePalabra(char obtener) {
	return mundoA->adivinar(obtener);
}

bool Control::finDelJuego() {
	return mundoA->finDelJuego();
}