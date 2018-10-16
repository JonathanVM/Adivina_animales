#include <iostream>
#include "interfaz.h"

int main() {
	Interfaz *inter = new Interfaz();
	inter->juego();

	system("pause");
	delete inter;
	return 0;
}