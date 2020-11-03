
#include <iostream>
#include <cmath>

using namespace std;

int main () {
	
	int precio, dinero, euros, cincuenta, veinte, diez, cinco;
	
	cout << "Introduzca el valor del producto en centimos: ";			// Introducimos las variables, dando por hecho que el cambio será múltiplo de 5
	cin >> precio;
	cout << "Introduzca el dinero depositado en centimos: ";
	cin >> dinero;
	
	dinero = dinero - precio;											// Realizamos el cálculo de la división de monedas que vamos a recibir
	euros = dinero / 100;
	dinero = dinero - euros * 100;
	cincuenta = dinero / 50;
	dinero = dinero - cincuenta * 50;
	veinte = dinero / 20;
	dinero = dinero - veinte * 20;
	diez = dinero / 10;
	dinero = dinero - diez * 10;
	cinco = dinero / 5;
	dinero = dinero - cinco * 5;
	
	cout << "Salen a devolver las siguientes monedas: " << euros << " de 1 euro, " << cincuenta << " de 50cts, " << veinte << " de 20cts, " << diez << " de 10cts y " << cinco << " de 5cts.";
}
