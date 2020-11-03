
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	int dias, horas, minutos, segundos;					// Declaramos los enteros que vamos a emplear
	
	cout << "Introduzca el numero de horas: ";			// Introducción de variables
	cin >> horas;
	cout << "Introduzca el numero de minutos: ";
	cin >> minutos;
	cout << "Introduzca el numero de segundos: ";
	cin >> segundos;
	
	minutos = minutos + (segundos / 60);				// Calculamos los valores
	segundos = segundos % 60;
	horas = minutos / 60 + horas;
	minutos = minutos % 60;
	dias = horas / 24;
	horas = horas % 24;
	
	cout << "El resultado es " << dias << " dias, " << horas << " horas," << minutos << " minutos y " << segundos << " segundos.";		// Mostramos el resultado al usuario
}
