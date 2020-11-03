
#include <iostream>   // Inclusion de los recursos de E/S

using namespace std; 

int main(){                       // Programa Principal
   
   double capital;               // Declara variables para guardar
   double interes;
   
   cout << "Introduzca el capital a ingresar en euros: ";                        // Pide que se introduzca el valor de las variables a usar
   cin >> capital;
   cout << "Introduzca el porcentaje de interes: ";
   cin >> interes;
   
   capital = capital + capital * interes / 100;									 // Realiza el cálculo requerido para obtener el total
   
   cout << "El total de su nuevo capital es de " << capital << " euros.";		 // Muestra el valor total del nuevo capital
}
