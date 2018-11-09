#include "interfaz.h"

///<summary>Declaracion de la clase Interfaz</summary>
///<remarks>Inicializa el atributo de control. </remarks>
Interfaz::Interfaz() {
	control = new Control();
}

///<summary>Destructor de la clase interfaz.</summary>
Interfaz::~Interfaz() {
	delete control;
}

///<summary>Metodo que contiene el encabezado del inicio del juego.
/// Este muestra las opciones que el usuario puede usar en un inicio.</summary>
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

///<summary>Imprime solo el titulo de encabezado para usar en las otras opciones del juego, como adivinar o reordenar.</summary>
void Interfaz::imprimirTitulo() {
	std::cout << "\n\n" <<
		MARGEN << "--------------------------------------------------------------\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "|                  EL MUNDO DE LOS ANIMALES                  |\n" <<
		MARGEN << "|                                                            |\n" <<
		MARGEN << "--------------------------------------------------------------\n\n";
}

///<summary>Metodo principal del juego, que contiene todas las opciones disponibles.
/// es un metodo iterativo, con el que el usuario va interactuar desde una primera vista.</summary>
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
	control->guardarArbol();
}

///<summary>Metodo que se encarga de ir adivinando el animal en el que esta pensando el usuario.</summary>
///<returns>Retorna true si el usuario adivina o false si el usuario no adivino.</returns>
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

///<summary>Metodo que se encarga de decirle al usuario si gano el juego o perdio. En caso de haber perdido, 
/// le pide al usuario que digite el animal en el que estaba pensando. 
///Y se le pide tambien digitar una caracteristica relevante que este posea. </summary>
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

///<summary>Metodo que sirve como un menu para el usuario. Una vez ejecutada una accion se le muestra este menu. </summary>
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

///<summary>Metodo que muestra el arbol de manera grafica al usuario, este escoge de ahi los niveles que quiere mover.</summary>
void Interfaz::reordenar() {

	system("cls");
	imprimirTitulo();
	std::string nivelActual, nivelNuevo;
	int nivelA, nivelN;

	control->imprimirArbol();

	std::cout << "\n" << MARGEN << "      Digite el nivel de la caracteristica general a mover: ";
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

///<summary>Metodo que valida las diferentes opciones de respuesta de los menu que digita el usuario.</summary>
///<returns></returns>
bool Interfaz::respuestaAceptada(std::string cadena, std::string ver) {
	if (ver == "Si") {
		if (cadena == "si" || cadena == "Si" || cadena == "sI" || cadena == "SI" || cadena == "S" || cadena == "s") {
			return true;
		}
		return false;
	}
	else if(ver == "No"){
		if (cadena == "No" || cadena == "NO" || cadena == "nO" || cadena == "no" || cadena == "n" || cadena == "N") {
			return true;
		}
		return false;
	}
	return false;
}