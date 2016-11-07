#ifndef FILTRO_H_
#define FILTRO_H_

#include <string>
#include <stdbool.h>
#include "Imagen.h"
#include "Thread.h"

class Filtro : public Thread {
private:
	Imagen filtro;
	int inicio;
	int fin;
	Imagen* imagen;
	Imagen* original;
public:
	explicit Filtro(Imagen *imagen);
	virtual void run();
	void setParametros(int inicio, int fin, Imagen* imagen, Imagen* original);
	virtual ~Filtro();
private:
	virtual char aplicarFiltro(int coincidencias, int encendidos) = 0;
	int calcularEncendidos();
	char procesarFiltro(Imagen *imagen, int pix_f, int pix_c);
	bool posicionValida(Imagen *imagen, int x, int y);
	bool compararBit(char a, char b);
	int getCentro();
};

#endif
