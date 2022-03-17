
#include <iostream>
using namespace std;

int main ()	{
	
	int x, k, z = 0, total = 0;
	
	cout << "Introduzca el numero de filas: ";
	cin >> k;
	
	double real [k][k], resultado[k];
	
	cout << "Ahora introduzca los numeros de la matriz por filas: " << endl;
	for (int i = 0; i < k; i++)
		for (int j = 0; j <= i; j++)	{
			cin >> real[i][j];
			real[j][i] = real[i][j];
			resultado[z] = real [i][j];
			z++;
		}
		
	for(int s = 1; s <= k; s++)	{	
		total += s;
	}
	
	for (int m = 0; m < total; m++)	{
			cout << resultado[m] << endl;
		}
}

