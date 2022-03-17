/**
 * @file 35.cpp
 * @author Pablo Olivares Martinez
 * @brief Programa que realiza la funcion requerida en el ejercicio
 * 35 del reto 5.
 * @date 2020-12-22
 */

#include <iostream>
#include "../include/bintree.h"

using namespace std;

/**
 * @brief Funcion que dados dos arboles A y B que comparten la misma
 * estructura, suma los valores de las etiquetas en la misma posicion.
 * @param A Arbol a sumar.
 * @param B Arbol a sumar.
 * @param C Arbol solucion.
 */
void sumadosarboles(bintree<int> A, bintree<int> B, bintree<int> &C);

/**
 * @brief Funcion que comprueba si dos arboles tienen la misma estructura.
 * @param A arbol A a comparar con B.
 * @param B arbol B a comparar con A.
 * @return true ambos arboles tienen la misma estructura.
 * @return false los arboles tienen estructura distinta.
 */
bool mismaStruct(bintree<int>::node A, bintree<int>::node B);

int main(int argc, char *argv[]) {
    bintree<int> A(3), B(10), C;
	bintree<int>::preorder_iterator it;

    A.insert_left(A.root(), 1);
    A.insert_right(A.root(), 9);
    A.insert_left(A.root().left(), 6);
    A.insert_right(A.root().left(), 8);
    A.insert_right(A.root().left().right(), 4);
    A.insert_left(A.root().right(), 5);;

    B.insert_left(B.root(), 4);
    B.insert_right(B.root(), 3);
    B.insert_left(B.root().left(), 5);
    B.insert_right(B.root().left(), 22);
    B.insert_right(B.root().left().right(), 12);
    B.insert_left(B.root().right(), -7);

	sumadosarboles(A, B, C);

	it = C.begin_preorder();
	for (it; it != C.end_preorder(); ++it)
		cout << *it << " ";
	cout << endl;

    return 0;
}

void sumadosarboles(bintree<int> A, bintree<int> B, bintree<int> &C) {
    if (mismaStruct(A.root(),B.root())) {
		C = A;
		bintree<int>::preorder_iterator it = C.begin_preorder(), itB = B.begin_preorder();

		for (itB, it; it != C.end_preorder(); ++itB, ++it)
			*it += *itB;
	}
}

bool mismaStruct(bintree<int>::node A, bintree<int>::node B) {
    if (A.null() && B.null()) return true;

    if (!A.null() && !B.null()) {
        return (mismaStruct(A.left(), B.left()) &&
                mismaStruct(A.right(), B.right()));
    }

    return false;
}