
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	double altura1;			// Usamos las variables de altura para la introducción de datos
	double altura2;
	double altura3;
	double media;			// Para los resultados empleamos el de media y desviacion
	double desviacion;
	
	cout << "Introduzca la altura de la primera persona: ";			// Pide la introducción de las variables
	cin >> altura1;
	cout << "Introduzca la altura de la segunda persona: ";
	cin >> altura2;
	cout << "Introduzca la altura de la tercera persona: ";
	cin >> altura3;
	
	media = (altura1 + altura2 + altura3) / 3;																	// Realiza las operaciones necesarias
	desviacion = sqrt( (pow(altura1 - media, 2) + pow(altura2 - media, 2) + pow(altura3 - media, 2) ) / 3 );
	
	cout << "La media de las alturas es " << media << " y la desviacion tipica es " << desviacion;				// Da los resulltados al usuario
}
