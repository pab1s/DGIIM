/**
 * @file pila_max_vd.cpp
 * @brief Archivo que contiene los métodos de nuestra clase pila con maximo hecho con VD
 * @author Alvaro Luna y Pablo Olivares
 */
#include "../include/pila_max_vd.h"


pila_max_vd::pila_max_vd(const pila_max_vd &orig){
    *this = orig;
}

pila_max_vd & pila_max_vd:: operator= (const pila_max_vd &orig){
    if(this != &orig){
        elementopila = orig.elementopila;
    }

    return *this;
}

void pila_max_vd:: poner(int numero){
    elemento nuevo;

    nuevo.ele = numero;
    nuevo.maximo = numero;

    if(elementopila.empty()){
        elementopila.push_back(nuevo);
    } else{
        if(tope().maximo > numero){
            nuevo.maximo = tope().maximo;
        }

        elementopila.push_back(nuevo);
    }
}

void pila_max_vd:: quitar(){
    if (!vacia()){
        elementopila.pop_back();
    }
}

bool pila_max_vd:: vacia() const{
    return elementopila.empty();
}

const elemento & pila_max_vd:: tope() const{
    return elementopila.back();
}
