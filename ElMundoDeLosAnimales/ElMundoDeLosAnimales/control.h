#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>

class Control {
private:

public:
	Control();
	~Control();
	void jugar(std::string);
	void agregar(std::string, std::string);
	void reiniciar();
	void terminar();
	void mover(unsigned int, unsigned int);
	
};

#endif // !CONTROL_H

