#include <iostream>
#include <cstring>

using namespace std;

int main () {
   
   const int DIM = 100;
   int posicion1, posicion2;
   char cadena[DIM];
   
   cout << "Introduzca una cadena de caracteres de longitud maxima de 100: ";
   cin >> cadena;
   cout << "Ahora introduzca la primera posicion: ";
   cin >> posicion1;
   do{
   cout << "Introduzca la segunda posicion: ";
   cin >> posicion2;
   } while (posicion2 < posicion1);
   
   //Imprime la subcadena
   cout << "La subcadena es: ";
   for (int j = (posicion1 - 1); j < posicion2; j++) 
      cout << cadena[j];
   
}
