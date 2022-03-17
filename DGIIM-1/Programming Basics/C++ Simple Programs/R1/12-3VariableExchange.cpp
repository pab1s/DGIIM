
#include <iostream>

using namespace std;

int main () {
	
	int x, y, z;		//Variables
	int cambio;			//Variable que usaremos para hacer el cambio
	
	x = 10;				//Valor inicial aplicado a cada variable
	y = 20;
	z = 30;
	
	cambio = x;			//Proceso de intercambio de variables		
	x = z;
	z = y;
	y = cambio;
	
	cout << "Valor X: " << x;		//Salida de resultados
	cout << "\nValor Y: " << y;
	cout << "\nValor Z: " << z;
}
