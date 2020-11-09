/* 
 * File:   Clientes.cpp
 * Author: Pablo Olivares Martínez
 * 
 * Created on 11 de junio de 2020, 19:20
 */

#include "Clientes.h"
#include "Cliente.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Clientes::allocate(int n) {
    if (n > 0) {
        losClientes = new Cliente[n];
        numClientes = n;
    } else {
        losClientes = nullptr;
        numClientes = 0;
    }
}

void Clientes::deallocate() {
    if (losClientes) {
        delete[] losClientes;
        losClientes = nullptr;
        numClientes = 0;
    }
}

void Clientes::copy(const Clientes& orig) {
    deallocate();
    allocate(orig.numClientes);
    numClientes = orig.numClientes;
    
    for (int i = 0; i < orig.numClientes; i++) {
        losClientes[i] = orig.losClientes[i];
    }
}

//Ejercicio 1.1: Es necesario, pues emplea memoria dinamica
Clientes::Clientes() {
    losClientes = nullptr;
    numClientes = 0;
}

//Ejercicio 1.2: Es necesario, ya que usamos memoria dinamica
Clientes::~Clientes() {
    deallocate();
}

//Ejercicio 1.3: Es necesario, ya que usamos memoria dinamica
Clientes::Clientes(Clientes& orig) {
    copy(orig);
}

Clientes& Clientes::operator=(const Clientes& orig) {
    if (this != &orig) {
        copy(orig);
    }
    return *this;
}

//Ejercicio 2.1:
Clientes& Clientes::operator+=(const Cliente& orig) {
    
    for (int i = 0; i < numClientes; i++) {
        if (orig.getNIF() == losClientes[i].getNIF())
            return *this;
    }
    
    Cliente* aux = new Cliente[numClientes + 1];
    for (int i = 0; i < numClientes; i++) {
        aux[i] = losClientes[i];
    }
    aux[numClientes] = orig;
    deallocate();
    losClientes = aux;
    numClientes++;
    return *this;
}

//Ejercicio 2.2:
Clientes Clientes::operator+(const Clientes &otro) {
    Clientes aux;
    bool buscando = true;
    aux.allocate(numClientes);
    
    for (int i = 0; i < numClientes; i++) {
        aux.losClientes[i] = losClientes[i];
    }
    for (int i = 0; i < numClientes; i++) {
        buscando = true;
        for (int j = 0; j < otro.numClientes; j++) {
            if (aux.losClientes[i].getNIF() == otro.losClientes[i].getNIF() && buscando)
                buscando = false;
        }

        if (buscando == true)
            aux += otro.losClientes[i];
        
    }
    
    return aux;
}

//Ejercicio 3.1:
std::ostream& operator<<(std::ostream& os, const Clientes& orig) {
    for (int i = 0; i < orig.getNumeroClientes(); i++) {
        os << orig[i].toString() << endl;
    }
    return os;
}

//Ejercicio 4.2
void Clientes::escribirClientes(const string nombre) const {
    ofstream flujo;
    flujo.open(nombre);

    if (!flujo) {
        cerr << "No hay fichero. Error." << endl;
        exit(1);
    }
    else {
        flujo << "FICHEROCLIENTES" << endl;       
        flujo << *this;
        
        if (flujo.fail()) {
            cerr << "Fallo en la lectura. Error." << endl;
            exit(1);
        }
        
        flujo.close();
    }
}

Cliente& Clientes::operator[](int n) {
    return losClientes[n];
}

const Cliente& Clientes::operator[](int n) const {
    return losClientes[n];
}

int Clientes::getNumeroClientes() const {
    return numClientes;
};