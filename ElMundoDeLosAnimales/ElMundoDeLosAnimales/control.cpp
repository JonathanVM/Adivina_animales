#include "control.h"


///<summary>Constructor de la clase Control</summary>
///<remarks>Inicializa una instancia a la clase del modelo</remarks>
Control::Control() {
	mundoA = new MundoAnimales();
}

///<summary>Destructor de la clase Control</summary>
///<remarks>Destruye la instancia a la clase del modelo</remarks>
Control::~Control() {
	delete mundoA;
}

///<summary>Metodo que agrega una nueva caracteristica y un nuevo animal al arbol del sistema.</summary>
///<remarks>Este metodo recibe dos string, la nueva caracteristica y el nuevo animal.</remarks>
///<returns>Retorna <code>true</code> si los datos se agregaron correctamente.
///Retorna <code>false</code> si los datos no se agregaron correctamente.</returns>
bool Control::agregar(std::string caracteristica, std::string animal) {
	if (!mundoA->existePalabra(caracteristica)  && !mundoA->existePalabra(animal)) {
		return mundoA->insertarNuevo(caracteristica, animal);
	}
	return false;
}

///<summary>Metodo que devuelve algunos atributos a su estado inicial.</summary>
///<remarks>Como la persona puede jugar varias veces, cada vez que termina una partida(Por ejemplo), 
/// se limpiaran algunos atributos: el nodo actual o anterior que volveran a apuntar a root y el atributo 
///de que termino el juego volvera a false. </remarks>
void Control::reiniciar() {
	mundoA->reiniciar();
}

///<summary>Metodo en control que se encarga de subir y bajar caracteristicas relevantes del arbol.</summary>
///<remarks>Este metodo recibe dos parametros, el nivel actual en el que se encuentra la caracteristica y 
/// el nivel a donde se quiere mover dicha caracteristica. Si la posicion actual es menor a la nueva posicion 
/// esto quiere decir que la caracteristica se movera para arriba, y si la posicion actual es mayor a la nueva 
/// posicion entonces la caracteristica se movera para abajo.</remarks>
///<returns>Si ambas posiciones son iguales, el metodo lanzara una excepcion, y si las posiciones son menor o mayor
/// a las establecidas tambien lanzara una excepcion.</returns>
void Control::mover(unsigned int actual, unsigned int nueva) {
	if (actual  == nueva) {
		throw "No se pueden mover caracteristicas iguales";
	}
	else if((actual < 1 && actual > 6) || (nueva < 1 && nueva > 6)){
		throw "Los niveles de las caracteristicas generales van de 1 a 6";
	}
	else if (actual > nueva){
		mundoA->moverCaracteristica(actual, nueva, true);
	}
	else {
		mundoA->moverCaracteristica(actual, nueva, false);
	}
}

///<summary>Obtiene la palabra que sigue a la del arbol. Por donde el usuario va adivinandol </summary>
///<returns>Retorna un string con la palabra que sigue, segun la decision del usuario. 
/// Si dijo el usuario si. Avanza a la derecha del arbol, si dice que no, avanza por la izquierda ene l arbol. </returns>
std::string Control::siguientePalabra(char obtener) {
	return mundoA->adivinar(obtener);
}

///<summary>Metodo que facilita saber si la partida o juego actual, ya termino o aun no. </summary>
///<returns>Retorna <code>true</code> si el juego ya termino. Retorna <code>false</code> si el juego
/// aun no termina. </returns>
bool Control::finDelJuego() {
	return mundoA->finDelJuego();
}

///<summary>Metodo que se encarga de mostrar el arbol de forma grafica al usuario.</summary>
void Control:: imprimirArbol() {
	mundoA->imprimirArbol();
}

///<summary>Metodo que guarda en el archivo el estado actual del arbol. 
/// Sobreescribiendo el archivo que se encontraba anteriormente. </summary>
void Control::guardarArbol() {
	mundoA->guardarArchivo();
}
