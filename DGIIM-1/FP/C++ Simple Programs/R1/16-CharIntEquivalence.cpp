#include <iostream>

using namespace std;

int main () {
	
	char caracter;		//N�mero a introducir en forma de caracter
	int entero;			//Entero que dar� el n�mero introducido
	
	cout << "Introduzca un numero del 0 al 9: ";		//Entrada de datos
	cin >> caracter;
	
	entero = caracter - 48;								//Transformaci�n del caracter a entero
	
	cout << "El numero que ha introducido es el " << entero << ".";			//Salida de datos
}
