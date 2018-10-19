#include "interfaz.h"

Interfaz::Interfaz() {
	control = new Control();
}
Interfaz::~Interfaz() {
	delete control;
}

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

void Interfaz::imprimirTitulo() {
	std::cout << "\n\n" <<
		MARGEN << "--------------------------------------------------------------\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|                  EL MUNDO DE LOS ANIMALES                  |\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "--------------------------------------------------------------\n\n";
}


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
				resultado(adivinar());
				control->reiniciar();
				nuevaOpcion = volverJuego("jugar    ");
				if (nuevaOpcion != "1") {
					opcion = nuevaOpcion;
					break;
				}
			}
		}
	} while (opcion != "3");
}

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
		if (pregunta == "Si") {
			respuesta = 'S';
			correcto = true;
		}
		else if (pregunta == "No") {
			respuesta = 'N';
			correcto = true;
		}
		else
			correcto = false;
	}
	return (respuesta == 'S');
}

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

void Interfaz::reordenar() {

	system("cls");
	imprimirTitulo();
	std::string nivelActual, nivelNuevo;
	int nivelA, nivelN;

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
