
#include <iostream>

using namespace std;

int main ()	{
	
	int a, b, c;
	
	cout << "Introduzca el primer numero: ";					// Pide la entrada de datos
	cin >> a;
	cout << "Introduzca el segundo numero: ";
	cin >> b;
	cout << "Introduzca el tercero numero: ";
	cin >> c;
	
	bool ordenado = ((a < b) && (b > c)) ||						// Comprueba si los numeros estan en orden
				    ((a > b) && (b < c));	
	
	if (ordenado == 0)											// Si estan en orden, saldrá esta respuesta
		cout << "Los numeros estan ordenados.";

	else
		cout << "Los numeros no estan ordenados.";					// En caso adverso, saldrá esta
}
