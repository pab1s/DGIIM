
#include <iostream>
#include <cmath>

using namespace std;

struct TipoPolinomio {																// Declaración de la estructura
	int x, a0, a1, a2, a3, solucion;
};

TipoPolinomio polinomio1, polinomio2, polinomio3;									// Estructuras a emplear

int main ()	{
	
	char opcion;																	// Caracter para elegir el método
	
	cout << "Elija el apartado (a, b o c): ";
	cin >> opcion;
	
	if (opcion == 'a')	{															// Opción A
		cout << "Introduzca el coeficiente de grado 3 del polinomio: ";				// Entrada de datos
		cin >> polinomio1.a3;
		cout << "Introduzca el coeficiente de grado 2 del polinomio: ";
		cin >> polinomio1.a2;
		cout << "Introduzca el coeficiente de grado 1 del polinomio: ";
		cin >> polinomio1.a1;
		cout << "Introduzca el coeficiente de grado 0 del polinomio: ";
		cin >> polinomio1.a0;
	
		cout << "El polinomio introducido es: " << polinomio1.a3 << "x^3 + " << polinomio1.a2 << "x^2 + " << polinomio1.a1 << "x + " << polinomio1.a0;		// Salida de datos
	}
	if (opcion == 'b')	{															// Opción B
		cout << "Introduzca el coeficiente de grado 3 del polinomio 1: ";			// Entrada de datos
		cin >> polinomio1.a3;
		cout << "Introduzca el coeficiente de grado 2 del polinomio 1: ";
		cin >> polinomio1.a2;
		cout << "Introduzca el coeficiente de grado 1 del polinomio 1: ";
		cin >> polinomio1.a1;
		cout << "Introduzca el coeficiente de grado 0 del polinomio 1: ";
		cin >> polinomio1.a0;
		
		cout << "Introduzca el coeficiente de grado 3 del polinomio 2: ";
		cin >> polinomio2.a3;
		cout << "Introduzca el coeficiente de grado 2 del polinomio 2: ";
		cin >> polinomio2.a2;
		cout << "Introduzca el coeficiente de grado 1 del polinomio 2: ";
		cin >> polinomio2.a1;
		cout << "Introduzca el coeficiente de grado 0 del polinomio 2: ";
		cin >> polinomio2.a0;		
	
		polinomio3.a3 = polinomio1.a3 + polinomio2.a3;								// Cálculos
		polinomio3.a2 = polinomio1.a2 + polinomio2.a2;
		polinomio3.a1 = polinomio1.a1 + polinomio2.a1;
		polinomio3.a0 = polinomio1.a0 + polinomio2.a0;
		
		cout << "El polinomio resultante de la suma de ambos es: " << polinomio3.a3 << "x^3 + " << polinomio3.a2 << "x^2 + " << polinomio3.a1 << "x + " << polinomio3.a0;		// Salida de datos
	}	

	if (opcion == 'c')	{															// Opción C
		cout << "Introduzca el coeficiente de grado 3 del polinomio: ";				// Entrada de datos
		cin >> polinomio1.a3;
		cout << "Introduzca el coeficiente de grado 2 del polinomio: ";
		cin >> polinomio1.a2;
		cout << "Introduzca el coeficiente de grado 1 del polinomio: ";
		cin >> polinomio1.a1;
		cout << "Introduzca el coeficiente de grado 0 del polinomio: ";
		cin >> polinomio1.a0;
	
		cout << "El polinomio introducido es: " << polinomio1.a3 << "x^3 + " << polinomio1.a2 << "x^2 + " << polinomio1.a1 << "x + " << polinomio1.a0 << endl;
		cout << "Introduzca un valor para x: ";
		cin >> polinomio1.x;
		
		polinomio1.solucion = polinomio1.a3 * pow(polinomio1.x, 3) + polinomio1.a2 * pow(polinomio1.x, 2) + polinomio1.a1 * polinomio1.x + polinomio1.a0;		// Cálculos
		
		cout << "El resultado del polinomio para el valor establecido de x es: " <<	polinomio1.solucion;		// Salida de datos
	}
	
	else
		cout << "No ha metido una de las opciones disponibles.";		// Salida de datos
}
