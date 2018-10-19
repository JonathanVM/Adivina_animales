#include "arbolbin.h"

#ifndef MUNDOANIMALES_H
#define MUNDOANIMALES_H

#include <iostream>


///<summary>Implementacion de la clase MundoAnimales (Modelo)</summary>
class MundoAnimales {
private:
	NODOPTR root;
	NODOPTR actual;
	NODOPTR anterior;
	bool terminoJuego;
public:
	MundoAnimales();
	~MundoAnimales();
	void leerArchivo();
	void guardarArchivo();
	void valoresPorDefecto();
	bool insertarNuevo(std::string, std::string);//Tal vez recibir nodos creados en el control y ahi verificar si hay mas memoria disponible.
	void reiniciar();
	bool existePalabra(std::string,NODOPTR);
	bool existePalabra(std::string);
	//bool moverCaracteristica(unsigned int, unsigned int);
	bool finDelJuego();
	std::string adivinar(char opcion);
	NODOPTR crearNodo(std::string);//Verifica si hay memoria o no.
};

#endif // !MUNDOANIMALES_H

