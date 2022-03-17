/************************************************************************************
 * PROYECTO PGM: MODULO BLANQUEAR.EXE - INFORMACION
 * ********************************************************************************** 
 * AUTOR: PABLO OLIVARES MARTÍNEZ
 * NOMBRE ARCHIVO: BLANQUEAR.EXE
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

//Vuelve la imagen blanca al completo
void Blanquear(Imagen imagen, Imagen &blanca){
	blanca.P2 = imagen.P2;
	blanca.filas = imagen.filas;
	blanca.columnas = imagen.columnas;
	blanca.brillo_max = imagen.brillo_max;
	
	for (int i = 0; i < blanca.filas; i++)	{
		for (int j = 0; j < blanca.columnas; j++)
			blanca.matriz[i][j] = 255;
	}
}

int main () {
	
	Imagen imagen;
	Imagen blanca;
	
	EntradaImagen(imagen);
	Blanquear(imagen, blanca);
	SalidaImagen(blanca);
}
