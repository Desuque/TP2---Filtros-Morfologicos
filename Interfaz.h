#ifndef INTERFAZ_H_
#define INTERFAZ_H_

#include "Imagen.h"
#include "Filtro.h"
#include <string.h>
#include <iostream>
#include <string>

class Interfaz {
private:
	std::string str_img;
	int hilos;

public:
	Interfaz();
	void leerImagen();
	int procesarImagen(int argc, char* argv[]);
	virtual ~Interfaz();

private:
	void setHilos(int hilos);
	Filtro* getFiltro(std::string tipo_filtro, Imagen* imagenFiltro);
	void aplicarFiltros(int argc, char *argv[], Imagen *imagen);
	void obtenerImagen(std::string cadena, Imagen *imagen);
	void mostrarImagen(Imagen *imagen);
	int getFilasAProcesarPorHilo(int altura, int hilos);
	void filtrar(std::string tipo_filtro, std::string patron, Imagen *imagen);
};

#endif
