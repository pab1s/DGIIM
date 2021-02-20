#include "punto.h"

/**
 * @brief Función auxiliar que elimina los espacios en blanco,
 * tabuladores y saltos de línea entre la información del flujo.
 * @param is Flujo de entrada.
 */
void quitarSeparadores(std::istream &is) {
	while (is && (is.peek() == '\t' || is.peek() == ' ' || is.peek() == '\n'))
		is.get();
}

Punto::Punto() {
    latitud = 0;
    longitud = 0;
    descripcion = "";
}

Punto::Punto(const double lat, const double lng) {
    setDescripcion("");
    setLongitud(lng);
    setLatitud(lat);
}

Punto::Punto(double lat, double lng, std::string desc) {
    setDescripcion(desc);
    setLongitud(lng);
    setLatitud(lat);
}

Punto::Punto(const Punto &P) { copiar(P); }

Punto &Punto::operator=(const Punto &P) {
    copiar(P);
    return *this;
}

void Punto::setLatitud(const double lat) { latitud = lat; }

void Punto::setLongitud(const double lng) { longitud = lng; }

void Punto::setDescripcion(const std::string des) { descripcion = des; }

void Punto::setCoordenadas(const double lat, const double lng) {
    setLongitud(lng);
    setLatitud(lat);
}

double Punto::getLatitud() const { return latitud; }

double Punto::getLongitud() const { return longitud; }

std::string Punto::getDescripcion() const { return descripcion; }

void Punto::leerPunto(std::istream &is) { 
    quitarSeparadores(is);
    is.get();
    quitarSeparadores(is);
    is >> latitud;
    quitarSeparadores(is);
    is.get();
    quitarSeparadores(is);
    is >> longitud;
    quitarSeparadores(is);
    is.get();
}

void Punto::escribirPunto(std::ostream &os) const {
    os << ' ' << '(' << getLatitud() << ',' << getLongitud() << ')';
}

std::istream &operator>>(std::istream &is, Punto &P) {
    P.leerPunto(is);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Punto &P) {
    P.escribirPunto(os);
    return os;
}

bool Punto::operator==(const Punto &P) const {
    return (this->getLatitud() == P.getLatitud() &&
            this->getLongitud() == P.getLongitud() &&
            this->getDescripcion() == P.getDescripcion());
}

Punto Punto::operator+(const Punto & g){
    Punto aux(*this);

    aux.setLongitud(aux.getLongitud() + g.getLongitud());
    aux.setLatitud(aux.getLatitud() + g.getLatitud());

    return aux;
}

Punto Punto::operator-(const Punto & g){
    Punto aux(*this);

    aux.setLongitud(aux.getLongitud() - g.getLongitud());
    aux.setLatitud(aux.getLatitud() - g.getLatitud());

    return aux;
}

void Punto::copiar(const Punto &P) {
    setLongitud(P.getLongitud());
    setLatitud(P.getLatitud());
    setDescripcion(P.getDescripcion());
}
