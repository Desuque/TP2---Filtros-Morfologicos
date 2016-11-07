#include "Interfaz.h"
#include "Dilatacion.h"
#include "Erosion.h"
#include "Thread.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * Define el numero de argumento por el cual
 * ingresa el primer tipo de filtro
 */
#define ID_FILTRO 2
#define MIN_PARAMETROS 3
#define MIN_FILA_POR_HILO 1

Interfaz::Interfaz() {
	this->hilos = 0;
}

void Interfaz::leerImagen() {
	std::string str;
	std::string space = " ";
	std::string buffer;
	while(!std::cin.eof()) {
		std::getline(std::cin, str);
		buffer+=str + space;
	}
	this->str_img = buffer;
}

void Interfaz::setHilos(int hilos) {
	this->hilos = hilos;
}

int Interfaz::procesarImagen(int argc, char* argv[]) {
	if (argc > MIN_PARAMETROS) {
		Imagen imagen;
		setHilos(atoi(argv[1]));
		obtenerImagen(this->str_img, &imagen);
		aplicarFiltros(argc, argv, &imagen);
	} else {
		return 1;
	}
	return 0;
}

void Interfaz::aplicarFiltros(int argc, char *argv[], Imagen *imagen) {
	for(int i=ID_FILTRO; i<argc; i++) {
		filtrar(argv[i], argv[i+1], imagen);
		i++;
	}
	mostrarImagen(imagen);
}

void Interfaz::obtenerImagen(std::string cadena, Imagen *imagen) {
	int ancho = 0;
	int alto = 0;
	int i = 0;
	std::string img;
    std::string s(cadena);
    std::istringstream iss(cadena);
    do {
    	std::string sub;
    	iss >> sub;
    	switch (i) {
    	case 0:
    		ancho = atoi(sub.c_str());
    		i++;
    		break;
    	case 1:
    		alto = atoi(sub.c_str());
    		i++;
    		break;
    	case 2:
    		img += sub;
    		break;
    	}
    } while (iss);
    imagen->setDimension(ancho, alto);
    imagen->cargarImagen(img);
}

void Interfaz::mostrarImagen(Imagen *imagen) {
	std::cout<<imagen->getAncho()<<" "<<imagen->getAlto()<<std::endl;
	for(int i=0; i<imagen->getAlto(); i++) {
		for(int j=0; j<imagen->getAncho(); j++) {
			std::cout<<imagen->getPixel(i,j);
		}
		std::cout<<std::endl;
	}
}

Filtro* Interfaz::getFiltro(std::string tipo_filtro, Imagen* imagenFiltro) {
	Filtro* filtro = NULL;
	if (tipo_filtro == "d") {
		filtro = new Dilatacion(imagenFiltro);
	} else if (tipo_filtro == "e") {
		filtro = new Erosion(imagenFiltro);
	}
	return filtro;
}

int Interfaz::getFilasAProcesarPorHilo(int altura, int hilos) {
	if(hilos > altura) {
		return MIN_FILA_POR_HILO;
	} else {
	return altura / hilos;
	}
}

void Interfaz::filtrar(std::string tipo_filtro,
		std::string patron, Imagen *imagen) {
    std::vector<Thread*> threads;
    Imagen img_filtro;
    obtenerImagen(patron, &img_filtro);


    Imagen original;
	original.copiar(imagen);

	int filas = getFilasAProcesarPorHilo(imagen->getAlto(), hilos);

	int inicio = 0;
	int fin = filas;
	bool procesar = true;
	int hilosLanzados = 0;
	while(procesar) {
	    Filtro* filtro = getFiltro(tipo_filtro, &img_filtro);
		filtro->setParametros(inicio, fin, imagen, &original);
		threads.push_back(filtro);

		if (fin == imagen->getAlto()) {
			procesar = false;
		}
		inicio = fin;
		fin = fin + filas;
		if (fin > imagen->getAlto()) {
			fin = imagen->getAlto();
		}
		hilosLanzados++;
	}
	for (int i = 0; i < hilosLanzados; i++) {
		threads[i]->start();
	}
	for (int i = 0; i < hilosLanzados; i++) {
		threads[i]->join();
		delete threads[i];
	}
}

Interfaz::~Interfaz() {
}

