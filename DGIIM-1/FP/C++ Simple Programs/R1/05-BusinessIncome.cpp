
#include <iostream>

using namespace std;

int main () {
	
	double ingreso;			// Declara las variables a emplear
	double disenador;
	double trabajador;
	
	cout << "Indique los ingresos obtenidos en euros: ";		// Pide al usuario los ingresos totales de la empresa
	cin >> ingreso;
	
	trabajador = ingreso / 5;		// Operaci�n que distribuye los ingresos seg�n indica el enunciado
	disenador = trabajador * 2;
	
	cout << "El disenador ha ingresado " << disenador << " euros." << endl;						// Muestra al usuario la ganancia de cada individuo
	cout << "Cada fabricante ha ingresado " << trabajador << " euros, habiendo 3 fabricantes.";
}
