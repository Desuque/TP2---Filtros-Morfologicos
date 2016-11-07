#include "Erosion.h"

Erosion::Erosion(Imagen *imagen) : Filtro(imagen) {
}

char Erosion::aplicarFiltro(int coincidencias, int encendidos) {
	if (coincidencias == encendidos) {
		return '#';
	}
	return '.';
}

Erosion::~Erosion() {
}

