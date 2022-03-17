#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Funcion que halla el factorial del entero introducido
 * @param n Entero a calcular
 * @return int Factorial del numero n
 */
int factorial(int n);

/**
 * @brief Funcion que calcula el binomio de Newton
 * @param n Numero de elementos
 * @param k Valor a  escoger
 * @return int Numero de maneras de escoger k para n elementos
 */
int binomioNewton(int n, int k);

/**
 * @brief Funcion que calcula el triangulo de Tartalia y almacena
 * sus valores en un vector de forma lineal
 * @param nivel Ultimo nivel a obtener sus valores del triangulo
 * @param v Vector donde se almacenan los valores del binomio
 * @pre nivel debe ser positivo o 0
 */
void tartaglia(int nivel, vector<unsigned int> &v);

/**
 * @brief Funcion que muestra los elementos del vector
 * @param v Vector a mostrar
 */
void showVector(vector<unsigned int> v);

int main() {
    vector<unsigned int> v;
    tartaglia(7, v);
    showVector(v);
}

int factorial(int n) {
    int sol = 1;
    for (int i = n; i > 1; i--)
        sol *= i;

    return sol;
}

int binomioNewton(int n, int k) {
    int binomio = factorial(n) / (factorial(k) * factorial(n - k));
    return binomio;
}

void tartaglia(int nivel, vector<unsigned int> &v) {
    for (int i = 0; i <= nivel; i++)
        for (int j = 0; j <= i; j++)
            v.push_back(binomioNewton(i, j));
}

void showVector(vector<unsigned int> v) {
    vector<unsigned int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << ' ';
    cout << '\n';
}