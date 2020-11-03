
#include <iostream>
#include <cmath>

using namespace std;

int main () {
   
   double tiempo, distancia, velocidad1, velocidad2, distancia1, distancia2;     //Variables declaradas
   
   cout << "Introduzca la distancia a la que se encuentran ambos trenes en metros: ";     //Introducción de variables
   cin >> distancia;
   cout << "Introduzca la velocidad del primer tren en m/s: ";
   cin >> velocidad1;
   cout << "Introduzca la velocidad del segundo tren en m/s: ";
   cin >> velocidad2;
   
   tiempo = distancia / (velocidad1 + velocidad2);    //Cálculos
   distancia1 = velocidad1 * tiempo;
   distancia2 = velocidad2 * tiempo;
   
   cout << "El primer tren colisionara con el segundo a " << distancia1 << " metros de su origen y el segundo a " << distancia2 << " metros de su origen pasados " << tiempo << " segundos.";      //Salida del resultado
}
