#include "Imagen.h"
#include <iostream>
#include <string>

Imagen::Imagen() : ancho(0), alto(0), matriz(NULL) {
}

void Imagen::setDimension(int ancho, int alto) {
	this->ancho = ancho;
	this->alto = alto;

	this->matriz = new char*[this->alto];
	for(int i=0; i<this->alto; i++) {
		this->matriz[i] = new char[this->ancho];
	}
	for(int i=0; i<this->alto; i++) {
		for(int j=0; j<this->ancho; j++) {
			matriz[i][j] = '.';
		}
	}
}

int Imagen::getAncho() {
	return this->ancho;
}

int Imagen::getAlto() {
	return this->alto;
}

char Imagen::getPixel(int alto, int ancho) {
	return matriz[alto][ancho];
}

void Imagen::setPixel(int i, int j, char pixel) {
	matriz[i][j] = pixel;
}

void Imagen::copiar(Imagen *imagen) {
	setDimension(imagen->getAncho(), imagen->getAlto());
	for(int i=0; i<this->alto; i++) {
		for(int j=0; j<this->ancho; j++) {
			this->matriz[i][j] = imagen->getPixel(i,j);
		}
	}
}

void Imagen::cargarImagen(std::string imagen) {
	int k=0;
	for(int i=0; i<this->alto; i++) {
		for(int j=0; j<this->ancho; j++) {
			matriz[i][j] = imagen[k];
			k++;
		}
	}
}

Imagen::~Imagen() {
	if (matriz != NULL) {
		for(int i=0; i<this->alto; i++) {
			delete[] matriz[i];
		}
		delete[] matriz;
	}
}
