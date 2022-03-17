/* 
 * File:   Cliente.cpp
 * Author: Andrés Cano Utrera <acu@decsai.ugr.es>
 * 
 * Created on 11 de junio de 2020, 19:17
 */
#include <string>
#include <iostream>

#include "Cliente.h"

using namespace std;

//Ejercicio 1.1: No es necesario, pero es recomendable
Cliente::Cliente() {
    idCliente = 0;
    descuento = 0.0;
    nombre = "";
    NIF = "";
}

//Ejercicio 1.2: No es necesario, el por defecto actuaría correctamente por no usar memoria dinamica
Cliente::~Cliente() {
    idCliente = 0;
    descuento = 0.0;
    nombre = "";
    NIF = "";
}

//Ejercicio 1.3: No es necesario, ya que al no usar punteros ni memoria dinámica no hay problema con la asignación por defecto

int Cliente::getIdCliente() const{
    return idCliente;
}

double Cliente::getDescuento() const{
    return descuento;
}

std::string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getNIF() const {
    return NIF;
}

std::string Cliente::toString() const {
    string cadena = to_string(idCliente) + " " + to_string(descuento) + " " + 
            nombre + " " + NIF;
    return cadena;
}

//Ejercicio 1.1: Es necesario, pues emplea memoria dinamica
