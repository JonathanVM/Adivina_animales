#include "mundoAnimales.h"

MundoAnimales::MundoAnimales() {
	root = actual = anterior = nullptr;
	terminoJuego = false;
	valoresPorDefecto();
}
MundoAnimales::~MundoAnimales() {

}
void MundoAnimales::leerArchivo() {

}
void MundoAnimales::guardarArchivo() {

}
void MundoAnimales::valoresPorDefecto() {
	NODOPTR ave = crearNodo("ave");
	NODOPTR aguila = crearNodo("Aguila");
	NODOPTR reptil = crearNodo("reptil");
	NODOPTR lagarto = crearNodo("Lagarto");
	NODOPTR mamifero = crearNodo("mamifero");
	NODOPTR acuatico = crearNodo("acuatico");
	NODOPTR ballena = crearNodo("Ballena");
	NODOPTR maulla = crearNodo("maulla");
	NODOPTR gato = crearNodo("Gato");
	NODOPTR perro = crearNodo("Perro");
	NODOPTR pez = crearNodo("pez");
	NODOPTR beta = crearNodo("Beta");
	NODOPTR invertebrado = crearNodo("invertebrado");
	NODOPTR arana = crearNodo("Arana");
	NODOPTR anfibio = crearNodo("anfibio");
	NODOPTR rana = crearNodo("Rana");
	NODOPTR culebra = crearNodo("Culebra");
	if (ave && aguila && reptil && lagarto && mamifero && acuatico && ballena && maulla 
		&& gato && perro && pez && beta && invertebrado && arana && anfibio && rana && culebra) {
		ave->right = aguila;
		ave->left = reptil;
		reptil->right = lagarto;
		reptil->left = mamifero;
		mamifero->right = acuatico;
		acuatico->right = ballena;
		acuatico->left = maulla;
		maulla->right = gato;
		maulla->left = perro;
		mamifero->left = pez;
		pez->right = beta;
		pez->left = invertebrado;
		invertebrado->right = arana;
		invertebrado->left = anfibio;
		anfibio->right = rana;
		anfibio->left = culebra;
		root = actual = anterior = ave;
	} else
		throw "Ya no se pueden agregar mas animales";
}

bool MundoAnimales::insertarNuevo(std::string caracteristica, std::string animal) {
	NODOPTR carac = crearNodo(caracteristica);
	NODOPTR anim = crearNodo(animal);
	if (carac && anim) {
		carac->left = anterior->right;
		carac->right = anim;
		anterior->right = carac;
		return true;
	}
	else
		return false;
}
void MundoAnimales::reiniciar() {
	actual = anterior = root;
	terminoJuego = false;
}

bool MundoAnimales::existePalabra(std::string palabra) {
	return existePalabra(palabra, root);
}

bool MundoAnimales::existePalabra(std::string palabra, NODOPTR actual) {
	if (actual == nullptr)
		return false;

	if (actual->elemento == palabra)
		return true;
	else
		return existePalabra(palabra, actual->left) || existePalabra(palabra, actual->right);
}


bool MundoAnimales::moverCaracteristica(unsigned int posActual, unsigned int posNueva, int metodo) {
	
}

bool MundoAnimales::moverCaracteristicaArriba(NODOPTR inicio, NODOPTR final) {
	
}

bool MundoAnimales::moverCaracteristicaAbajo(NODOPTR incio, NODOPTR final) {
	
	return false;
}

bool MundoAnimales::finDelJuego() {
	return terminoJuego;
}
std::string MundoAnimales::adivinar(char opc = ' ') {
	std::string valor = "";
	if (actual) {
	//Evita que cuando es una hoja, se haga actual null, por un exceso de llamadas externas cuando el juego ya ha terminado.
		if (actual->left && actual->right) {//Segun la logica del proyecto un nodo no hoja siempre tiene dos hijos.
			if (opc == 'S') {
				anterior = actual;
				actual = actual->right;
			}
			if (opc == 'N') {
				anterior = actual;
				actual = actual->left;
			}
		}
		if(!actual->left && !actual->right) {
			terminoJuego = true;
		}
		valor = actual->elemento;
	}
	return valor;
}


NODOPTR obtenerCaracteristicaGeneral(unsigned int pos) {
	return nullptr;
}

///<summary> Crea un nuevo nodo, siempre y cuando haya memoria disponible.</summary>
///<returns>Retorna un nuevo nodo, o retorna null si no hay memoria </returns>
NODOPTR MundoAnimales::crearNodo(std::string nuevo) {
	NODOPTR nuevoNodo;
	try{
		nuevoNodo = new nodo;
		nuevoNodo->elemento = nuevo;
		nuevoNodo->left = nuevoNodo->right = nullptr;
		return nuevoNodo;
	}catch (std::bad_alloc exception){
		return nullptr;
	}
}