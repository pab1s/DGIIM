/************************************************************************************
 * PROYECTO PGM: MODULO NEGATIVO.EXE - INFORMACION
 * **********************************************************************************
 * AUTOR: PABLO OLIVARES MARTÍNEZ
 * NOMBRE ARCHIVO: NEGATIVO.EXE
 * **********************************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 650;

//Almacena los datos de la matriz inicial y la final
struct Imagen{
	string P2;
	int filas;
	int columnas;
	int brillo_max;
	int matriz[MAX][MAX];
};

//Recibe los valores que definen la imagen
void EntradaImagen(Imagen &imagen){
	cin >> imagen.P2;
	cin >> imagen.columnas;
	cin >> imagen.filas;
	cin >> imagen.brillo_max;
	for (int i = 0; i < imagen.filas; i++)
		for (int j = 0; j < imagen.columnas; j++)
			cin >> imagen.matriz[i][j];
}

//Devuelve la imagen final
void SalidaImagen (Imagen imagen){
	cout << imagen.P2 << endl;
	cout << imagen.columnas << " " << imagen.filas << endl;
	cout << imagen.brillo_max;
	
	for (int i = 0; i < imagen.filas; i++){
		cout << endl;
		for (int j = 0; j < imagen.columnas; j++)
			cout << imagen.matriz[i][j] << " ";
	}
}

//Invierte los colores de la imagen
void Negativo(Imagen imagen, Imagen &negativo){
	negativo.P2 = imagen.P2;
	negativo.filas = imagen.filas;
	negativo.columnas = imagen.columnas;
	negativo.brillo_max = imagen.brillo_max;
	
	for (int i = 0; i < imagen.filas; i++)	{
		for (int j = 0; j < imagen.columnas; j++)
			negativo.matriz[i][j] = 255 - imagen.matriz[i][j];
	}
}

int main () {
	
	Imagen imagen;
	Imagen negativo;
	
	EntradaImagen(imagen);
	Negativo(imagen, negativo);
	SalidaImagen(negativo);
}
