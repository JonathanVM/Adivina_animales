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
	void insertarNuevo(std::string, std::string);//Tal vez recibir nodos creados en el control y ahi verificar si hay mas memoria disponible.
	void reiniciar();
	bool moverCaracteristica(unsigned int, unsigned int, int);
	bool moverCaracteristicaArriba(NODOPTR, NODOPTR);
	bool moverCaracteristicaAbajo(NODOPTR, NODOPTR);
	
	bool finDelJuego();
	std::string adivinar(char opcion);
	NODOPTR crearNodo(std::string);//Verifica si hay memoria o no.
	NODOPTR obtenerCaracteristicaGeneral(unsigned int);
	int const CARACTERISTICAS_GENERALES = 6;
};

#endif // !MUNDOANIMALES_H

