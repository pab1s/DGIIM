
#include <iostream>

using namespace std;

int main () {
	
	int numero, numero_invertido, digito;
	
	cout << "Introduzca un numero entero: ";
	cin >> numero;	
	cout << "El numero separado en digitos es: ";
	
	//Le da la vuelta al numero, si no se hace, muestra los digitos al reves
	for (int i = numero; i > 0; i = i / 10)	{
		
		digito = i % 10;
		numero_invertido = numero_invertido * 10 + digito;
	}
	
	//Imprime los digitos separados por espacios
	for (int j = numero_invertido; j > 0; j = j / 10)	{
		
		digito = j % 10;
		
		cout << digito << " ";
	}
}
