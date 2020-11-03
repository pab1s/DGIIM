#include <iostream>
#include <algorithm>

using namespace std;

int Amigos(int primero, int segundo)	{
	
	int contador1 = 0, contador2 = 0, divisor = 1;
	bool son_amigos = false;
	
   //Suma los divisores del número 1
   do {
      
      if (primero % divisor == 0) 
         contador1 = contador1 + divisor;
      
      divisor++;
      
   } while (divisor < primero);
   
   divisor = 1;
   
   //Suma los divisores del número 2
   do {
      
      if (segundo % divisor == 0) 
         contador2 = contador2 + divisor;
      
      divisor++;
      
   } while (divisor < segundo);
   
   if (contador1 == segundo && contador2 == primero)
   	son_amigos = true;
   	else
   		son_amigos = false;
   		
   	return (son_amigos);	
   	
}

int main () {
   
   int numero1, numero2, mayor, menor, i, j;
   
   //Introducción de variables según las condiciones indicadas
   cout << "Introduzca un numero entero: ";
   cin >> numero1;

   cout << "Introduzca otro numero entero: ";
   cin >> numero2;
   
   mayor = max(numero1, numero2);
   menor = min(numero1, numero2);
   
	for (i = menor; i <= mayor; i++)
		for (j = menor; j <= mayor; j++)	{
   
		   //Comprueba si son amigos o no y lo muestra por pantalla
			if (Amigos(i,j) == true && i != j)
		      cout << "Los numeros " << i << " y " << j << " son amigos." << endl;
		}
   
}
