/**
 * @file 41.cpp
 * @author Pablo Olivares Martinez
 * @brief Programa que realiza la funcion requerida en el ejercicio
 * 41 del reto 5.
 * @date 2020-12-22
 */

#include <iostream>
#include "../include/bintree.h"

using namespace std;

/**
 * @brief Funcion original sobrecargada para trabajar con nodos.
 * @param w nodo a buscar su nivel.
 * @param A Nodo del arbol donde se busca.
 * @return int Nivel en el que se encuentra el nodo. Si no pertenece
 * al arbol, devuelve -1.
 */
int enquenivel (bintree<int>:: node w, bintree<int>::node A);

/**
 * @brief Funcion original para la busqueda del nivel de un nodo
 * dado el nodo y el arbol.
 * @param w nodo a buscar su nivel.
 * @param A Arbol donde se busca.
 * @return int Nivel en el que se encuentra el nodo. Si no pertenece
 * al arbol, devuelve -1.
 */
int enquenivel (bintree<int>:: node w, bintree<int> & A);

int main () {
    // Creamos el árbol:
    //        7
    //     /    \
    //    1      9
    //  /  \    /
    // 6    8  5
    //       \
    //       4

    bintree<int> Arb(7), Aux(4);
    Arb.insert_left(Arb.root(), 1);
    Arb.insert_right(Arb.root(), 9);
    Arb.insert_left(Arb.root().left(), 6);
    Arb.insert_right(Arb.root().left(), 8);
    Arb.insert_right(Arb.root().left().right(), 4);
    Arb.insert_left(Arb.root().right(), 5);


    cout << enquenivel(Arb.root().left().right().right(), Arb) << endl;
    return 0;
}

int enquenivel (bintree<int>:: node w, bintree<int>::node A) {
    //Establezco -1 para el caso en que no estuviese el nodo
    int n = -1, n1, n2;

    if (w == A)
        return ++n;

    if (A.right() == w || A.left() == w) {
        return n+2;
    }
    else if (!A.left().null() && !A.right().null() && A.left() != w && A.right() != w) {
        n1 = enquenivel(w,A.left());
        n2 = enquenivel(w,A.right());
        n = n1 > n2 ? n1 : n2;
    }
    else if (!A.left().null() && A.left() != w) {
        n = enquenivel(w,A.left());
    }
    else if (!A.right().null() && A.right() != w) {
        n = enquenivel(w,A.right());
    }

    if (n != -1)
        ++n;

    return n;
}

int enquenivel (bintree<int>:: node w, bintree<int> & A) { return enquenivel(w, A.root()); }
