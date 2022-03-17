#include <iostream>
#include "../include/cola_max.h"
using namespace std;
ostream &operator<<(ostream &o, const elemento<int> &e);

int main() {
    Cola_max<int> c;

  /*  for (int i = 10; i >= 0; i--) {
        c.poner(i);
    }*/
    c.poner(6);
    c.poner(4);

    while (!c.vacia()) {
        elemento<int> x = c.frente();
        cout << c.frente().ele;
        cout << x << endl << c.num_elementos() << endl;
        c.quitar();
    }
    return 0;
}

ostream &operator<<(ostream &o, const elemento<int> &e){
    o << e.ele << " " << e.maximo << "\n";
    return o;
}