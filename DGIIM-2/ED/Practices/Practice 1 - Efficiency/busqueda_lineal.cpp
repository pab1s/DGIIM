#include <ctime>
#include <iostream>
// Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
using namespace std;
int buscar(const int *v, int n, int x) {
    int i = 0;
    while (i < n && v[i] != x) i = i + 1;
    if (i < n)
        return i;
    else
        return -1;
}
void sintaxis() {
    cerr << "Sintaxis:" << endl;
    cerr << " TAM: Tamaño del vector (>0)" << endl;
    cerr << " VMAX: Valor máximo (>0)" << endl;
    cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
    exit(EXIT_FAILURE);
}
int main(int argc, char *argv[]) {
    if (argc != 3)
        // Lectura de parámetros
        sintaxis();
    int tam = atoi(argv[1]);
    // Tamaño del vector
    int vmax = atoi(argv[2]);
    // Valor máximo
    if (tam <= 0 || vmax <= 0) sintaxis();
    // Generación del vector aleatorio
    int *v = new int[tam];
    // Reserva de memoria
    srand(time(0));
    // Inicialización generador números pseudoaleatorios
    for (int i = 0; i < tam; i++)  // Recorrer vector
        v[i] = rand() % vmax;
    // Generar aleatorio [0,vmax[
    clock_t tini;
    tini = clock();
    // Anotamos el tiempo de inicio
    int x = vmax + 1;   // Buscamos un valor que no está en el vector
    buscar(v, tam, x);  // de esta forma forzamos el peor caso
    clock_t tfin;
    tfin = clock();
    // Anotamos el tiempo de finalización
    // Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
    cout << tam << "\t" << (tfin - tini) / (double)CLOCKS_PER_SEC << endl;
    delete[] v;
    // Liberamos memoria dinámica
}