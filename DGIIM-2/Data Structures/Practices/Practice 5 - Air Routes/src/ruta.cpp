#include "ruta.h"

#include <iostream>

#include "punto.h"

using namespace std;

/**
 * @brief Sobrecarga auxiliar para la salida de rutas usado en
 * escribirRuta() para facilitar la legibilidad del código.
 * @param is Flujo de salida.
 * @param R Lista de puntos de la STL a mostrar.
 * @return istream& Devuelve el control del flujo de salida.
 */
ostream &operator<<(ostream &os, const list<Punto> &R);

Ruta::Ruta() {
    Id = "";
    np = 0;
}

Ruta::Ruta(const list<Punto> &R) {
    Id = "";
    ruta = R;
    np = R.size();
}

Ruta::Ruta(const list<Punto> &R, const string &etiq) {
    Id = etiq;
    ruta = R;
    np = R.size();
}

Ruta::Ruta(const Ruta &R) { copiar(R); }

Ruta &Ruta::operator=(const Ruta &R) {
    copiar(R);
    return *this;
}

bool Ruta::operator==(const Ruta &R) const {
    return (this->getId() == R.getId() && this->getRuta() == R.getRuta());
}

void Ruta::setId(const string &etiq) { Id = etiq; }

void Ruta::setRuta(const list<Punto> &r) { ruta = r; }

void Ruta::insertar(const Punto &P) {
    ruta.push_back(P);
    np++;
}

void Ruta::borrarPunto() {
    ruta.pop_front();
    np--;
}

bool Ruta::vacia() { return ruta.empty(); }

void Ruta::eliminar() {
    ruta.clear();
    setId("");
    np = 0;
}

string Ruta::getId() const { return Id; }

list<Punto> Ruta::getRuta() const { return ruta; }

int Ruta::getSize() const { return np; }

void Ruta::leerRuta(istream &is) {
    Punto p;

    if (!this->vacia())
        this->eliminar();

    is >> Id >> np;
    for (int i = 0; i < np; i++) {
        is >> p;
        ruta.push_back(p);
    }
}

void Ruta::escribirRuta(ostream &os) const {
    os << Id << ' ' << np << ' ' << ruta << endl;
}

ostream &operator<<(ostream &os, const Ruta &R) {
    R.escribirRuta(os);
    return os;
}

istream &operator>>(istream &is, Ruta &R) {
    R.leerRuta(is);
    return is;
}

void Ruta::copiar(const Ruta &R) {
    if (this->ruta != R.getRuta() || this->Id != R.getId()) {
        this->ruta = R.getRuta();
        this->np = R.getSize();
        this->Id = R.getId();
    }
}

ostream &operator<<(ostream &os, const list<Punto> &R) {
    list<Punto>::const_iterator it;

    for (it = R.cbegin(); it != R.cend(); ++it) {
        os << ' ' << *it;
    }

    return os;
}


Ruta::iterator & Ruta::iterator::operator++(){
    ++p;
    return * this;
}

Ruta::iterator & Ruta::iterator::operator--(){
    --p;
    return * this;
}

bool Ruta::iterator::operator==(const iterator  & it){
    return it.p ==p;
}

bool Ruta::iterator::operator!=(const iterator  & it){
    return it.p !=p;
}

const Punto & Ruta::iterator::operator*()const{
    return *p;
}


Ruta::const_iterator::const_iterator(const iterator & it){
    p=it.p;
}

Ruta::const_iterator & Ruta::const_iterator::operator=(const Ruta::iterator & it){
    p=it.p;
    return *this;
}   

Ruta::const_iterator & Ruta::const_iterator::operator ++(){
    ++p;
    return * this;
}

Ruta::const_iterator & Ruta::const_iterator::operator --(){
    --p;
    return * this;
}

bool Ruta::const_iterator::operator ==(const Ruta::const_iterator  & it){
    return it.p ==p;
}

bool Ruta::const_iterator::operator !=(const Ruta::const_iterator  & it){
    return it.p !=p;
}

const Punto & Ruta::const_iterator::operator*()const {
    return *p;
}


Ruta::iterator Ruta::begin(){
    iterator it;
    it.p = ruta.begin();
    return it;
}  

Ruta::const_iterator Ruta::cbegin()const{
    const_iterator it;
    it.p = ruta.begin();
    return it;
}

Ruta::iterator Ruta::end(){
    iterator it;
    it.p = ruta.end();
    return it;
}

Ruta::const_iterator Ruta::cend()const{
    const_iterator it;
    it.p = ruta.end();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p){
    iterator it;
    std::list<Punto>::iterator i;

    for (i=ruta.begin(); i!=ruta.end() && !((*i)==p);++i);
        it.p=i;

    return it;
}