#include <iostream>
#include <cstring>

using namespace std;

int main () {
   
   const int DIM = 100;
   int i, j, n = 0, posicion, longitud_cadena, longitud_subcadena, nuevo_total;
   char cadena[DIM], subcadena[DIM], cadena_final[DIM], parte2[DIM];
   
   cout << "Introduzca una cadena de caracteres de longitud maxima de 100: ";
   cin >> cadena;
   cout << "Introduzca la segunda cadena: ";
   cin >> subcadena;
   cout << "Introduzca ahora la posición en la que desea insertarla: ";
   cin >> posicion;
   
   //Establece las longitudes de cadena
   longitud_cadena = strlen(cadena);
   longitud_subcadena = strlen(subcadena);
   nuevo_total = longitud_cadena + longitud_subcadena;
   
   //Escribe la primera parte de la cadena
   for (i = 0; i < posicion; i++){
         cadena_final[i] = cadena[i];          
      }
    
   //Introduce la palabra en la posicion pedida
   if (i == posicion)	{
	   for (int k = posicion; k < (longitud_subcadena + posicion); k++){
	         cadena_final[k] = subcadena[n];          
	         n++;
	      }
	}
   
   //Introduce el resto de la primera cadena
   for (j = (posicion + longitud_subcadena); j < nuevo_total; j++) {
      cadena_final[j] = cadena[i];
      i++;
   }
   
   cout << cadena_final;
   
}
