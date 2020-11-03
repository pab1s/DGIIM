#include <iostream>

using namespace std;

int Perfecto (int num) {
	
	int divisor = 1, suma_divisores = 0, perfecto = 0;
		
		//Factoriza el numero y suma sus factores
		do {
			if (num % divisor == 0)
				suma_divisores = suma_divisores + divisor;
				
			divisor++;
				
		} while (num >= divisor);
		
		//Soluciona el fallo de que se sume el mismo numero
		suma_divisores = suma_divisores - num;
		
		//Si es perfecto, lo establece y sobrescribe al anterior
		if (suma_divisores == num)
			perfecto = divisor - 1;
		
		suma_divisores = 0;
		divisor = 1;
		
		return (perfecto);
}

int main ()	{
	
	int numero;
	
	cout << "Introduzca un numero: ";
	cin >> numero;
	cout << "\nLos numeros perfectos menores o iguales que " << numero << " son: ";
	for (int i = 1; i <= numero; i++) {
		if (Perfecto(i) != 0)
			cout << Perfecto(i) << " ";
	}
	
}

