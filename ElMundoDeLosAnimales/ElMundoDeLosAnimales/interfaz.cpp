#include "interfaz.h"

///<summary></summary>
///<returns></returns>
Interfaz::Interfaz() {
	control = new Control();
}

///<summary></summary>
///<returns></returns>
Interfaz::~Interfaz() {
	delete control;
}

///<summary></summary>
///<returns></returns>
void Interfaz::menu() {
	std::cout << "\n\n" <<
		MARGEN << "--------------------------------------------------------------\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|                  EL MUNDO DE LOS ANIMALES                  |\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|------------------------------------------------------------|\n" <<
		MARGEN << "|                                                            |\n" << 
		MARGEN << "|     1. Adivinar animal                                     |\n" <<
		MARGEN << "|     2. Reordenar carteristica                              |\n" <<
		MARGEN << "|     3. Salir                                               |\n" << 
		MARGEN << "|                                                            |\n" <<
		MARGEN << "--------------------------------------------------------------\n\n" <<
		MARGEN << "      Digite una opcion: ";
}

///<summary></summary>
///<returns></returns>
void Interfaz::imprimirTitulo() {
	std::cout << "\n\n" <<
		MARGEN << "--------------------------------------------------------------\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|                  EL MUNDO DE LOS ANIMALES                  |\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "--------------------------------------------------------------\n\n";
}

///<summary></summary>
///<returns></returns>
void Interfaz::juego() {
	std::string opcion = "", nuevaOpcion = "";

	do {
		system("cls");
		menu();
		std::cin >> opcion;
		if (opcion == "2") {
			nuevaOpcion = "1";
			while (nuevaOpcion == "1") {
				reordenar();
				nuevaOpcion = volverJuego("modificar");
				if (nuevaOpcion != "1") {
					opcion = nuevaOpcion;
					break;
				}
			}
		}
		else {
			while (opcion == "1") {
				control->reiniciar();
				resultado(adivinar());
				nuevaOpcion = volverJuego("jugar    ");
				if (nuevaOpcion != "1") {
					opcion = nuevaOpcion;
					break;
				}
			}
		}
	} while (opcion != "3");
}

///<summary></summary>
///<returns></returns>
bool Interfaz::adivinar() {
	char respuesta = ' ';
	std::string pregunta, stringActual;
	bool salir = false, correcto = true;

	system("cls");
	imprimirTitulo();

	while (!salir || !correcto) {
		if (correcto) {
			stringActual = control->siguientePalabra(respuesta);
			salir = control->finDelJuego();
		}
		std::cout << "\n" << MARGEN << "      Esta pensando en \"" << stringActual << "\" (Si/No)?: ";
		std::cin >> pregunta;
		if (respuestaAceptada(pregunta, "Si")) {
			respuesta = 'S';
			correcto = true;
		}
		else if (respuestaAceptada(pregunta, "No")) {
			respuesta = 'N';
			correcto = true;
		}
		else
			correcto = false;
	}
	return (respuesta == 'S');
}

///<summary></summary>
///<returns></returns>
void Interfaz::resultado(bool result) {
	if (result) {
		std::cout << "\n\n" <<
			MARGEN << "--------------------------------------------------------------\n" <<
			MARGEN << "|                          YO GANE!                          |\n" <<
			MARGEN << "--------------------------------------------------------------\n\n";
	}
	else {
		std::string nombre, caracteristica;
		std::cout << "\n\n" <<
			MARGEN << "--------------------------------------------------------------\n" <<
			MARGEN << "|                         HE PERDIDO!                        |\n" <<
			MARGEN << "--------------------------------------------------------------\n\n";
		std::cout << MARGEN << "      Agreguemos el animal en que pensabas\n\n";
		std::cout << MARGEN << "      Digite el nombre del animal: ";
		std::cin >> nombre;
		std::cout << "\n" << MARGEN << "      Mencione una caracteristica relevante: ";
		std::cin >> caracteristica;
		std::cout << "\n\n";
		if (control->agregar(caracteristica, nombre))
			std::cout << MARGEN << "      Agregado correctamente, hasta la proxima\n\n";
		else 
			std::cout << MARGEN << "      No se agrego, por que la caracteristica y/o \n" << MARGEN << "animal ya existe\n\n";
	}
}

///<summary></summary>
///<returns></returns>
std::string Interfaz::volverJuego(std::string mensaje) {
	std::string opcion;
	std::cout << "\n" <<
		MARGEN << "--------------------------------------------------------------\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|     1. Volver a " + mensaje + "                                  |\n" <<
		MARGEN << "|     2. Volver al menu                                      |\n" <<
		MARGEN << "|     3. Salir                                               |\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "--------------------------------------------------------------\n\n" <<
		MARGEN << "      Digite una opcion: ";
	
	std::cin >> opcion;
	std::cout << "\n";
	while (opcion != "1" && opcion != "2" && opcion != "3") {
		std::cout << MARGEN << "      Digite una opcion valida: ";
		std::cin >> opcion;
		std::cout << "\n";
	}
	return opcion;
}

///<summary></summary>
///<returns></returns>
void Interfaz::reordenar() {

	system("cls");
	imprimirTitulo();
	std::string nivelActual, nivelNuevo;
	int nivelA, nivelN;

	control->imprimirArbol();

	std::cout << MARGEN << "      Digite el nivel de la caracteristica general a mover: ";
	std::cin >> nivelActual;

	while (nivelActual != "1" && nivelActual != "2" && nivelActual != "3" && 
			nivelActual != "4" && nivelActual != "5" && nivelActual != "6") {
		std::cout << "\n" << MARGEN << "      Digite un nivel valido: ";
		std::cin >> nivelActual;
	}
	nivelA = std::stoi(nivelActual);

	std::cout << "\n" << MARGEN << "      Digite el nivel de la caracteristica general de destino: ";
	std::cin >> nivelNuevo;

	while (nivelNuevo != "1" && nivelNuevo != "2" && nivelNuevo != "3" &&
		nivelNuevo != "4" && nivelNuevo != "5" && nivelNuevo != "6") {
		std::cout << "\n" << MARGEN << "      Digite un nivel valido: ";
		std::cin >> nivelNuevo;
	}

	nivelN = std::stoi(nivelNuevo);

	try {
		control->mover(nivelA, nivelN);
		std::cout << MARGEN << "      Se realizo la accion satisfactoriamente";
	}catch (const char* error) {
		std::cout << MARGEN << "      Error: " << error << "\n";
	}
}

///<summary></summary>
///<returns></returns>
bool Interfaz::respuestaAceptada(std::string cadena, std::string ver) {
	if (ver == "Si") {
		if (cadena == "si" || cadena == "Si" || cadena == "sI" || cadena == "SI") {
			return true;
		}
		return false;
	}
	else if(ver == "No"){
		if (cadena == "No" || cadena == "NO" || cadena == "nO" || cadena == "no") {
			return true;
		}
		return false;
	}
	return false;
}