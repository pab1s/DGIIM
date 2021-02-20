#include <iostream>
#include "../include/pila_max.h"
using namespace std;
ostream &operator<<(ostream &o, const elemento &e);

int main() {
    Pila_max p;
    int i;

    for (i = 10; i >= 0; i--)
        p.poner(i);

    while (!p.vacia()) {
        elemento x = p.tope();
        cout << x << endl;
        p.quitar();
    }
    return 0;
}

ostream &operator<<(ostream &o, const elemento &e){
    o << e.ele << " " << e.maximo << "\n";
    return o;
}