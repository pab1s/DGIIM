#include <iostream>
#include <cmath>

using namespace std;

int main ()	{
	
	int numero_inicial, numero_transitorio, narcisista, base, exponente;
	
	exponente = 0;
	narcisista = 0;
	
	//Pide un numero positivo hasta que el introducido lo sea
	do {
		cout << "Introduzca un numero entero positivo: ";
		cin >> numero_inicial;
	} while (numero_inicial < 0);
	
	numero_transitorio = numero_inicial;
	
	//Calcula el exponente
	for (int i = numero_inicial; i > 0; exponente++)	{
		i = i / 10;
	}
	
	//Realiza las operaciones
	for (int j = 0; j < exponente; j++)	{
		base = numero_transitorio % 10;
		numero_transitorio = numero_transitorio / 10;
		narcisista = narcisista + pow(base * 1.0, exponente);
	}
	
	//Comprueba si el numero introducido es narcisista o no
	if (narcisista == numero_inicial)
		cout << "El numero introducido es narcisista.";
		
	else
		cout << "El numero introducido no es narcisista.";
}
