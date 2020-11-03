
#include <iostream>

using namespace std;

int main ()	{
	
	char letra_original, letra_convertida;		// Declaración de los carácteres a emplear
	
	cout << "Introduzca una letra: ";			// Introducción de variables
	cin >> letra_original;
	
	bool detector = letra_original > 64 && letra_original < 91;		// Comprueba si es mayuscula la letra introducida
	
	if (detector == 1)							// En caso de ser mayuscula, hace el cambio a minúscula	
		letra_convertida = letra_original + 32;	// Proceso de conversión
	
	else										// En caso de que sea minúscula, la copia a la solución
		letra_convertida = letra_original;
		
	cout << "La letra minuscula es: " << letra_convertida;			// Salida de la solución
}
