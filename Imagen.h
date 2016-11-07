#ifndef IMAGEN_H_
#define IMAGEN_H_

#include <string>

class Imagen {
private:
	int ancho;
	int alto;
	char **matriz;

public:
	Imagen();
	int getAncho();
	int getAlto();
	void setDimension(int alto, int ancho);
	char getPixel(int fila, int columna);
	void setPixel(int i, int j, char pixel);
	void cargarImagen(std::string imagen);
	void copiar(Imagen *imagen);
	virtual ~Imagen();

private:
};

#endif
