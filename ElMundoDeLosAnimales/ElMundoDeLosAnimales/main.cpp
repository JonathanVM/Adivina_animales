#include <iostream>
#include "interfaz.h"

///<summary>
///Bienvenido a nuestro mundo de animales
///Integrantes:
///Jonathan Vásquez Mora
///Delia Hernández Ruiz
///</summary>
int main() {
	Interfaz *inter = new Interfaz();
	inter->juego();
	delete inter;

	return 0;
}