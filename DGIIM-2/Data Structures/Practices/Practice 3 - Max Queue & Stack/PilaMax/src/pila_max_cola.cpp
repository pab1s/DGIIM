#include "../include/pila_max_cola.h"
using namespace std;

void Pila_max_Cola::poner(int n){
    elemento aux;
    aux.maximo = n;
    aux.ele = n;

    if(!vacia())
        if(tope().maximo > aux.maximo)
            aux.maximo = tope().maximo;

    c.poner(aux);
}
void Pila_max_Cola::quitar(){
    Cola<elemento> aux;
    assert(!c.vacia());
        while (c.num_elementos() > 1) {
            aux.poner(c.frente());
            c.quitar();
        }
        c = aux;
}

elemento Pila_max_Cola::tope() {
    Cola<elemento> aux = c;
    assert(!c.vacia());
        while (aux.num_elementos() > 1) {
            aux.quitar();
        }
    return aux.frente();
}

bool Pila_max_Cola::vacia() {
    return c.vacia();
}