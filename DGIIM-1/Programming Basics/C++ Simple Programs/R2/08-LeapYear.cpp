
#include <iostream>

using namespace std;

int main ()	{
	
	int ano;				// A�o introducido
	bool bisiesto;			// Comprueba si el a�o es bisiesto
	
	cout << "Introduzca la fecha de un ano: ";		// Entrada de variables
	cin >> ano;
	
	bisiesto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);		//Declara las condiciones para que sea bisiesto
	
	if (bisiesto == 1)								// Si es bisiesto, dir� eso
		cout << "El ano es bisiesto.";
	
	else											// Si no lo es, dir� esto
		cout << "El ano no es bisiesto.";
}
