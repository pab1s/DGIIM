#include <iostream>

using namespace std;

int main () {
   
   int opcion, km, kmextra;
   double precio = 150;
   char cliente;

   cout << "Introduzca la distancia a la que se encuentra el destino en kilometros: ";
   cin >> km;
   cout << "Introduzca si es cliente previo o no (Si [s] o No [n]): ";
   cin >> cliente;
   
   kmextra = km - 200;
   precio = precio - 15;

	// Comprueba si el cliente es previo y aplica su descuento especial

   if (cliente == 's')  {
   	
   	    cout << "Introduzca si desea aplicar todos los descuentos (1) o no (0): ";
   		cin >> opcion;
   
   	// Comprueba si quiere que se apliquen todos los descuentos o solo el de cliente previo
   
      if (opcion == 1)  {
         if (km <= 200) 
            precio = precio;
   
         if (km > 200)  {  
         
            precio = precio + 0.1 * kmextra;
   
            if (km >= 600 && km < 1100)  
            precio = precio - precio * 0.03;
            
            if (km >= 1100)  
            precio = precio - precio * 0.04;
         }
      }
      
      precio = precio - precio * 0.05;
   }

	// Si no es cliente previo, no aplica el descuento especial
         
   if (cliente == 'n')  {

      if (km <= 200) 
         precio = precio;

      if (km > 200)  {  
      
         precio = precio + 0.1 * kmextra;

         if (km >= 600 && km < 1100)  
         precio = precio - precio * 0.03;
         
         if (km >= 1100)  
         precio = precio - precio * 0.04;
      }  
   }
   
   cout << "El precio final del vuelo es de " << precio << " euros.";
}
