#ifndef ARBOLBIN_H
#define ARBOLBIN_H

#include <iostream>
#include <string>

struct nodo {
	std::string elemento;
	struct nodo* left;
	struct nodo* right;
};
typedef struct nodo NODO;
typedef struct nodo* NODOPTR;

class Arbol {
public:
	Arbol();
	~Arbol();
	void borrarArbol(NODOPTR);
	void imprimeArbol(NODOPTR);
private:
	void print(NODOPTR, std::string, bool);
};

#endif