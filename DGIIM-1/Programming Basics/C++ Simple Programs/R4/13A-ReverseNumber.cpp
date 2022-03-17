
#include <iostream>

using namespace std;

int Inverso(int num)	{
	
	int numero_invertido, digito;

	//Le da la vuelta al numero, si no se hace, muestra los digitos al reves
	for (int i = num; i > 0; i = i / 10)	{
		
		digito = i % 10;
		numero_invertido = numero_invertido * 10 + digito;
	}

	return (numero_invertido);
}

int main () {
	
	int numero;
	
	cout << "Introduzca un numero entero: ";
	cin >> numero;	
	cout << "El numero invertido es: ";
	cout << Inverso(numero);
}
