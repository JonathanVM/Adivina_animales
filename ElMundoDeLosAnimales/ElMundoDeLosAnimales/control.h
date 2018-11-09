
#include "mundoAnimales.h"
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>


///<summary>Implementacion de la clase Control, que interactua desde el modelo hasta la interfaz(Control)</summary>
class Control {
private:
	MundoAnimales *mundoA;
public:
	Control();
	~Control();
	bool agregar(std::string, std::string);
	void reiniciar();
	void mover(unsigned int, unsigned int);
	std::string siguientePalabra(char);
	bool finDelJuego();
	void imprimirArbol();
	void guardarArbol();
};

#endif // !CONTROL_H

