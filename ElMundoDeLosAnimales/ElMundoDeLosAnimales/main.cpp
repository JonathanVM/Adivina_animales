#include <iostream>
#include "interfaz.h"

int main() {
	Interfaz *inter = new Interfaz();
	inter->juego();
	delete inter;
	return 0;
}