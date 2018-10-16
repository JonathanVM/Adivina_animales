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
NODOPTR MundoAnimales::crearNodo(std::string) {

}