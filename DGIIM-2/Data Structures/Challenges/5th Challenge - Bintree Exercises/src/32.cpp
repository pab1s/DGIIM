/**
 * @file 32.cpp
 * @author Pablo Olivares Martinez
 * @brief Programa que realiza la funcion requerida en el ejercicio
 * 32 del reto 5.
 * @date 2020-12-22
 */

#include <iostream>
#include "../include/bintree.h"

using namespace std;

/**
 * @brief Funcion que comprueba si un arbol esta contenido en el otro. 
 * @param ab1 arbol donde buscar.
 * @param ab2 subarbol a buscar.
 * @return true si el subarbol pertenece a ab1.
 * @return false si no pertenece.
 */
bool es_subarbol(const bintree<int> &ab1, const bintree<int> &ab2);

/**
 * @brief Funcion que mira si un nodo y sus hijos contienen los mismos
 * valores.
 * @param n1 nodo del primer arbol.
 * @param n2 nodo del segundo arbol.
 * @return true si tienen los mismos valores.
 * @return false no tienen los mismos valores.
 */
bool sonIguales(bintree<int>::node n1, bintree<int>::node n2);

int main() {
    // Creamos el árbol:
    bintree<int> ab1(7), ab2(1);

    ab1.insert_left(ab1.root(), 1);
    ab1.insert_right(ab1.root(), 9);
    ab1.insert_left(ab1.root().left(), 6);
    ab1.insert_right(ab1.root().left(), 8);
    ab1.insert_right(ab1.root().left().right(), 4);
    ab1.insert_left(ab1.root().right(), 5);

    ab2.insert_left(ab2.root(), 6);
    ab2.insert_right(ab2.root(), 8);
    ab2.insert_right(ab2.root().right(), 4);

    string s = es_subarbol(ab1, ab2)
                   ? "El segundo arbol esta contenido en el primero"
                   : "El segundo arbol no esta contenido en el primero";
    cout << s << endl;
    return 0;
}

bool es_subarbol(const bintree<int> &ab1, const bintree<int> &ab2) {
    bintree<int>::node n1, n2;
    bintree<int> AL, AR, B;

    n1 = ab1.root();
    n2 = ab2.root();

    if (n1.null() && n2.null()) return true;

    if (n1.null() || n2.null()) return false;

    if (sonIguales(n1, n2)) return true;

    AL.assign_subtree(ab1, ab1.root().left());
    AR.assign_subtree(ab1, ab1.root().right());
    B.assign_subtree(ab2, ab2.root());

    return es_subarbol(AL, B) || es_subarbol(AR, B);
}

bool sonIguales(bintree<int>::node n1, bintree<int>::node n2) {
    if (n1.null() && n2.null()) return true;

    if (n2.null() || n1.null()) return false;

    return (*n1 == *n2 && sonIguales(n1.left(), n2.left()) &&
            sonIguales(n1.right(), n2.right()));
}