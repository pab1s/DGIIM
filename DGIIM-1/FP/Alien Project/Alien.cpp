#include <iostream>

using namespace std;

int main () {

   int alien, primo, contador0 = 0, contador1 = 0, numero = 1;

   cout << "Introduzca el codigo extraterretre: ";
   
   do {
      
	   cin  >> alien;
	   
	   if (alien == 0)   {  
	      contador0++;
	      contador1 = 0;
	      
	      if (contador0 == 1)	{
		      numero = numero * primo;
		      if (primo != 0)
			  cout << primo << endl;
		      primo = 1;
	      	
		  }
	   }
	
	   if (alien == 1) {
	      contador1 = contador1 + alien;
	      primo = contador1;
	      contador0 = 0;
	   }
   } while (contador0 < 5);
      
	if (contador0 == 5) {
		cout << "El numero alienigena es: " << numero;
		return 0;
	}   
}

