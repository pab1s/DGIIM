/Este programa comprobara si una matriz cuadrada es magica mediante una funcion

#include <iostream>
using namespace std;

//Funcion que suma las filas, columnas y diagonal. Si da lo misma, sera magica
void CuadradoMagico( int matriz[100][100], int dimension){
	int suma, comprobar;
	bool cuadradomagico;
	
	suma = comprobar = 0;
	cuadradomagico = true;
	
	for (int i=0; i<dimension; i++)
		suma = suma + matriz[i][1];	
		
	for (int j=0; j< dimension; j++){
		for (int k=0; k<dimension; k++)	
			comprobar = comprobar + matriz[j][k];
		if (comprobar != suma)
			cuadradomagico = false;
		comprobar = 0;
	}
	
	for (int l=0; l<dimension; l++){
		for (int m=0; m<dimension; m++)	
		 comprobar = comprobar + matriz[m][l];
		if (comprobar != suma)
			cuadradomagico = false;
		comprobar = 0;
	}
		
	for (int n=0; n<dimension; n++){
		comprobar = comprobar + matriz[n][n];	
		if (comprobar != suma)
			cuadradomagico = false;	
	}
	
	if (!cuadradomagico)
		cout << "La matriz no es un cuadrado magico ";
	if (cuadradomagico)
		cout << "La matriz es un cuadrado magico ";
}

int main (){
	int dimension, suma, comprobar;
	int matriz[100][100];
	bool cuadradomagico;
	
	//Se introducen los datos
	cout << "Introduzca las filas/columnas que tiene la matriz cuadrada: ";
	cin >> dimension;
	cout << "Introduzca los valores de la matriz cuadrada: ";
	for (int i=0; i<dimension; i++)
		for (int j=0; j< dimension; j++)
			cin >> matriz[i][j];
	
	//Se emplea la funcion	
	CuadradoMagico( matriz, dimension);
	
}
