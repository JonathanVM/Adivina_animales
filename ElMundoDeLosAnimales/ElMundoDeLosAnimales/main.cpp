#include <iostream>
#include "interfaz.h"

///<summary>
///Bienvenido a nuestro mundo de animales
///Integrantes:
///Jonathan V�squez Mora
///Delia Hern�ndez Ruiz
///</summary>
int main() {
	Interfaz *inter = new Interfaz();
	inter->juego();
	delete inter;

	return 0;
}