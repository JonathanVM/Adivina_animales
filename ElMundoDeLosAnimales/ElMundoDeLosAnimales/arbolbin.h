#ifndef ARBOLBIN_H
#define ARBOLBIN_H

#include <fstream>
#include <iostream>
#include <queue>
#include <string>

struct nodo {
	std::string elemento;
	struct nodo* left;
	struct nodo* right;
};

typedef struct nodo NODO;
typedef struct nodo* NODOPTR;

//#############################################################
//                PROTOTIPOS DE FUNCI�N                      ##   
//#############################################################
NODOPTR cargarArbolDeArchivo(char);
NODOPTR insertaNodoDesdeArchivo(std::ifstream&, char);
int profundidad(NODOPTR);
void recorridoPreOrden(NODOPTR);
void recorridoEnOrden(NODOPTR);
void recorridoPosOrden(NODOPTR);
void levelOrderTraversalRecursivo(NODOPTR);
void levelOrder(NODOPTR, int);
void levelOrderTraversalIterativo(NODOPTR);
void insertarNodo(NODOPTR*, std::string);
void borrarArbol(NODOPTR);
NODOPTR buscarNodo(NODOPTR, std::string);
bool borrarNodoChar(NODOPTR*, char);
//#############################################################


///////////////////////////////////////////////////////////////////////////////////////////////////////
// WRAPPER - Inserta nodos en el �rbol, a partir de un archivo. Se crea un �rbol de acuerdo al tipo de
// datos deseado. Si la funci�n se llama con la letra 'c', se crea un �rbol de char. Si la funci�n se
// llama con la letra 'i', se crea un �rbol de int.
// Retorna un apuntador a la ra�z del �rbol
NODOPTR cargarArbolDeArchivo(char tipo) {
	std::string filename;

	if (tipo == 'c')
		filename = "arbolchar.txt";
	else if (tipo == 'i')
		filename = "arbolint.txt";
	else
		return nullptr;

	std::ifstream handle(filename, std::ios::in);
	if (!handle) {
		return nullptr;
	}

	NODOPTR tmp = insertaNodoDesdeArchivo(handle, tipo);
	handle.close();
	return tmp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Funci�n Auxiliar para crear un �rbol binario tipo char desde el archivo manejado por "handle"
// La funci�n retorna un apuntador de tipo NODOPTR a la ra�z del �rbol
NODOPTR insertaNodoDesdeArchivo(std::ifstream& handle, char tipo) {
	char c;
	int x;
	NODOPTR tmp;

	switch (tipo) {
	case 'c':
		handle.get(c);
		if (c == '$')
			return nullptr;
		tmp = new NODO;
		tmp->elemento = c;
		break;
	case 'i':
		handle >> x;
		if (x == -1)
			return nullptr;
		tmp = new NODO;
		tmp->elemento = x;
		break;
	default:
		tmp = nullptr;
		break;
	}
	tmp->left = insertaNodoDesdeArchivo(handle, tipo);
	tmp->right = insertaNodoDesdeArchivo(handle, tipo);
	return tmp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcula la profundidad (altura) del �rbol. Retorna el valor de la profundidad (Depth)
int profundidad(NODOPTR actual) {
	if (actual == nullptr)
		return 0;
	int maxizq = profundidad(actual->left);
	int maxder = profundidad(actual->right);

	if (maxizq > maxder)
		return maxizq + 1;
	return maxder + 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del �rbol Pre Orden
void recorridoPreOrden(NODOPTR actual) {
	if (actual != nullptr) {
		std::cout << actual->elemento << " ";
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del �rbol En Orden
void recorridoEnOrden(NODOPTR actual) {
	if (actual != nullptr) {
		recorridoPreOrden(actual->left);
		std::cout << actual->elemento << " ";
		recorridoPreOrden(actual->right);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del �rbol Pos Orden
void recorridoPosOrden(NODOPTR actual) {
	if (actual != nullptr) {
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
		std::cout << actual->elemento << " ";
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// WRAPPER - Imprime el recorrido del �rbol en Level-Order (Breadth-first search) RECURSIVO
void levelOrderTraversalRecursivo(NODOPTR actual) {
	int niveles = profundidad(actual) + 1;
	for (int i = 1; i <= niveles; ++i)
		levelOrder(actual, i);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Auxiliar para el recorrido del �rbol en Level-Order 
void levelOrder(NODOPTR actual, int n) {
	if (n == 1)
		std::cout << actual->elemento << " ";
	else {
		levelOrder(actual->left, n - 1);
		levelOrder(actual->right, n - 1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del �rbol en Level-Order (Breadth-first search) ITERATIVO
void levelOrderTraversalIterativo(NODOPTR actual) {
	std::queue<NODOPTR> Cola;
	NODOPTR tmp;

	if (!actual)
		return;

	Cola.push(actual);
	while (!Cola.empty()) {
		tmp = Cola.front();
		Cola.pop();
		std::cout << tmp->elemento << " ";
		if (tmp->left)
			Cola.push(tmp->left);
		if (tmp->right)
			Cola.push(tmp->right);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Inserta un nuevo nodo en el �rbol. Encuentra el primer
// espacio disponible en un nivel del �rbol
void insertarNodo(NODOPTR* actual, std::string dato) {
	std::queue<NODOPTR> Cola;
	NODOPTR tmp;
	NODOPTR nuevo = new NODO;
	nuevo->elemento = dato;
	nuevo->left = nullptr;
	nuevo->right = nullptr;

	if (!actual) {
		*actual = nuevo;
		return;
	}

	Cola.push(*actual);
	while (!Cola.empty()) {
		tmp = Cola.front();
		Cola.pop();
		if (tmp->left)
			Cola.push(tmp);
		else {
			tmp->left = nuevo;
			return;
		}
		if (tmp->right)
			Cola.push(tmp);
		else {
			tmp->right = nuevo;
			return;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Elimina el �rbol completo, nodo por nodo. Utiliza un recorrido Pos Orden para tal fin.
void borrarArbol(NODOPTR actual) {
	if (actual != nullptr) {
		borrarArbol(actual->left);
		borrarArbol(actual->right);
		delete actual;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Busca el nodo que contiene el elemento dado por par�metro. Retorna un apuntador al nodo encontrado o
// NULL si no lo encontr�.
NODOPTR buscarNodo(NODOPTR actual, std::string dato) {
	if (actual) {
		if (actual->elemento == dato)
			return actual;
		NODOPTR aux;
		if ((aux = buscarNodo(actual->right, dato)))
			return aux;
		if ((aux = buscarNodo(actual->left, dato)))
			return aux;
	}
	return nullptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Elimina el nodo que contiene el dato dado por el usuario. Retorna TRUE si el nodo fue borrado con �xito
// y FALSE en caso contrario. Versi�n CHAR
bool borrarNodoChar(NODOPTR* actual, char dato) {
	return false;
}
#endif