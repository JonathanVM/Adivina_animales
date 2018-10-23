﻿#ifndef ARBOLBIN_H
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
static void borrarArbol(NODOPTR);
static NODOPTR buscarNodo(NODOPTR, std::string);
static void imprimeArbol(NODOPTR);
static void print(NODOPTR, std::string, bool);
//#############################################################

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

///////////////////////////////////////////////////////////////////
///////////Imprimir Arbol, grafico////////////////////////////////


///<summary></summary>
///<returns></returns>
void imprimeArbol(NODOPTR p){
	std::string guion, signo;
	guion = (char)196;
	signo = (char)195;
	std::cout << "\t\t\t " << static_cast<char>(192) + guion + guion + guion + " Root\n";
	std::cout << "\t\t\t\t" << signo + guion + guion + guion + " Right\n";
	std::cout << "\t\t\t\t" << static_cast<char>(192) + guion + guion + guion + " Left\n\n";
	print(p, " ", true);
}

void print(NODOPTR node, std::string indent, bool is_tail) {
	std::string guion, signo;
	guion = (char)196;
	std::cout << "\t\t\t" << indent << (is_tail ? static_cast<char>(192) + guion + guion + guion + " ": static_cast<char>(195) + guion + guion + guion + " ");
	if (node == nullptr) {
		std::cout << "*\n";
		return;
	}
	std::cout << node->elemento << "\n";
	if (node->left != nullptr || node->right != nullptr) {
		signo = (char)179;
		indent.append(is_tail ? "      " : signo  + "     ");
		print(node->right, indent, false);
		print(node->left, indent, true);
	}
}

#endif