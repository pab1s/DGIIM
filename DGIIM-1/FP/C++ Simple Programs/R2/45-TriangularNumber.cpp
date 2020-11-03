#include <iostream>

using namespace std;

int main ()	{
	
	int entero, suma = 0, triangulares = 0;
	
	cout << "introduzca un entero del cual quiera saber todos los numeros triangulares anteriores: ";
	cin >> entero;
	
	//Toma todos los numeros menores o iguales al introducido para comprobar si son triangulares
	for (int i = 1; i <= entero; i++)	{
		
		//Comprueba si el numero es triangular
		for (int j = 0; j < i; j++)	{
	
			suma = suma + j;
			
			if (suma == i)
				triangulares++;
		}
		
		//Resetea la suma	
		suma = 0;		
	}
	
	cout << "La cantidad de numeros triangulares previos o iguales a " << entero << " es de " << triangulares << ".";
	
}
