
#include <iostream>             // Inclusion de los recursos de E/S

using namespace std; 

int main(){             		      // Programa Principal
   
   const double PI = 3.1415927;      // Declara una constante
   double radio;              	   	 // Declara variables para guardar
   double longitud;
   double area;
   
   cout << "Introduzca la longitud del radio en metros: ";											// Pide la variable necesaria para el cálculo
   cin >> radio;

   longitud = 2 * PI * radio;																		// Realiza los dos cálculos requeridos
   area = PI * radio * radio;
   
   cout << "La longitud de la circunferencia dada es de " << longitud << " metros." << endl;		// Muestra los resultados al usuario
   cout << "El area del circulo es de " << area << " metros cuadrados.";
}
