
#include <iostream>

using namespace std;

int main ()	{
	
	char letra_original, letra_convertida;		// Declaraci�n de los car�cteres a emplear
	
	cout << "Introduzca una letra: ";			// Introducci�n de variables
	cin >> letra_original;
	
	bool detector = letra_original > 64 && letra_original < 91;		// Comprueba si es mayuscula la letra introducida
	
	if (detector == 1)							// En caso de ser mayuscula, hace el cambio a min�scula	
		letra_convertida = letra_original + 32;	// Proceso de conversi�n
	
	else										// En caso de que sea min�scula, la copia a la soluci�n
		letra_convertida = letra_original;
		
	cout << "La letra minuscula es: " << letra_convertida;			// Salida de la soluci�n
}
