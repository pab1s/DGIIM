#include "../include/cola_max.h"
#include <cassert>
using namespace std;

template <class T>
bool Cola_max<T>::vacia(){
    return pila.empty();
}

template <class T>
elemento<T> Cola_max<T>::frente () {
    stack<elemento<T>> aux = pila;
    assert(!pila.empty());
    while (pila.size() > 1) {
        aux.pop();
    }

    return aux.top();
}

template <class T>
void Cola_max<T>::poner(const T& elem) {
    elemento<T> aux;
    aux.ele = elem;
    aux.maximo = elem;

    if(!vacia())
        if(pila.top().maximo > aux.maximo)
            aux.maximo = pila.top().maximo;

    pila.push(aux);
}

template <class T>
void Cola_max<T>::quitar(){
    stack<elemento<T>> aux;

    while (!pila.empty()) {
        aux.push(pila.top());
        pila.pop();
    }

    aux.pop();

    while (!aux.empty()) {
        pila.push(aux.top());
        aux.pop();
    }
}

template <class T>
int Cola_max<T>::num_elementos() const{
    return pila.size();
}