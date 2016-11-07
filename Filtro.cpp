#include "Filtro.h"
#include <iostream>

Filtro::Filtro(Imagen *imagenFiltro) : inicio(0),
		fin(0) , imagen(NULL), original(NULL) {
	filtro.copiar(imagenFiltro);
}

void Filtro::setParametros(int inicio, int fin,
		Imagen* imagen, Imagen* original) {
	this->inicio = inicio;
	this->fin = fin;
	this->imagen = imagen;
	this->original = original;
}

int Filtro::getCentro() {
	return  (filtro.getAlto()-1)/2;
}

void Filtro::run() {
	for(int i=inicio; i<fin; i++) {
		for(int j=0; j<imagen->getAncho(); j++) {
			char resultado = procesarFiltro(original, i, j);
			imagen->setPixel(i, j, resultado);
		}
	}
}

int Filtro::calcularEncendidos() {
	int encendidos = 0;
	for(int i=0; i<filtro.getAlto(); i++) {
		for(int j=0; j<filtro.getAncho(); j++) {
			if (filtro.getPixel(i,j) == '#') {
				encendidos += 1;
			}
		}
	}
	return encendidos;
}

bool Filtro::posicionValida(Imagen *imagen, int fil, int col) {
	if (col>=0 && col<(imagen->getAncho()) && fil>=0 && (fil<imagen->getAlto())) {
		return true;
	}
	return false;
}

bool Filtro::compararBit(char a, char b) {
	char encendido = '#';
	if ((a == encendido) && (b == encendido)) {
		return true;
	}
	return false;
}

char Filtro::procesarFiltro(Imagen *imagen, int pix_f, int pix_c) {
	int coincidencias = 0;
	for(int i=0; i<filtro.getAlto(); i++) {
		for(int j=0; j<filtro.getAncho(); j++) {
			int posRel_fil = i-getCentro() + pix_f;
			int posRel_col = j-getCentro() + pix_c;
			if (posicionValida(imagen, posRel_fil, posRel_col)) {
				if (compararBit(filtro.getPixel(i,j),
						imagen->getPixel(posRel_fil, posRel_col))) {
					coincidencias += 1;
				}
			}
		}
	}
	return aplicarFiltro(coincidencias, calcularEncendidos());
}

Filtro::~Filtro() {
}

