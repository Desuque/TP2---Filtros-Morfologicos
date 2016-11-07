#include "Dilatacion.h"

Dilatacion::Dilatacion(Imagen *imagen) : Filtro(imagen) {
}

char Dilatacion::aplicarFiltro(int coincidencias, int encendidos) {
	if (coincidencias > 0 && coincidencias <= encendidos) {
		return '#';
	}
	return '.';
}

Dilatacion::~Dilatacion() {
}

