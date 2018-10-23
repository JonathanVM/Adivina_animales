#include "arbol.h"

#ifndef MUNDOANIMALES_H
#define MUNDOANIMALES_H

#include <iostream>
#include <fstream>


///<summary>Implementacion de la clase MundoAnimales (Modelo)</summary>
class MundoAnimales {
private:
	NODOPTR root;
	NODOPTR actual;
	NODOPTR anterior;
	bool terminoJuego;
	Arbol * arbol;

	bool moverCaracteristicaArriba(NODOPTR, NODOPTR, unsigned int);
	bool moverCaracteristicaAbajo(NODOPTR, NODOPTR, unsigned int);
public:
	MundoAnimales();
	~MundoAnimales();
	void leerArchivo();
	void armarArbolArhivo(NODOPTR, std::ifstream&, std::string&, bool);
	void guardarArchivo();
	void guardarArchivo(std::ofstream&, NODOPTR, int);
	void valoresPorDefecto();
	bool insertarNuevo(std::string, std::string);//Tal vez recibir nodos creados en el control y ahi verificar si hay mas memoria disponible.
	void reiniciar();
	bool moverCaracteristica(unsigned int posActual, unsigned int posNueva, bool metodo);
	bool existePalabra(std::string,NODOPTR);
	bool existePalabra(std::string);
	bool finDelJuego();
	std::string adivinar(char opcion);
	NODOPTR crearNodo(std::string);//Verifica si hay memoria o no.
	NODOPTR obtenerCaracteristicaGeneral(unsigned int);
	void imprimirArbol();


	int const CARACTERISTICAS_GENERALES = 6;
};

#endif // !MUNDOANIMALES_H

