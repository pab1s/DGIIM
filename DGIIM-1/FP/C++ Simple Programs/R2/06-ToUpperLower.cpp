
#include <iostream>

using namespace std;

int main ()	{
	
	const int difmayusminus = 'a' - 'A';		// Constante que muestra la diferencia entre una letra y su mayuscula
	char letra_original, letra_convertida;		// Declaración de los carácteres a emplear
	bool es_mayuscula, es_minuscula;			// Boolean que comprueba si es mayuscula o minuscula
	
	cout << "Introduzca una letra: ";			// Introducción de variables
	cin >> letra_original;
	
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');			// Comprueba si es mayuscula o minuscula
	es_minuscula = (letra_original >= 'a') && (letra_original <= 'z');
	
	if (es_mayuscula == 1)	{							// En caso de ser mayuscula, hace el cambio a minúscula	
		
		letra_convertida = letra_original + difmayusminus;							// Proceso de conversión
		
		cout << "La minuscula de la letra introducida es: " << letra_convertida;	// Salida de la solución
	}
	
	if (es_minuscula == 1)	{							// En caso de ser minuscula, hace el cambio a mayuscula	
		
		letra_convertida = letra_original - difmayusminus;							// Proceso de conversión
		
		cout << "La mayuscula de la letra introducida es: " << letra_convertida;	// Salida de la solución
	}
}
