#include <iostream>
#include "Interfaz.h"

int main(int argc, char *argv[]) {
	Interfaz interfaz;
	interfaz.leerImagen();
	interfaz.procesarImagen(argc, argv);

	return 0;
}
