
#include "mundoAnimales.h"
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>


///<summary>Implementacion de la clase Control</summary>
class Control {
private:
	MundoAnimales *mundoA;
public:
	Control();
	~Control();
	bool agregar(std::string, std::string);
	void reiniciar();
	void terminar();
	void mover(unsigned int, unsigned int);
	std::string siguientePalabra(char);
	bool finDelJuego();
};

#endif // !CONTROL_H

