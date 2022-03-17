#include <iostream>

using namespace std;

int main ()	{
	
	int dato, minimo, contador = 0;
	
	// Realiza el bucle hasta que el dato introducido sea 0
	do {
		cout << "Introduzca un numero entero: ";
		cin >> dato;
		
		// Aumenta en 1 el contador por cada vez que se hace el bucle
		contador++;
		
		// Establece el  menor valor a minimo
		if (minimo > dato)
			minimo = dato;
			
	} while (dato != 0);

	cout << "Ha introducido la siguiente cantidad de numeros: " << contador << endl;
	cout << "El minimo de ellos es " << minimo << ".";
}
