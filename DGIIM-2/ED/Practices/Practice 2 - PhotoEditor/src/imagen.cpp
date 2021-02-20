/**
 * @file imagen.cpp
 * @author Alvaro Luna y Pablo Olivares
 *  */
#include <cassert>
#include "imagenES.h"
#include "imagen.h"

using namespace std;

Imagen::Imagen() {
    img =nullptr;
    cols = 0;
    fils = 0;
}

Imagen:: Imagen(int f, int c){
    img = nullptr;
    allocate(f, c);
}

Imagen::Imagen (const Imagen & orig){
    copia(orig);
}

Imagen& Imagen::operator=(const Imagen& orig) {
    if(this != &orig)
        copia(orig);

    return *this;
}

Imagen::~Imagen() {
    deallocate();
}

int Imagen:: num_filas () const{
    return fils;
}

int Imagen:: num_columnas () const{
    return cols;
}

void Imagen:: asigna_pixel (int fil, int col, byte valor){
    assert(fil >= 0 && fil < num_filas());
    assert(col >= 0 && col < num_columnas());

    img[fil*cols + col]=valor;
}

byte Imagen:: valor_pixel (int fil, int col) const{
    assert(fil >= 0 && fil < num_filas());
    assert(col >= 0 && col < num_columnas());

    return img[fil*cols + col];
}

void Imagen::copia(const Imagen & i) {
    if(num_filas() != i.num_filas() || num_columnas() != i.num_columnas()) {
        deallocate();
        allocate(i.num_filas(), i.num_columnas());
    }

	//P2 = i.P2;
	cols = i.num_columnas();
	fils = i.num_filas();
	//brillo_max = i.brillo_max;

    for (int j = 0; j < num_filas(); j++)
        for (int k = 0; k < num_columnas(); k++)
            asigna_pixel(j, k, i.valor_pixel(j, k));    
}

bool Imagen::print(const char* ofile) {
    return EscribirImagenPGM(ofile, img, fils, cols);
    return true;
}

bool Imagen::read(const char *ifile) {
    img = LeerImagenPGM (ifile, fils, cols);
    return true;
}

    void Imagen::allocate(int f, int c){
        if (img != nullptr)
            deallocate();

        assert(f>-1 && c>-1);

        fils = f;
        cols = c;

        img = new byte[fils*cols];

        for (int i = 0; i < fils*cols; i++)
            img[i] = 0;
    }

    void Imagen ::deallocate(){
        if (img != nullptr)
            delete[] img;
    }
    