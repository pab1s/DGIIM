#include <fstream>
#include <iostream>
#include "../include/punto.h"
using namespace std;

int main () {
    fstream ifile;
    Punto P;

    ifile.open("./datos/pruebapunto.txt");
    P.leerPunto(ifile);

    P.setDescripcion("P1");
    cout << P.getDescripcion() << ": ";
    P.escribirPunto(cout);
    cout << endl;

    Punto P2, P3(2.4, -3.3);

    P2.setDescripcion("P2");
    P2.setCoordenadas(1.0, 5.4);

    P3.setDescripcion("P3");

    cout << P2.getDescripcion() << ": ";
    P2.escribirPunto(cout);
    cout << endl;

    cout << P3.getDescripcion() << ": ";
    P3.escribirPunto(cout);
    cout << endl;

    cout << endl << "P1 = P2 - P3" << endl;
    P = P2 - P3;

    cout << P.getDescripcion() << ": ";
    P.escribirPunto(cout);
    cout << endl;

}