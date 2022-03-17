/* 
 * File:   Ventas.cpp
 * Author: Pablo Olivares Martínez
 * 
 * Created on 11 de junio de 2020, 20:58
 */

#include "Ventas.h"
#include "Venta.h"
#include <iostream>
#include <fstream>

using namespace std;

void Ventas::allocate(int n) {
    if (n > 0) {
        lasVentas = new Venta[n];
        numVentas = n;
    } else {
        lasVentas = nullptr;
        numVentas = 0;
    }
}

void Ventas::deallocate() {
    if (lasVentas) {
        delete[] lasVentas;
        lasVentas = nullptr;
        numVentas = 0;
    }
}

void Ventas::copy(const Ventas& orig) {
    deallocate();
    allocate(orig.numVentas);
    numVentas = orig.numVentas;
    
    for (int i = 0; i < orig.numVentas; i++) {
        lasVentas[i] = orig.lasVentas[i];
    }

}

//Ejercicio 1.1: Es necesario, pues emplea memoria dinamica
Ventas::Ventas() {
    lasVentas = nullptr;
    numVentas = 0;
}

//Ejercicio 1.2: Es necesario, ya que usamos memoria dinamica
Ventas::~Ventas() {
    deallocate();
}

//Ejercicio 1.3: Es necesario, ya que usamos memoria dinamica
Ventas::Ventas(Ventas& orig) {
    copy(orig);
}

Ventas& Ventas::operator=(const Ventas& orig) {
    if (this != &orig) {
        copy(orig);
    }
    return *this;
}

//Ejercicio 2.1:
Ventas& Ventas::operator+=(const Venta& orig) {
    Venta* aux = new Venta[numVentas + 1];
    for (int i = 0; i < numVentas; i++) {
        aux[i] = lasVentas[i];
    }
    aux[numVentas] = orig;
    deallocate();
    lasVentas = aux;
    numVentas++;
    return *this;
}

//Ejercicio 3.2:
std::istream& operator>>(std::istream& is, Ventas& orig) {
    string cadena = "";
    getline (is, cadena);
    orig += Venta(cadena);
    
    return is;
}

//Ejercicio 4.1:
void Ventas::read(const std::string fichero) {
    std::ifstream flujo;
    std::string password = "";
    
    flujo.open(fichero);
    if (!flujo) {
        cerr << "No hay fichero. Error." << endl;
        exit(1);
    }
    else {
        flujo >> password;
        
        if (password != "FICHEROVENTAS") {
            cerr << "Fichero incorrecto. Error." << endl;
            exit(1);
        }
        while (!flujo.eof()) {
            flujo >> *this;
        }
        
        if (flujo.fail()) {
            cerr << "Fallo en la lectura. Error." << endl;
            exit(1);
        }
        
        flujo.close();
    }
}

Ventas::Ventas(const std::string fichero) {
    read(fichero);
}

bool Ventas::operator>(const Ventas& orig) {
    if (orig.ventaMedia() > this->ventaMedia())        
        return false;
    else
        return true;
}

bool Ventas::operator==(const Ventas& orig) {
    if (orig.ventaMedia() == this->ventaMedia())        
        return true;
    else
        return false;
}

double Ventas::ventaMedia() const{
    double media = 0;
    for (int i = 0; i < numVentas; i++) {
        media += lasVentas[i].getTotal();
    }
    media = media / numVentas;
    return media;
}