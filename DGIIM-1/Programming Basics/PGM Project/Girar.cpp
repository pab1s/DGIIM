/************************************************************************************
 * PROYECTO PGM: MODULO GIRAR.EXE - INFORMACION
 * **********************************************************************************
 * AUTOR: MARCOS RICO GUERRA
 * NOMBRE ARCHIVO: ROTAR.EXE
 * **********************************************************************************/

#include <iostream>
#include <string>

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
void EntradaImagen(Imagen & imagen){
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

//Rota la imagen 90º hacia la derecha
void Girar (Imagen imagen, Imagen &girada){
	girada.P2 = imagen.P2;
	girada.filas = imagen.columnas;
	girada.columnas = imagen.filas;
	girada.brillo_max = imagen.brillo_max;
	
	for ( int i = 0; i < girada.filas; i++)
		for (int j = 0; j < girada.columnas; j++)
			girada.matriz[i][j] = imagen.matriz[imagen.filas - 1 - j][i];	
}

int main(){
	
	Imagen imagen, girada;
	
	EntradaImagen(imagen);
	Girar(imagen, girada);
	SalidaImagen(girada);
}
