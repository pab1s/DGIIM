#include <iostream>

using namespace std;

int main ()	{
	
	int tope, divisor = 1;
	
	cout << "Introduzca un numero entero: ";
	cin >> tope;
	
	// Realiza el bucle hasta que el divisor sea igual al tope
	do {
		if (tope % divisor == 0)
			cout << divisor << " es un divisor de " << tope << ".\n";
			
		divisor++;
			
	} while (tope + 1 > divisor);
}
