#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Funcion que duplica la lista dada de la forma exigida
 *  en el enunciado
 * @tparam T Plantilla del tipo de dato que se introduce en la lista
 * @param L Lista introducida
 */
template <class T> void duplicarlista(list<T> &L);

/**
 * @brief Funcion que muestra la lista por pantalla
 * @tparam T Plantilla del tipo de dato que se introduce en la lista
 * @param g Lista a mostrar
 */
template <class T> void showlist(list<T> g);

int main() {
    list<int> listado = {1, 2, 3, 4, 5};
    duplicarlista(listado);
}

template <class T>
void duplicarlista(list<T> &L) {
    list<T> sol, aux;
    int tam = L.size();

    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) {
            sol.push_back(L.back());
            L.pop_back();
        } else {
            sol.push_back(L.front());
            L.pop_front();
        }
    }

    aux = sol;

    for (int i = 0; i < tam; i++) {
        if (i % 2 == 0) {
            sol.push_back(aux.back());
            aux.pop_back();
        } else {
            sol.push_back(aux.front());
            aux.pop_front();
        }
    }

    showlist(sol);
}

template <class T>
void showlist(list<T> g) {
    typename list<T>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}