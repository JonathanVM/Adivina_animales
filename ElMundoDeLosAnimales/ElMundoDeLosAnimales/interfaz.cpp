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

void Interfaz::juego() {
	std::string opcion;

	do {
		system("cls");
		menu();
		std::cin >> opcion;
		if (opcion == "1") {
			resultado(adivinar());
			control->reiniciar();
			volverJuego();
		}
		else if (opcion == "2") {
			//modificar
		}
	} while (opcion != "3");
}

bool Interfaz::adivinar() {
	char respuesta = ' ';
	std::string pregunta, stringActual;
	bool salir = false, correcto = true;

	system("cls");
	std::cout << "\n\n" <<
		MARGEN << "--------------------------------------------------------------\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|                  EL MUNDO DE LOS ANIMALES                  |\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "--------------------------------------------------------------\n\n";

	while (true) {
		salir = control->finDelJuego();
		if (correcto) {
			stringActual = control->obtenerActual(respuesta);
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
		else {
			correcto = false;
		}

		if (salir && correcto) {
			return (respuesta == 'S');
		}
	}
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
		control->agregar(nombre,caracteristica);
		std::cout << MARGEN << "      Agregado correctamente, hasta la proxima\n\n";
		control->reiniciar();
		control->terminar();
	}
}

void Interfaz::volverJuego() {
	std::string opcion;
	std::cout << MARGEN << "      1. Volver a jugar\n\n";
	std::cout << MARGEN << "      2. Volver al menu\n\n";
	std::cout << MARGEN << "      3. Salir\n\n";
	std::cout << MARGEN << "      Digite una opcion: ";
	std::cin >> opcion;
	if (opcion == "1") {
		juego();
	}
	else if (opcion == "2") {
		menu();
	}
	else if (opcion == "3") {
		system("exit");
	}
}