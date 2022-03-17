#include <iostream>

using namespace std;

int main () {
	
	int cifra, min, max, contador_cifras = 0;
	
	//Introducción de datos de forma que cummplen las condiciones requeridas
	do {
		cout << "Introduzca la cifra que desea contar (del 1 al 9): ";
		cin >> cifra;
	} while (cifra < 1 && cifra > 9);
	
	cout << "Ahora, establezca el intervalo en el que desea contarlo." << endl;
	cout << "Introduzca el minimo del intervalo incluido: ";
	cin >> min;
	
	do{
	cout << "Introduzca el maximo del intervalo incluido: ";
	cin >> max;
	} while (max < min);
	
	//Realiza el conteo de cifras
	for (int i = min; i <= max; i++)	{
		
		int copia_i = i;
		
		//Confierte el numero negativo en positivo para que lo cuente
		if (copia_i < 0)
			copia_i = - copia_i;
		
		//Aumenta el contador de cifras si coincide
		while (copia_i > 0)	{
			
			if (copia_i % 10 == cifra)
				contador_cifras++;
				
			copia_i = copia_i / 10;
		}
	}
	
	cout << "El numero de " << cifra << " que hay en el intervalo es de " << contador_cifras << ".";
	
}
