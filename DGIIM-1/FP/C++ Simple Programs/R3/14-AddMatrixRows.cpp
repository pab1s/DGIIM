
#include <iostream>
using namespace std;

int main ()	{
	
	int x, y;
	
	cout << "Introduzca el numero de filas: ";
	cin >> x;
	cout << "Introduzca el numero de columnas: ";
	cin >> y;
	
	double real [x][y], resultado[x];
	
	cout << "Ahora introduzca los numeros de la matriz por filas: " << endl;
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			cin >> real[j][i];
	
	for (int k = 0; k < y; k++)	{
		for (int l = 0; l < x; l++)
			resultado[k] += real[l][k];

		cout << resultado[k] << endl;
	}
}
