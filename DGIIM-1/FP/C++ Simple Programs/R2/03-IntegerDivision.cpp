
#include <iostream>													//Inclusi�n de librer�a de recursos I/O

using namespace std;

int main()															//Funci�n principal
{
	int numero1, numero2;											//Variables para guardar n�meros (como enteros)
	bool ambos, primero, segundo;					//Variables booleanas para comprobar los distintos casos
	
	cout << "Introduzca el primer numero: ";
	cin >> numero1;
	cout << "Introduzca el segundo numero: ";
	cin >> numero2;
	
	ambos = numero1 % numero2 == 0 && numero2 % numero1 == 0;		//Las boolean analizar�n que situaci�n se cumple y la mostrar� por pantalla
	
	if(ambos == 1)	{
		cout << "Ambos numeros se dividen entre si.\n"; 	
	}
	
	else	{
		
		primero = numero2 % numero1 == 0;
		
		if(primero == 1)	{
			cout << "El primer numero divide al segundo.\n";								
			}
		
		else	{
			
			segundo = numero1 % numero2 == 0;
			
			if(segundo == 1)	{
				
				cout << "El segundo numero divide al primero.\n";
			}
			
			else	{
				
				cout << "Los numeros introducidos no se dividen entre si.\n"; 
			}
		}
	}
	
	system("pause");
}
