
#include <iostream>	

using namespace std;

int main()	{
	
	int numero1, numero2;
	bool ambos, primero, segundo;
	
	cout << "Introduzca el primer numero: ";
	cin >> numero1;
	cout << "Introduzca el segundo numero: ";
	cin >> numero2;
	
	ambos = numero1 % numero2 == 0 && numero2 % numero1 == 0;
	primero = numero2 % numero1 == 0;
	segundo = numero1 % numero2 == 0;	
	
	// Comprueba si ambos se dividen
	
	if(ambos == 1)	{
		cout << "Ambos numeros se dividen entre si.\n"; 	
	}
	
	else	{
		
		// Comprueba si el primero divide al segundo
		
		if(primero == 1)	{
			cout << "El primer numero divide al segundo.\n";								
			}
		
		else	{		
			
			// Comprueba si el segundo divide al primero
			
			if(segundo == 1)	{
				
				cout << "El segundo numero divide al primero.\n";
			}
			
			// Si ninguno divide al otro, lo muestra
			
			else	{
				
				cout << "Los numeros introducidos no se dividen entre si.\n"; 
			}
		}
	}
	
	system("pause");
}
