#include <iostream>
#include <cstdlib>

using namespace std;

int main () {
	
	//Dimensión máxima del vector: 100
	const int DIM = 100;
	int vector1[DIM], vector2[DIM], vector[DIM], longitud1, longitud2, longitud, aux, y;
	
	cout << "Introduzca la longitud del primer vector (max = 100): ";
	cin >> longitud1;
	cout << "Introduzca la longitud del segundo vector (max = 100): ";
	cin >> longitud2;
	
	cout << "Introduzca los elementos del vector 1:\n";
	for (int i = 0; i < longitud1; i++)
		cin >> vector1[i];
	
	cout << "Introduzca los elementos del vector 2:\n";
	for (int j = 0; j < longitud2; j++)
		cin >> vector2[j];
	
	longitud = longitud1 + longitud2 + 1;
	
	for (int k = 0; k < longitud; k++)	{
		
		if (k <= longitud1)
			vector[k] = vector1[k];
			
		if (k > longitud1)
			vector[k] = vector2[k - longitud1];
	}
	
	for (int w=0; w<(longitud-1); w++)
	{
	   for (y=w+1; y<longitud; y++)
	  {
	    if(vector[w]>vector[y])
	    {
	     aux = vector[w];
	     vector[w] = vector[y];
	     vector[y] = aux;
	    }
	  }
	}
	
	for (int n = 0; n < longitud - 1; n++)
		cout << vector[n] << " ";
}
