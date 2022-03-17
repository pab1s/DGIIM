#include <iostream>

using namespace std;

int main ()	{
	
	int n, m, impares = 0;
	
	cout << "Introduzca el primer factor: ";
	cin >> n;
	cout << "Introduzca el segundo factor: ";
	cin >> m;
	
	//Detiene el bucle cuando no sea posible seguir dividiendo
	 while (n != 1)	{
	 	
	 	//Aumenta el sumatorio de la imagen de los impares
	 	if (n % 2 == 1)
	 		impares = impares + m;
	 		
	 	n = n / 2;
	 	m = m * 2;
	 }
	
	//Soluciona que no se sume el ultimo numero
	impares = impares + m;
	
	cout << "La solucion del producto ruso es: " << impares;
}
