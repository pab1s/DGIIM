#include <iostream>
//Esta libreria nos permite encontrar el maximo de dos numeros facilmente
#include <algorithm>

using namespace std;

int main ()	{
	
	int sucursal = 0, producto, unidades;
	int suma1 = 0, suma2 = 0, suma3 = 0, maxsuma, maxsucursal;
	
	//Introducción de datos que se añaden a una base de datos hasta que se introduzca -1
	while (sucursal != -1) {
		cout << "INTRODUZCA EL IDENTIFICADOR DE SU SUCURSAL (1, 2 o 3): ";
		cin >> sucursal;
		cout << "INTRODUZCA EL CODIGO DEL PRODUCTO (1, 2 o 3): ";
		cin >> producto;
		cout << "INTRODUZCA EL NUMERO DE PRODUCTOS VENDIDOS: ";
		cin >> unidades;
		
		if (sucursal == 1)
			suma1 = suma1 + unidades;
		
		if (sucursal == 2)
			suma2 = suma2 + unidades;

		if (sucursal == 3)
			suma3 = suma3 + unidades;		
	}
	
	//Cálculo de la sucursal que más productos ha vendido
	maxsuma = max(suma1, suma2);
	maxsuma = max(maxsuma, suma3);
	
	if (suma1 == maxsuma)
		maxsucursal = 1;

	if (suma2 == maxsuma)
		maxsucursal = 2;

	if (suma3 == maxsuma)
		maxsucursal = 3;

	cout << "\nLA SUCURSAL QUE MAS PRODUCTOS HA VENDIDO ES: " << maxsucursal;
	cout << "\nEL NUMERO DE PRODUCTOS VENDIDOS POR ESTA SUCURSAL ES: " << maxsuma;
	
}
