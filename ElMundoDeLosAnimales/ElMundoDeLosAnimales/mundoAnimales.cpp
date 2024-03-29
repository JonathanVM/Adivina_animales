#include "mundoAnimales.h"

///<summary>Constructor de la clase mundo animales, inicializa los atributos</summary>
MundoAnimales::MundoAnimales() {
	root = actual = anterior = nullptr;
	terminoJuego = false;
	leerArchivo();
}

///<summary>Destructor de la clase MundoAnimales</summary>
MundoAnimales::~MundoAnimales() {
}

///<summary>Lee del archivo solo si existe y si no carga los valores por defecto</summary>
void MundoAnimales::leerArchivo() {
	std::ifstream archivo("arbol.txt");
	std::string derecha = "";
	armarArbolArhivo(nullptr, archivo, derecha, true);
	archivo.close();
}

///<summary>Arma el arbol con los datos provenientes del archivo.
///Se asume que un nodo no hoja siempre tiene dos hijos, en caso de que los datos del archivo no cumplieran con esto, 
///se cargaran los valores por defecto
///</summary>
void MundoAnimales::armarArbolArhivo(NODOPTR actual, 
	std::ifstream& archivo, std::string& derecha, bool seguir) {
	std::string cadena;
	
	getline(archivo, cadena);
	if (archivo.eof()) {
		seguir = false;
		derecha = "";
		return;
	}
	NODOPTR aux;
	if (cadena == "root" || cadena == "left" || cadena == "right") {
		if (!actual && cadena == "root") {
			getline(archivo, cadena);
			if (cadena != "root" && cadena != "left" && cadena != "right") {
				actual = root = crearNodo(cadena);
				if (!root) {
					borrarArbol(root);
					valoresPorDefecto();
				}
			}
			else {
				borrarArbol(root);
				valoresPorDefecto();
				return;
			}
			getline(archivo, cadena);
			if (cadena != "left" && cadena != "right") {
				borrarArbol(root);
				valoresPorDefecto();
				return;
			}
		}
		if (cadena == "left") {
			getline(archivo, cadena);
			if (cadena != "root" && cadena != "left" && cadena != "right") {
				aux = crearNodo(cadena);
				actual->left = aux;
				armarArbolArhivo(actual->left, archivo, derecha, seguir);
				if (derecha == "") {
					borrarArbol(root);
					valoresPorDefecto();
					return;
				}
				aux = crearNodo(derecha);
				actual->right = aux;
				derecha = "";
				armarArbolArhivo(actual->right, archivo, derecha, seguir);
			}
			else {
				borrarArbol(root);
				valoresPorDefecto();
				return;
			}
		}
		if (cadena == "right") {
			getline(archivo, cadena);
			if (cadena != "root" && cadena != "left" && cadena != "right") {
				derecha = cadena;
				return;
			}
			else {
				borrarArbol(root);
				valoresPorDefecto();
				return;
			}	
		}
	}
	else {
		borrarArbol(root);
		valoresPorDefecto();
		return;
	}
}

///<summary>Si no existe el archivo, lo crea y sino lo sobrescribe</summary>
void MundoAnimales::guardarArchivo() {
	std::ofstream archivo("arbol.txt");
	guardarArchivo(archivo, root, 0);
	archivo.close();
}

///<summary>Va guardando en el archivo dado por parametro linea por linea, identificando izquierda, derecha y la raiz</summary>
void MundoAnimales::guardarArchivo(std::ofstream& fs, NODOPTR actual, int esg) {
	if (actual != nullptr) {
		if (esg == 1) {
			fs << "left\n" << actual->elemento << "\n";
		}
		else if (esg == 2) {
			fs << "right\n" << actual->elemento << "\n";
		}
		else {
			fs << "root\n" << actual->elemento << "\n";
		}
		guardarArchivo(fs, actual->left, 1);
		guardarArchivo(fs, actual->right, 2);
	}
	return;
}

///<summary>En caso de no existir el archivo o no cumplir con un formato valido, se procede a utilizar este metodo.
///Este se encarga de cargar valores por defecto para iniciar a jugar.
///</summary>
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

///<summary>Error, si anterior no existe, eliminar memoria, igual si solo uno se creo, liberar la memoria del otro</summary>
///<returns>Retorna true si se insertaran las cosas exitosamente, Retorna false si no se agrego exitosamente.</returns>
bool MundoAnimales::insertarNuevo(std::string caracteristica, std::string animal) {
	NODOPTR carac = crearNodo(caracteristica);
	NODOPTR anim = crearNodo(animal);
	if (carac && anim && anterior) {
		carac->left = anterior->right;
		carac->right = anim;
		anterior->right = carac;
		return true;
	}
	else {
		if (carac)
			delete carac;
		if (anim)
			delete anim;
		return false;
	}
}

///<summary>Al terminar de jugar en la parte de adivinar una palabra, 
///y si la persona quiere volver a jugar, todos los valores tiene que ser resetados para un nuevo juego.</summary>
void MundoAnimales::reiniciar() {
	actual = anterior = root;
	terminoJuego = false;
}

///<summary>Antes de agregar un animal nuevo o una caracteristica nueva, primero se verifica si la palabra ya 
///existe en el arbol.</summary>
///<returns>Si la palabra existe retirna true, y si la palabra no existe retorna false.</returns>
bool MundoAnimales::existePalabra(std::string palabra) {
	return existePalabra(palabra, root);
}

///<summary>Metodo recursivo que recorre un arbol para encontrar una palabra.</summary>
///<returns>Si encuentra la palabra retorna true, si no encuentra la palabra retorna false.</returns>
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
/// Reordena el arbol por la caracteristica relevante en el arbol, ya sea mover el nodo de la caracteristica 
/// actual hacia arriba o hacia abajo. 
///</summary>
///<returns>Retorna true si la caracteristica se movio satisfactoriamente, retorna false si la 
/// caracteristica no se movio satisfactoriamente.</returns>
bool MundoAnimales::moverCaracteristica(unsigned int posActual, unsigned int posNueva, bool metodo) {
	NODOPTR inicio, destino;
	if (posActual > 1 || metodo)
		inicio = obtenerCaracteristicaGeneral(posActual - 1);
	else
		inicio = obtenerCaracteristicaGeneral(posActual);
	if (posNueva == 1 || !metodo)
		destino = obtenerCaracteristicaGeneral(posNueva);	
	else
		destino = obtenerCaracteristicaGeneral(posNueva - 1);
	if (metodo)
		return moverCaracteristicaArriba(inicio, destino, posNueva);
	return moverCaracteristicaAbajo(inicio, destino, posActual);
}


///<summary>Metodo mueve un nodo del arbol hacia abajo al de la posicion. Este metodo recibe 
/// el nodo que se quiere mover, y un nodo antes a la de la posicion nueva, tambien recibe una posicion 
/// nueva.</summary>
///<returns>Retorna true si la caracteristica se movio satisfactoriamente, retorna false si la 
/// caracteristica no se movio satisfactoriamente.</returns>
bool MundoAnimales::moverCaracteristicaArriba(NODOPTR inicio, NODOPTR destino, unsigned int posNueva) {
	NODOPTR aux;
	if (!inicio || !destino)
		return false;
	aux = inicio->left;
	inicio->left = aux->left;
	if (posNueva != 1) {
		aux->left = destino->left;
		destino->left = aux;
	}
	else {
		root = aux;
		aux->left = destino;
	}
	return true;
}

///<summary>Metodo mueve un nodo del arbol hacia abajo al de la posicion. Este metodo recibe 
/// el nodo que se quiere mover, y el nodo correspondiente a la posicion nueva, tambien recibe una posicion 
/// nueva.</summary>
///<returns>Retorna true si la caracteristica se movio satisfactoriamente, retorna false si la 
/// caracteristica no se movio satisfactoriamente.</returns>
bool MundoAnimales::moverCaracteristicaAbajo(NODOPTR inicio, NODOPTR destino, unsigned int posActual) {
	NODOPTR aux;
	if (!inicio || !destino)
		return false;
	if (posActual != 1) {
		aux = inicio->left;
		inicio->left = aux->left;
	}
	else {
		aux = inicio;
		root = aux->left;
	}
	aux->left = destino->left;
	destino->left = aux;
	return true;
}

///<summary>Metodo que facilita saber si la partida o juego actual, ya termino o aun no. </summary>
///<returns>Retorna <code>true</code> si el juego ya termino. Retorna <code>false</code> si el juego
/// aun no termina. </returns>
bool MundoAnimales::finDelJuego() {
	return terminoJuego;
}

///<summary>Obtiene la palabra que sigue a la del arbol. Por donde el usuario va adivinandol </summary>
///<returns>Retorna un string con la palabra que sigue, segun la decision del usuario. 
/// Si dijo el usuario si. Avanza a la derecha del arbol, si dice que no, avanza por la izquierda ene l arbol. </returns>
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

///<summary>Busca en el arbol una caracteristica relevante, correspondiente a la posicion 
/// que se le pasa. Esta posicion se asume que es un nivel.</summary>
///<returns>Retorna el nodo de la caracteristica relevante, con la posicion perspectiva.</returns>
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

///<summary>Metodo que se encarga de mostrar el arbol de forma grafica al usuario.</summary>
void MundoAnimales::imprimirArbol() {
	imprimeArbol(root);
}