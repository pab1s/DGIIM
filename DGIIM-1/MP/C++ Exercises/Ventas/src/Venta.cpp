/* 
 * File:   Venta.cpp
 * Author: Pablo Olivares Martínez
 * 
 * Created on 11 de junio de 2020, 20:57
 */

#include <sstream>
#include <string>

#include "Venta.h"

using namespace std;

Venta::Venta(const std::string &linea) {
    istringstream flujodeString;
    if (linea.size() > 0) {
        flujodeString.str(linea);
        flujodeString >> idCliente;
        flujodeString >> idProducto;
        flujodeString >> total;
    } else {
        idCliente = 0;
        idProducto = 0;
        total = 0;
    }
}

int Venta::getIdCliente() const {
    return idCliente;
}

int Venta::getIdProducto() const {
    return idProducto;
}

double Venta::getTotal() const {
    return total;
}

//Ejercicio 1.1: Es necesario, pues el constructor con parámetros anula el sin parámetros default
Venta::Venta() {
    idCliente = 0;
    idProducto = 0;
    total = 0;
}

//Ejercicio 1.2: No es necesario, el por defecto actuaría correctamente por no usar memoria dinamica
Venta::~Venta() {
    idCliente = 0;
    idProducto = 0;
    total = 0;
}

//Ejercicio 1.3: No es necesario, ya que al no usar punteros ni memoria dinámica no hay problema con la asignación por defecto