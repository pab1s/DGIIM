/**
 * @file 38.cpp
 * @author Pablo Olivares Martinez
 * @brief Programa que realiza la funcion requerida en el ejercicio
 * 38 del reto 5.
 * @date 2020-12-22
 */

#include <iostream>
#include "../include/bintree.h"

using namespace std;

/**
 * @brief funcion que comprueba si el arbol dado
 * es un arbol de seleccion.
 * @param A arbol a evaluar.
 * @return true es un arbol de seleccion.
 * @return false no es un arbol de seleccion.
 */
bool seleccion(bintree<int> & A);

/**
 * @brief A efectos practicos, es la funcion pedida en el ejercicio
 * pero operando con los nodos directamente.
 * @param nodo nodo raiz del arbol.
 * @return true si es un arbol de seleccion.
 * @return false si no lo es.
 */
bool hijoMayorIgual(bintree<int>::node nodo);

int main () {
    bintree<int> ab(1);

    ab.insert_left(ab.root(), 3);
    ab.insert_right(ab.root(), 1);
    ab.insert_left(ab.root().left(), 4);
    ab.insert_right(ab.root().left(), 3);
    ab.insert_right(ab.root().left().right(), 3);
    ab.insert_left(ab.root().right(), 1);

    string s = seleccion(ab)
                   ? "El arbol introducido es un arbol de seleccion."
                   : "El arbol introducido no es un arbol de seleccion.";
    cout << s << endl;
    return 0;
}

bool seleccion(bintree<int> & A) {
    return hijoMayorIgual(A.root());
}

bool hijoMayorIgual(bintree<int>::node nodo) {

    bool check = false,
         cond1 = !nodo.left().null() && !nodo.right().null()    &&
                 (*nodo <= *nodo.left() && *nodo == *nodo.right() || 
                 *nodo <= *nodo.right() && *nodo == *nodo.left()),
         cond2 = !nodo.left().null() && *nodo == *nodo.left(),
         cond3 = !nodo.right().null() && *nodo == *nodo.right(),
         cond4 = nodo.left().null() && nodo.right().null();

    //Comprobamos las condiciones que confirman si es un arbol de seleccion
    if (cond1) {
        check = hijoMayorIgual(nodo.left()) && hijoMayorIgual(nodo.right());
    }

    else if (cond2) {
        check = hijoMayorIgual(nodo.left());
    }

    else if (cond3) {
        check = hijoMayorIgual(nodo.right());
    }

    else if (cond4) {
        check = true;        
    }
    
    else check = false;

    return check;
}