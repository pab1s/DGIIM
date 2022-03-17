#include <iostream>
#include <cmath>

using namespace std;

int main ()	{
	
	int parte1, parte2, numero, torn, divisor = 10;
	
	cout << "Introduzca un numero: ";
	cin >> numero;
	
	// Comprueba si el número es desgarrable o no y por dónde en caso afirmativo
	do {
		parte1 = numero % divisor;
		parte2 = numero / divisor;
		torn = pow(parte1 + parte2, 2);
		divisor = divisor * 10;
	} while (numero != torn && parte2 > 0);
	
	// En caso afirmativo, lo muestra al usuario
	if (numero == torn)
		cout << "El numero " << numero << " es desgarrable por " << parte2 << " y " << parte1 << ".";
	
	// En caso negativo, también lo dice	
	else
		cout << "El numero no es desgarrable.";
		
	
}
