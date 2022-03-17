#include <iostream>

using namespace std;

int main ()	{
	
	//long long int para que recoja el numero completo sin que desborde
	long long int numero;
	int dorsal, equipo1 = 0, equipo2 = 0;
	
	//Hace la operación hasta que se decida terminar introduciendo -1
	do {
		
		cout << "Introduzca la secuencia de puntos y dorsales (-1 para finalizar): ";
		cin >> numero;
		
		//Hace la operacion mientras el numero que se va descomponiendo sea mayor que 0
		for (long long int i = numero; i > 0; i = i / 100)	{
			
			//Obtiene el dorsal
			dorsal = (i % 100) / 10;
			
			//Atribuye la puntuacion al equipo segun el dorsal
			if (dorsal == 1 || dorsal == 2 || dorsal == 3)
				equipo1 = equipo1 + (i % 10);
				
			if (dorsal == 4 || dorsal == 5 || dorsal == 6)
				equipo2 = equipo2 + (i % 10);
			
		}
		
	} while (numero > -1);
	
	//Dice el resultado
	if (equipo1 > equipo2)
		cout << "Ha ganado el equipo 1.";
		
	if (equipo1 < equipo2)
		cout << "Ha ganado el equipo 2.";

	if (equipo1 == equipo2)
		cout << "Ambos equipos han empatado.";
	
}
