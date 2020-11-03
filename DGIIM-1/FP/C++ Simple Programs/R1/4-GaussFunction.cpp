
#include <iostream>   // Inclusion de los recursos de E/S
#include <cmath>      // Inclusion de los recursos matematicos

using namespace std; 

int main(){                    							  // Programa Principal
 
   const double PI = 3.1415927;     					 // Declara una constante
   double media;             						   	  // Declara variables para guardar
   double mean;
   double x;
   double solucion;
   
   cout << "Introduzca la media: ";						 // Pide la introducción de las variables necesarias							
   cin >> media;
   cout << "Introduzca la desviacion tipica: ";
   cin >> mean ;
   cout << "Introduzca la posicion en el eje x: ";
   cin >> x;
   
   solucion = (1 / (mean * sqrt(2 * PI))) * (exp ((-0.5) * pow((x - media) / mean, 2)));		// Realiza el cálculo requerido
   
   cout << "El valor que toma la funcion en x es: " << solucion;								// Muestra el resultado al usuario
}
