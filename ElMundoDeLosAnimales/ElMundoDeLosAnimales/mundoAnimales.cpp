#include "mundoAnimales.h"

MundoAnimales::MundoAnimales() {
	root = actual = anterior = nullptr;
}
MundoAnimales::~MundoAnimales() {

}
void MundoAnimales::leerArchivo() {

}
void MundoAnimales::guardarArchivo() {

}
void MundoAnimales::valoresPorDefecto() {

}
void MundoAnimales::insertarNuevo(std::string, std::string) {

}
void MundoAnimales::reiniciar() {
	actual = anterior = root;
}
bool MundoAnimales::moverCaracteristica(unsigned int posActual, unsigned int posNueva) {

}
NODOPTR MundoAnimales::adivinar(char opc = ' ') {
	if (actual) {
		if (opc == 'S') {
			anterior = actual;
			actual = actual->left;
		}
		if (opc == 'N') {
			anterior = actual;
			actual = actual->right;
		}
	}
	return actual;
}


///<summary> Crea un nuevo nodo, siempre y cuando haya memoria disponible.</summary>
///<returns>Retorna un nuevo nodo, o return null si no hay memoria </returns>
NODOPTR MundoAnimales::crearNodo(std::string nuevo) {
	NODOPTR nuevoNodo;
	// Manejo de excepciones. Si no hay memoria para crear un nodo nuevo
	// se lanza una excepción
	//
	try{
		nuevoNodo = new nodo;
		nuevoNodo->elemento;
		nuevoNodo->left = nuevoNodo->right = nullptr;
		return nuevoNodo;
	}catch (std::bad_alloc exception){
		return nullptr;
	}
}