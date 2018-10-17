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
//                PROTOTIPOS DE FUNCIÓN                      ##   
//#############################################################
static int profundidad(NODOPTR);
static void recorridoPreOrden(NODOPTR);
static void recorridoEnOrden(NODOPTR);
static void recorridoPosOrden(NODOPTR);
static void levelOrderTraversalRecursivo(NODOPTR);
static void levelOrder(NODOPTR, int);
static void levelOrderTraversalIterativo(NODOPTR);
static void borrarArbol(NODOPTR);
static NODOPTR buscarNodo(NODOPTR, std::string);
//#############################################################

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Calcula la profundidad (altura) del árbol. Retorna el valor de la profundidad (Depth)
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
// Imprime el recorrido del árbol Pre Orden
void recorridoPreOrden(NODOPTR actual) {
	if (actual != nullptr) {
		std::cout << actual->elemento << " ";
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del árbol En Orden
void recorridoEnOrden(NODOPTR actual) {
	if (actual != nullptr) {
		recorridoPreOrden(actual->left);
		std::cout << actual->elemento << " ";
		recorridoPreOrden(actual->right);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del árbol Pos Orden
void recorridoPosOrden(NODOPTR actual) {
	if (actual != nullptr) {
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
		std::cout << actual->elemento << " ";
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// WRAPPER - Imprime el recorrido del árbol en Level-Order (Breadth-first search) RECURSIVO
void levelOrderTraversalRecursivo(NODOPTR actual) {
	int niveles = profundidad(actual) + 1;
	for (int i = 1; i <= niveles; ++i)
		levelOrder(actual, i);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Auxiliar para el recorrido del árbol en Level-Order 
void levelOrder(NODOPTR actual, int n) {
	if (n == 1)
		std::cout << actual->elemento << " ";
	else {
		levelOrder(actual->left, n - 1);
		levelOrder(actual->right, n - 1);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Imprime el recorrido del árbol en Level-Order (Breadth-first search) ITERATIVO
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
// Elimina el árbol completo, nodo por nodo. Utiliza un recorrido Pos Orden para tal fin.
void borrarArbol(NODOPTR actual) {
	if (actual != nullptr) {
		borrarArbol(actual->left);
		borrarArbol(actual->right);
		delete actual;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Busca el nodo que contiene el elemento dado por parámetro. Retorna un apuntador al nodo encontrado o
// NULL si no lo encontró.
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

#endif