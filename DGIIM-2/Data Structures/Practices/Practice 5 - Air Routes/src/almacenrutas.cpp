#include <iostream>
#include "almacenrutas.h"

using namespace std;

/**
 * @brief Sobrecarga auxiliar para la salida de rutas usado en
 * escribirAlmacen() para facilitar la legibilidad del código.
 * @param is Flujo de salida.
 * @param R Lista de rutas de la STL a mostrar.
 * @return istream& Devuelve el control del flujo de salida.
 */
ostream &operator<<(ostream &os, const list<Ruta> &R);

/**
 * @brief Sobrecarga auxiliar para la entrada de rutas usado en
 * leerAlmacen() para facilitar la legibilidad del código.
 * @param is Flujo de entrada.
 * @param R Lista de rutas de la STL a rellenar.
 * @return istream& Devuelve el control del flujo de entrada.
 */
istream &operator>>(istream &is, list<Ruta> &R);

AlmacenRutas::AlmacenRutas(const list<Ruta> &AR) { AlmRuta = AR; }

AlmacenRutas::AlmacenRutas(const AlmacenRutas &AR) { copiar(AR); }

AlmacenRutas &AlmacenRutas::operator=(const AlmacenRutas &AR) {
    copiar(AR);
    return *this;
}

void AlmacenRutas::borrarRuta(const string ident) {
    Ruta R = getRuta(ident);
    AlmRuta.remove(R);
}

void AlmacenRutas::insertarRuta(const Ruta R) { AlmRuta.push_back(R); }

bool AlmacenRutas::vacia() { return AlmRuta.empty(); }

Ruta &AlmacenRutas::getRuta(const string ident) {
    list<Ruta>::iterator it;

    bool encontrado = false;

    for (it = AlmRuta.begin(); it != AlmRuta.end() && !encontrado; it++)
        if ((*it).getId() == ident) {
            encontrado = true;
        }

    --it;

    return (*it);
}

int AlmacenRutas::getSize() const { return AlmRuta.size(); }

list<Ruta> AlmacenRutas::getLista() const { return AlmRuta; }

void AlmacenRutas::leerAlmacen(istream &is) {
    string clave = "", seguro = "#Rutas";

    is >> clave;

    if (clave != seguro) {
        cerr << "El fichero no es válido." << endl;
    } else {
        is >> AlmRuta;
    }
}

void AlmacenRutas::escribirAlmacen(ostream &os) const { os << AlmRuta; }

ostream &operator<<(ostream &os, const AlmacenRutas &AR) {
    AR.escribirAlmacen(os);
    return os;
}

istream &operator>>(istream &is, AlmacenRutas &AR) {
    AR.leerAlmacen(is);
    return is;
}

void AlmacenRutas::copiar(const AlmacenRutas &AR) {
    list<Ruta> aux = AR.getLista();
    AlmRuta = aux;
}

void AlmacenRutas::eliminar() {
    while (!AlmRuta.empty()) AlmRuta.pop_front();
}

ostream &operator<<(ostream &os, const list<Ruta> &R) {
    list<Ruta>::const_iterator it;

    for (it = R.cbegin(); it != R.cend(); ++it) {
        os << ' ' << *it;
    }

    return os;
}

istream &operator>>(istream &is, list<Ruta> &R) {
    Ruta r;

    while (is.peek() != EOF) {
        is >> r;
        R.push_back(r);
    }

    return is;
}