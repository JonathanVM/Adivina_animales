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


///<summary>
/// metodo = true => moverCaracteristicaArriba
/// metodo = false => moverCaracteristicaAbajo
///</summary>
bool MundoAnimales::moverCaracteristica(unsigned int posActual, unsigned int posNueva, bool metodo) {
	/*if (posActual > 1)
		posActual--;
	if (posNueva > 1)
		posNueva--;
	NODOPTR aux = obtenerCaracteristicaGeneral(posActual);
	NODOPTR aux2 = obtenerCaracteristicaGeneral(posNueva);
	if (aux && aux2) {
		if (metodo)
			return moverCaracteristicaArriba(aux, aux2);
		return moverCaracteristicaAbajo(aux, aux2);
	}
	return false;*/
	return false;
}

bool MundoAnimales::moverCaracteristicaArriba(unsigned int posActual, unsigned int posNueva) {
	NODOPTR inicio, destino, aux;
	NODOPTR inicio = obtenerCaracteristicaGeneral(posActual-1);
	if(posNueva > 1)
		NODOPTR destino = obtenerCaracteristicaGeneral(posNueva-1);
	else
		NODOPTR destino = obtenerCaracteristicaGeneral(posNueva);
	
	if (!inicio || !destino)
		return false;

	aux = inicio->right;
	inicio->right = aux->right;
	if (posNueva != 1) {
		aux->right = destino->right;
		destino->right = aux;
	}
	else {
		root = aux;
		aux->right = destino;
	}
	return true;
}

bool MundoAnimales::moverCaracteristicaAbajo(unsigned int posActual, unsigned int posNueva) {
	NODOPTR inicio, destino, aux;
	if (posActual > 1) {
		NODOPTR inicio = obtenerCaracteristicaGeneral(posActual-1);
	} else
		NODOPTR inicio = obtenerCaracteristicaGeneral(posActual);
	NODOPTR destino = obtenerCaracteristicaGeneral(posNueva);

	if (!inicio || !destino)
		return false;
	if (posActual != 1) {
		aux = inicio->right;
		inicio->right = aux->right;
	}
	else {
		aux = root;
		root = inicio->left;
	}
	aux->right = destino->right;
	destino->right = aux;
	return true;
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


NODOPTR MundoAnimales::obtenerCaracteristicaGeneral(unsigned int pos) {
	if (root) {
		actual = root;
		int cont = 1;
		while (cont != pos) {
			actual = actual->left;
			cont++;
		}
		return actual;
	}
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