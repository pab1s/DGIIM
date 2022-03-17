/************************************************************************************
 * PROYECTO PGM: MODULO CONTRASTE.EXE - INFORMACION
 * **********************************************************************************
 * AUTOR: MARCOS RICO GUERRA
 * NOMBRE ARCHIVO: CONTRASTE.EXE
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

//Vuelve cada pixel blanco o negro según su cercanía a 255 o 0
void Contraste(Imagen imagen, Imagen & contraste){
	contraste.P2 = imagen.P2;
	contraste.filas = imagen.filas;
	contraste.columnas = imagen.columnas;
	contraste.brillo_max = imagen.brillo_max;
	
	for (int i = 0; i < imagen.filas; i++)
		for (int j = 0; j < imagen.columnas; j++){
			if (imagen.matriz[i][j] < 125)
				contraste.matriz[i][j] = 0;
			else
				contraste.matriz[i][j] = 255;
		}
	}
	
int main(){

	Imagen imagen;
	Imagen contraste;
	
	EntradaImagen(imagen);
	Contraste(imagen, contraste);
	SalidaImagen(contraste);
}
