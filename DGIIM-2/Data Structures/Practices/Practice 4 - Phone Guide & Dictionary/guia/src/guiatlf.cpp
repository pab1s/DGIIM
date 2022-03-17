#include "../include/guiatlf.h"

string& Guia_Tlf::operator[](const string& nombre) { return datos[nombre]; }

string Guia_Tlf::gettelefono(const string& nombre) {
    map<string, string>::iterator it = datos.find(nombre);
    if (it == datos.end())
        return string("");
    else
        return it->second;
}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(string nombre,
                                                           string tlf) {
    pair<string, string> p(nombre, tlf);
    pair<map<string, string>::iterator, bool> ret;

    ret = datos.insert(p);
    return ret;
}

pair<map<string, string>::iterator, bool> Guia_Tlf::insert(
    pair<string, string> p) {
    pair<map<string, string>::iterator, bool> ret;

    ret = datos.insert(p);
    return ret;
}

void Guia_Tlf::borrar(const string& nombre) {
    map<string, string>::iterator itlow =
        datos.lower_bound(nombre);  // el primero que tiene dicho nombre
    map<string, string>::iterator itupper =
        datos.upper_bound(nombre);  // el primero que ya no tiene dicho nombre
    datos.erase(itlow,
                itupper);  // borramos todos aquellos que tiene dicho nombre
}

void Guia_Tlf::borrar(const string& nombre, const string& tlf) {
    map<string, string>::iterator itlow =
        datos.lower_bound(nombre);  // el primero que tiene dicho nombre
    map<string, string>::iterator itupper =
        datos.upper_bound(nombre);  // el primero que ya no tiene dicho nombre
    map<string, string>::iterator it;
    bool salir = false;
    for (it = itlow; it != itupper && !salir; ++it) {
        if (it->second == tlf) {
            datos.erase(it);
            salir = true;
        }
    }
}

int Guia_Tlf::size() const { return datos.size(); }

unsigned int Guia_Tlf::contabiliza(const string& nombre) {
    return datos.count(nombre);
}

void Guia_Tlf::clear() { datos.clear(); }

bool Guia_Tlf::esVacia() { return datos.empty(); }

pair<map<string, string>::iterator, bool> Guia_Tlf::buscarNombre(const string &tlf){
    pair<map<string, string>::iterator, bool> result;
    
    for (auto it = datos.begin(); it != datos.end(); ++it) {
        if (it->second == tlf) {
            result.first = it;
            result.second = true;
        }
    }
    if (result.first == datos.end()) {
        result.second = false;
    }
    
    return result;
}

void Guia_Tlf::cambiarNombre(const string &tlf, const string &nuevo_nombre) {
    pair<map<string, string>::iterator, bool> aux = buscarNombre(tlf);
    pair<string, string> result;

    if (aux.second == true) {
        result.first = nuevo_nombre + '\t';
        result.second = tlf;
        borrar((*aux.first).first);
        insert(result);
    }
}

void Guia_Tlf::cambiarTlf(const string &nombre, const string &tlf) {
    string aux = nombre + '\t';
    borrar(aux);
    insert(aux, tlf);
}

Guia_Tlf Guia_Tlf::operator+(const Guia_Tlf& g) {
    Guia_Tlf aux(*this);
    map<string, string>::const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it) {
        aux.insert(it->first, it->second);
    }
    return aux;
}

Guia_Tlf Guia_Tlf::operator-(const Guia_Tlf& g) {
    Guia_Tlf aux(*this);
    map<string, string>::const_iterator it;
    for (it = g.datos.begin(); it != g.datos.end(); ++it) {
        aux.borrar(it->first, it->second);
    }
    return aux;
}

ostream& operator<<(std::ostream& os, Guia_Tlf& g) {
    for (auto it = g.cbegin(); it != g.cend(); ++it) {
        os << (*it).first << '\t' << '\t' << (*it).second << std::endl;
    }
    return os;
}

istream& operator>>(istream& is, pair<string, string>& d) {
    getline(is, d.first, '\t');
    getline(is, d.second);
    return is;
}

istream& operator>>(std::istream& is, Guia_Tlf& g) {
    g.datos.clear();
    std::pair<std::string, std::string> aInsertar;
    while (is) {
        is >> aInsertar;
        if (is) g.insert(aInsertar);
    }

    return is;
}

// Iterator
Guia_Tlf::iterator::iterator(typename std::map<string, string>::iterator it) {
    this->mit = it;
}

Guia_Tlf::iterator::iterator() {}

Guia_Tlf::iterator::iterator(const iterator& it) { mit = it.mit; }

Guia_Tlf::iterator& Guia_Tlf::iterator::operator=(const iterator& it) {
    mit = it.mit;
    return *this;
}

Guia_Tlf::iterator& Guia_Tlf::iterator::operator++() {
    ++this->mit;
    return *this;
}

Guia_Tlf::iterator& Guia_Tlf::iterator::operator--() {
    --this->mit;
    return *this;
}

pair<const string, string>& Guia_Tlf::iterator::operator*() { return *mit; }

bool Guia_Tlf::iterator::operator!=(const iterator& it) const {
    return mit != it.mit;
}

bool Guia_Tlf::iterator::operator==(const iterator& it) const {
    return mit == it.mit;
}

// Const iterator
Guia_Tlf::const_iterator::const_iterator(
    typename map<string, string>::const_iterator it) {
    this->mit = it;
}

Guia_Tlf::const_iterator::const_iterator() {}

Guia_Tlf::const_iterator::const_iterator(const const_iterator& it) {
    mit = it.mit;
}

Guia_Tlf::const_iterator& Guia_Tlf::const_iterator::operator=(
    const const_iterator& it) {
    mit = it.mit;
    return *this;
}

Guia_Tlf::const_iterator& Guia_Tlf::const_iterator::operator++() {
    ++this->mit;
    return *this;
}

Guia_Tlf::const_iterator& Guia_Tlf::const_iterator::operator--() {
    --this->mit;
    return *this;
}

pair<const string, string> Guia_Tlf::const_iterator::operator*() const {
    return *mit;
}

bool Guia_Tlf::const_iterator::operator!=(const const_iterator& it) const {
    return mit != it.mit;
}

bool Guia_Tlf::const_iterator::operator==(const const_iterator& it) const {
    return mit == it.mit;
}

Guia_Tlf::iterator Guia_Tlf::begin() {
    return Guia_Tlf::iterator(datos.begin());
}

Guia_Tlf::iterator Guia_Tlf::end() {
    return Guia_Tlf::iterator(datos.end());
    }

Guia_Tlf::const_iterator Guia_Tlf::cend() const {
    return Guia_Tlf::const_iterator(datos.cend());
}

Guia_Tlf::const_iterator Guia_Tlf::cbegin() const {
    return Guia_Tlf::const_iterator(datos.cbegin());
}