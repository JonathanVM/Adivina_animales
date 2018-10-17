
#include "mundoAnimales.h"
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>

class Control {
private:
	MundoAnimales *mundoA;
public:
	Control();
	~Control();
	void jugar(std::string);
	void agregar(std::string, std::string);
	void reiniciar();
	void terminar();
	void mover(unsigned int, unsigned int);
	std::string obtenerActual(char);
	bool seguirJuego();
};

#endif // !CONTROL_H

