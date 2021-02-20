#include <iostream>
#include <list>

using namespace std;

/**
 * @brief Funcion que comprueba si una lista es una conmutacion
 * de elementos de la otra lista
 * @param L1 Lista 1 usada como referencia a comprobar
 * @param L2 Lista 2 que es transformada para comprobar si se cumple o no
 * @return true Una lista es conmutacion de la otra
 * @return false Las listas no son una conmutacion de la otra
 */
bool anagrama(list<int>& L1, list<int>& L2);

/**
 * @brief Funcion que muestra la lista por pantalla
 * @param g Lista de enteros a mostrar
 */
void showlist(list<int> g);

int main() {
    list<int> L1 = {1, 23, 21, 4, 2, 3, 0}, L2 = {21, 1, 3, 2, 4, 23, 0};
    bool a = anagrama(L1, L2);
    cout << a << endl;
}

bool anagrama(list<int>& L1, list<int>& L2) {
    bool found = false;
    int count = 0, tam = L1.size();

    if (L1.size() != L2.size())
        return false;
    else if (L1.empty() && L2.empty())
        return true;

    for (int i = 0; i < tam; i++) {
        found = false;
        do {
            if (L1.front() == L2.front()) {
                L2.pop_front();
                found = true;
                count = 0;
            } else {
                L2.push_back(L2.front());
                L2.pop_front();
                count++;
            }
        } while (L2.size() != count && !found);

        if (L2.size() == count && L2.size() != 0) return false;

        L1.pop_front();
    }
    return true;
}

void showlist(list<int> g) {
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}