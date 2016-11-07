
#ifndef DILATACION_H_
#define DILATACION_H_

#include "Filtro.h"

class Dilatacion : public Filtro {
public:
	explicit Dilatacion(Imagen *imagen);
	virtual ~Dilatacion();

private:
	virtual char aplicarFiltro(int coincidencias, int encendidos);
};

#endif /* DILATACION_H_ */
