#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
#include "control.h"

class Interfaz {
private:

public:
	Interfaz();
	~Interfaz();
	void jugar();
	void iniciar();
	void resultado(bool);
	bool adivinar();
};

#endif // !INTERFAZ_H

