#include <iostream>

using namespace std;

int main () {

   int alien, primo, contador0 = 0, contador1 = 0;
   
   do {
      
	   cin  >> alien;
	   
	   //Cuando detecta un 0 muestra el numero primo
	   if (alien == 0)   {  

	      contador1 = 0;
	      contador0++;
		  	      
	      if (contador0 == 1)	{
	      	if (primo != 0)
			  cout << primo << endl;
		      primo = 1;
	      	
		  }

	   }
		
		//Cuando detecta un 1 sigue aumentando el numero primo 	
	   if (alien == 1) {
	      contador1 = contador1 + alien;
	      primo = contador1;
	      contador0 = 0;
	   }
   } while (contador0 < 5); 
   
   //Una vez llegados a los 5 ceros, envia un uno que servirá de detector para finalizar el siguiente programa
   if (contador0 == 5){
   		cout << 1;
   }
}

