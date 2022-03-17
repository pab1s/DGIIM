
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	int numero;							// Variable que recoge el n�mero
	int unidad, decena, centena;		// Variables que van a almacenar los d�gitos
	
	cout << "Introduzca un numero entero de tres digitos: ";		// Pide la introducci�n del n�mero
	cin >> numero;
	
	unidad = numero % 10;											// Obtenemos las unidades sacando el resto de dividir entre 10 el n�mero
	centena = numero / 100;											// Sacamos las centenas dividiendo el n�mero entre 100
	decena = (numero - centena * 100 - unidad) / 10;				// Obtenemos las centenas restando las unidades y las centenas y dividiendo entre 10
	
	cout << centena << "   " << decena << "   " << unidad;			// Muestra la soluci�n	
}
