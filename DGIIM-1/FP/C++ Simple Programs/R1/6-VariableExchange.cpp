
#include <iostream>                  // Inclusion de los recursos de E/S

using namespace std; 

int main(){                         // Programa Principal
   
   double edad_Pedro;               // Declara variables para guardar
   double edad_Juan;
   double intercambiador;			// Esta variable la usamos para almacenar el valor de una edad para no perderlo al realizar el cambio
   
   cout << "Introduce la edad de Pedro: ";				// Pide la introducción de variables
   cin >> edad_Pedro;
   cout << "Introduce la edad de Juan: ";
   cin >> edad_Juan;
   
   intercambiador = edad_Pedro;							// Realiza el cambio de variable
   edad_Pedro = edad_Juan;
   edad_Juan = intercambiador;
   
   cout << "La edad de Pedro ahora es " << edad_Pedro << " y la de Juan es " << edad_Juan << ".";			// Da el resultado final al usuario 
}
