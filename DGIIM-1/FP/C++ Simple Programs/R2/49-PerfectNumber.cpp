#include <iostream>

using namespace std;

int main ()	{
	
	int numero, divisor = 1, contador = 0, suma_divisores = 0, perfecto = 0;
	
	cout << "Introduzca un numero: ";
	cin >> numero;
	
	//Establece un contador que servirá para ir obteniendo los numeros menores que el introducido
	while (contador < numero)	{
		
		contador++;
		
		//Factoriza el numero y suma sus factores
		do {
			if (contador % divisor == 0)
				suma_divisores = suma_divisores + divisor;
				
			divisor++;
				
		} while (contador >= divisor);
		
		//Soluciona el fallo de que se sume el mismo numero
		suma_divisores = suma_divisores - contador;
		
		//Si es perfecto, lo establece y sobrescribe al anterior
		if (suma_divisores == contador)
			perfecto = divisor - 1;
		
		suma_divisores = 0;
		divisor = 1;
	}
	
	cout << "\n\n El mayor perfecto menor o igual al numero introducido es el " << perfecto;
	
}


