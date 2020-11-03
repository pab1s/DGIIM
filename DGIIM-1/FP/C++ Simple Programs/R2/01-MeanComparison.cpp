
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	int altura1, altura2, altura3;			// Usamos las variables de altura para la introducción de datos
	double media, desviacion;			// Para los resultados empleamos el de media y desviacion
	
	cout << "Introduzca la altura de la primera persona: ";			// Pide la introducción de las variables
	cin >> altura1;
	cout << "Introduzca la altura de la segunda persona: ";
	cin >> altura2;
	cout << "Introduzca la altura de la tercera persona: ";
	cin >> altura3;
	
	media = (altura1 + altura2 + altura3) / 3.0;																	// Realiza las operaciones necesarias
	desviacion = sqrt( (pow(altura1 - media, 2) + pow(altura2 - media, 2) + pow(altura3 - media, 2) ) / 3 );
	
	cout << "La media de las alturas es " << media << " y la desviacion tipica es " << desviacion << "\n";				// Da los resulltados al usuario
	
	if (altura1 < media) {										//Los if se encargarán de mostrar al usuario la solución correcta según la situación
	cout << altura1 << " es menor que la media.\n";
	}

	if (altura1 >= media) {
	cout << altura1 << " es mayor o igual a la media.\n";
	}

	if (altura2 < media) {
	cout << altura2 << " es menor que la media.\n";
	}
	
	if (altura2 >= media) {
	cout << altura2 << " es mayor o igual a la media.\n";
	}

	if (altura3 < media) {
	cout << altura3 << " es menor que la media.\n";
	}
	if (altura3 >= media) {
	cout << altura3 << " es mayor o igual a la media.\n";
	}
}
