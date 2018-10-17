#include "control.h"

Control::Control() {
	mundoA = new MundoAnimales();
}

Control::~Control() {
	delete mundoA;
}

void Control::jugar(std::string) {

}

void Control::agregar(std::string nombre, std::string caracteristica) {
	mundoA->insertarNuevo(nombre,caracteristica);
}

void Control::reiniciar() {
	mundoA->reiniciar();
}

void Control::terminar() {
}

void Control::mover(unsigned int, unsigned int) {

}

std::string Control::obtenerActual(char obtener) {
	return mundoA->adivinar(obtener);
}

bool Control::finDelJuego() {
	return mundoA->finDelJuego();
}