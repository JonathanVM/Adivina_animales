#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
#include "control.h"

class Interfaz {
private:
	std::string const MARGEN = "\t\t\t";
	Control *control;
public:
	Interfaz();
	~Interfaz();
	void menu();
	void juego();
	std::string volverJuego();
	bool adivinar();
	void resultado(bool);
};

#endif // !INTERFAZ_H

