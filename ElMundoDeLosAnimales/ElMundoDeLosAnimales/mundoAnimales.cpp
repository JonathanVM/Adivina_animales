#include "mundoAnimales.h"

MundoAnimales::MundoAnimales() {
	root = actual = anterior = nullptr;
	terminoJuego = false;
}
MundoAnimales::~MundoAnimales() {

}
void MundoAnimales::leerArchivo() {

}
void MundoAnimales::guardarArchivo() {

}
void MundoAnimales::valoresPorDefecto() {

}
void MundoAnimales::insertarNuevo(std::string caracteristica, std::string animal) {
	NODOPTR carac = crearNodo(caracteristica);
	NODOPTR anim = crearNodo(animal);
	if (carac && anim) {
		carac->left = anterior->right;
		carac->right = anim;
		anterior->right = carac;
	} else
		throw "Ya no se pueden agregar mas animales";
}
void MundoAnimales::reiniciar() {
	actual = anterior = root;
	terminoJuego = false;
}
bool MundoAnimales::moverCaracteristica(unsigned int posActual, unsigned int posNueva) {

}
bool MundoAnimales::seguirPreguntando() {
	return terminoJuego;
}
std::string MundoAnimales::adivinar(char opc = ' ') {
	std::string valor = "";
	if (actual) {
	//Evita que cuando es una hoja, se haga actual null, por un exceso de llamadas externas cuando el juego ya ha terminado.
		if (actual->left && actual->right) {//Segun la logica del proyecto un nodo no hoja siempre tiene dos hijos.
			if (opc == 'S') {
				anterior = actual;
				actual = actual->left;
			}
			if (opc == 'N') {
				anterior = actual;
				actual = actual->right;
			}
		}
		else {
			terminoJuego = true;
		}
		valor = actual->elemento;
	}
	return valor;
}


///<summary> Crea un nuevo nodo, siempre y cuando haya memoria disponible.</summary>
///<returns>Retorna un nuevo nodo, o retorna null si no hay memoria </returns>
NODOPTR MundoAnimales::crearNodo(std::string nuevo) {
	NODOPTR nuevoNodo;
	try{
		nuevoNodo = new nodo;
		nuevoNodo->elemento;
		nuevoNodo->left = nuevoNodo->right = nullptr;
		return nuevoNodo;
	}catch (std::bad_alloc exception){
		return nullptr;
	}
}