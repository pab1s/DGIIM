#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Funcion que rota la lista n veces 
 * @tparam T Plantilla del tipo de dato que se introduce en la lista
 * @param L Lista a rotar
 * @param n Numero de iteraciones de la rotacion
 */
template <class T> void rotalista(list<T> &L, int n);

/**
 * @brief Funcion que muestra la lista por pantalla
 * @tparam T Plantilla del tipo de dato que se introduce en la lista
 * @param g Lista a mostrar
 */
template <class T> void showlist(list<T> g);

int main() {
    list<int> listado = {1, 2, 3, 4, 5};
    rotalista(listado, 7);
    showlist(listado);
}

template <class T>
void rotalista(list<T> &L, int n) {
    n %= L.size();

    for (int i = 0; i < n; i++) {
        L.push_back(L.front());
        L.pop_front();
    }
}

template <class T>
void showlist(list<T> g) {
    typename list<T>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}