
#ifndef EROSION_H_
#define EROSION_H_

#include "Filtro.h"

class Erosion : public Filtro {
public:
	explicit Erosion(Imagen *imagen);
	virtual ~Erosion();

private:
	virtual char aplicarFiltro(int coincidencias, int encendidos);
};

#endif /* EROSION_H_ */
