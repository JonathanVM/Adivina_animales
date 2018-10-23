#include "arbol.h"


Arbol::Arbol() {
	
}

Arbol::~Arbol() {

}

///////////////////////////////////////////////////////////////////////
/// <summary> Elimina el árbol completo, nodo por nodo. Utiliza un recorrido Pos Orden para tal fin. </summary>
void Arbol::borrarArbol(NODOPTR actual) {
	if (actual != nullptr) {
		borrarArbol(actual->left);
		borrarArbol(actual->right);
		delete actual;
	}
}

///<summary>Armar arbol grafico</summary>
///<returns></returns>
void Arbol::imprimeArbol(NODOPTR p) {
	std::string guion, signo;
	guion = (char)196;
	signo = (char)195;
	std::cout << "\t\t\t " << static_cast<char>(192) + guion + guion + guion + " Root\n";
	std::cout << "\t\t\t\t" << signo + guion + guion + guion + " Right\n";
	std::cout << "\t\t\t\t" << static_cast<char>(192) + guion + guion + guion + " Left\n\n";
	print(p, " ", true);
}

void Arbol::print(NODOPTR node, std::string indent, bool is_tail) {
	std::string guion, signo;
	guion = (char)196;
	std::cout << "\t\t\t" << indent << (is_tail ? static_cast<char>(192) + guion + guion + guion + " " : static_cast<char>(195) + guion + guion + guion + " ");
	if (node == nullptr) {
		std::cout << "*\n";
		return;
	}
	std::cout << node->elemento << "\n";
	if (node->left != nullptr || node->right != nullptr) {
		signo = (char)179;
		indent.append(is_tail ? "      " : signo + "     ");
		print(node->right, indent, false);
		print(node->left, indent, true);
	}
}