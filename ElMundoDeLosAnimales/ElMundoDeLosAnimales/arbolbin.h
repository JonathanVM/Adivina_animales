#ifndef ARBOLBIN_H
#define ARBOLBIN_H

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>

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
static void getLine(const NODOPTR, int, std::vector<std::string>&);
static void postOrder(NODOPTR);
static void printRow(const NODOPTR, const int, int);
static int alturaArbol(NODOPTR);
//#############################################################

///////////////////////////////////////////////////////////////////////
///<summary>Calcula la profundidad (altura) del árbol. </summary>
///<returns>Retorna el valor de la profundidad (Depth) </returns>
int profundidad(NODOPTR actual) {
	if (actual == nullptr)
		return 0;
	int maxizq = profundidad(actual->left);
	int maxder = profundidad(actual->right);

	if (maxizq > maxder)
		return maxizq + 1;
	return maxder + 1;
}

///////////////////////////////////////////////////////////////////////
///<summary> Imprime el recorrido del árbol Pre Orden </summary>
void recorridoPreOrden(NODOPTR actual) {
	if (actual != nullptr) {
		std::cout << actual->elemento << " ";
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
	}
}

///////////////////////////////////////////////////////////////////////
///<summary> Imprime el recorrido del árbol En Orden </summary>
void recorridoEnOrden(NODOPTR actual) {
	if (actual != nullptr) {
		recorridoPreOrden(actual->left);
		std::cout << actual->elemento << " ";
		recorridoPreOrden(actual->right);
	}
}

///////////////////////////////////////////////////////////////////////
///<summary> Imprime el recorrido del árbol Pos Orden </summary>
void recorridoPosOrden(NODOPTR actual) {
	if (actual != nullptr) {
		recorridoPreOrden(actual->left);
		recorridoPreOrden(actual->right);
		std::cout << actual->elemento << " ";
	}
}

///////////////////////////////////////////////////////////////////////
///<summary> WRAPPER - Imprime el recorrido del árbol en Level-Order (Breadth-first search) RECURSIVO </summary>
void levelOrderTraversalRecursivo(NODOPTR actual) {
	int niveles = profundidad(actual) + 1;
	for (int i = 1; i <= niveles; ++i)
		levelOrder(actual, i);
}

///////////////////////////////////////////////////////////////////////
/// <summary> Auxiliar para el recorrido del árbol en Level-Order </summary>
void levelOrder(NODOPTR actual, int n) {
	if (n == 1)
		std::cout << actual->elemento << " ";
	else {
		levelOrder(actual->left, n - 1);
		levelOrder(actual->right, n - 1);
	}
}

///////////////////////////////////////////////////////////////////////
/// <summary> Imprime el recorrido del árbol en Level-Order (Breadth-first search) ITERATIVO </summary>
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

///////////////////////////////////////////////////////////////////////
/// <summary> Elimina el árbol completo, nodo por nodo. Utiliza un recorrido Pos Orden para tal fin. </summary>
void borrarArbol(NODOPTR actual) {
	if (actual != nullptr) {
		borrarArbol(actual->left);
		borrarArbol(actual->right);
		delete actual;
	}
}

///////////////////////////////////////////////////////////////////////
/// <summary> Busca el nodo que contiene el elemento dado por parámetro. </summary> 
/// <returns> Retorna un apuntador al nodo encontrado o
/// NULL si no lo encontró. </returns>
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

void postOrder(NODOPTR p){
	int height = alturaArbol(p) * 2;
	for (int i = 0; i < height; i++) {
		printRow(p, height, i);
	}
}

void printRow(const NODOPTR p, const int height, int depth){
	std::vector<std::string> vec;
	getLine(p, depth, vec);
	std::cout << std::setw((height - depth) * 3); // scale setw with depth
	bool toggle = true; // start with left
	if (vec.size() > 1) {
		for (std::string v : vec) {
			if (v != " ") {
				if (toggle)
					std::cout << "      /" << "  ";
				else
					std::cout << "\\" << " ";
			}
			toggle = !toggle;
		}
		std::cout << "\n";
		std::cout << std::setw((height - depth) * 3);
	}
	for (std::string v : vec) {
		if (v != " ")
			std::cout << v << " ";
	}
	std::cout << "\n";
}

void getLine(const NODOPTR root, int depth, std::vector<std::string>& vals){
	if (depth <= 0 && root != nullptr) {
		vals.push_back(root->elemento);
		return;
	}
	if (root->left != nullptr)
		getLine(root->left, depth - 1, vals);
	else if (depth - 1 <= 0)
		vals.push_back(" ");
	if (root->right != nullptr)
		getLine(root->right, depth - 1, vals);
	else if (depth - 1 <= 0)
		vals.push_back(" ");
}

int alturaArbol(NODOPTR p) {
	if (p == nullptr)
		return 0;
	else{
		int lDepth = alturaArbol(p->left);
		int rDepth = alturaArbol(p->right);
		if (lDepth > rDepth)
			return(lDepth + 1);
		else 
			return(rDepth + 1);
	}
}

#endif