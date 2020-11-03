#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main ()	{
	
	char pais, hortaliza;
	int toneladas, ton_max, ton_esp = 0, ton_ale = 0, ton_fra = 0;
	string frase_resultado = "El pais que mas hortalizas ha vendido ha sido ";
	
	while (pais != '@')	{
		
		cout << "Introduzca el indicativo del pais ([E] Espana, [F] Francia o [A] Alemania: " << endl;
		cin >> pais;
		
		//Para el bucle si se introduce '@' para que no sea necesario pedir mas datos
		if (pais == '@')
			break;
		
		cout << "Introduzca el indicativo de la hortaliza ([E] Espinaca, [P] Patata o [T] Tomate: " << endl;
		cin >> hortaliza;
		cout << "Introduzca las toneladas vendidas: " << endl;
		cin>> toneladas;
		
		//Aumenta el numero de toneladas por pais
		if (pais == 'E')
			ton_esp = ton_esp + toneladas;
			
		if (pais == 'A')
			ton_ale = ton_ale + toneladas;

		if (pais == 'F')
			ton_fra = ton_fra + toneladas;
		
	}
	
	//Compara las toneladas para saber cual es el mayor
	ton_max = max(ton_esp, ton_ale);
	ton_max = max(ton_max, ton_fra);
	
	cout << "\n\n";
	
	//Muestra la solucion segun el pais que mas toneladas haya recolectado
	if (ton_max == ton_esp)
		cout << frase_resultado << "Espana con " << ton_max << " toneladas.";
		
	if (ton_max == ton_ale)
		cout << frase_resultado << "Alemania con " << ton_max << " toneladas.";
		
	if (ton_max == ton_fra)
		cout << frase_resultado << "Francia con " << ton_max << " toneladas.";
	
}
