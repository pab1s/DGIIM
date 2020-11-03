
#include <iostream>   // Inclusion de los recursos de E/S

using namespace std; 

int main(){                       // Programa Principal
   
   double capital, capitalinicial, interes;               // Declara variables para guardar
   int contador = 0;
   
   cout << "Introduzca el capital a ingresar en euros: ";                        // Pide que se introduzca el valor de las variables a usar
   cin >> capital;
   cout << "Introduzca el porcentaje de interes anual: ";
   cin >> interes;
  
  capitalinicial = capital;

	// Vuelve a realizar la operación de intereses si no se cumple la condición  
   do{
   		capital = capital + capital * interes / 100;									 // Realiza el cálculo requerido para obtener el total	
   		contador++;
   	
   } while (capital < 2 * capitalinicial);
   
   cout << "El total de su capital supera el doble del inicial despues de " << contador << " anos.";		 // Muestra el valor total del nuevo capital
}
