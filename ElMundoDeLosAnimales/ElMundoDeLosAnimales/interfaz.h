#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <iostream>
#include <string>
#include "control.h"


///<summary>Implementacion de la clase Interfaz</summary>
class Interfaz {
private:
	std::string const MARGEN = "\t\t\t";
	Control *control;
public:
	Interfaz();
	~Interfaz();
	void menu();
	void juego();
	void reordenar();
	void imprimirTitulo();
	std::string volverJuego(std::string);
	bool adivinar();
	void resultado(bool);
};

#endif // !INTERFAZ_H

