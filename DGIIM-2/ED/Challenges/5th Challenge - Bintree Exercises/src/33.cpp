/**
 * @file 33.cpp
 * @author Pablo Olivares Martinez
 * @brief Programa que realiza la funcion requerida en el ejercicio
 * 33 del reto 5.
 * @date 2020-12-22
 */

#include <iostream>
#include "../include/bintree.h"

using namespace std;

/**
 * @brief funcion que suma todo el camino desde la hoja a la raiz.
 * @param nodo nodo de la hoja.
 * @return int valor de la suma.
 */
int suma_camino(const bintree<int>::node nodo);

/**
 * @brief funcion que comprueba si un arbol tiene mas de una rama que
 * sume el valor k.
 * @param arb arbol a valorar.
 * @param k valor deseado.
 * @return true si el numero de ramas que suman k es mayor que 1.
 * @return false si el numero de ramas que suman k es 0 o 1.
 */
bool suma_k(const bintree<int> &arb, int k);

/**
 * @brief sobrecarga de la funcion suma_k que devuelve el numero de ramas
 * que cumplen la condicion de la funcion original y usa los nodos para un uso
 * mas comodo.
 * @param nodo nodo del arbol.
 * @param k numero que se busca en la suma.
 * @return int numero de ramas que cumplen la condicion de suma = k.
 */
int suma_k(const bintree<int>::node nodo, int k);

int main() {
    int k = 14;
    bintree<int> ab(7);

    ab.insert_left(ab.root(), 1);
    ab.insert_right(ab.root(), 4);
    ab.insert_left(ab.root().left(), 6);
    ab.insert_right(ab.root().left(), 8);
    ab.insert_right(ab.root().left().right(), 4);
    ab.insert_left(ab.root().right(), 3);

    string s = suma_k(ab, k)
                   ? "La suma de ramas se repite mas de una vez para el valor k."
                   : "El numero de ramas que suman el valor k es de una o ninguna.";
    cout << s << endl;
    return 0;
}

bool suma_k(const bintree<int> &arb, int k) {
    if (suma_k(arb.root(), k) > 1)
        return true;
    else return false;
}

int suma_k(const bintree<int>::node nodo, int k) {
    int check = 0;

    if (!nodo.left().null() && !nodo.right().null()) {
        check = suma_k(nodo.left(), k) + suma_k(nodo.right(), k);
        return check;
    }
    else if (!nodo.left().null()) {
        check = suma_k(nodo.left(), k);
        return check;
    }
    else if (!nodo.right().null()) {
        check = suma_k(nodo.right(), k);
        return check;
    }

    if (suma_camino(nodo) == k)
        return 1;
    else
        return 0;
}

int suma_camino(const bintree<int>::node nodo) {
    if (nodo.null())
        return 0;
    return *nodo + suma_camino(nodo.parent());
}