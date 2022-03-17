/* Este programa dira que dos palabras son iguales si tienen la primera 
y ultima letra iguales y el resto de letras de una de las palabras estan 
en la otra, sin importar el orden*/

#include <iostream>
using namespace std;

//Esta funcion comprueba las condiciones y devuelve el resultado por pantalla
void Palabra (int longitud1, int longitud2, char palabra1[], char palabra2[]){
	bool mismapalabra, encontrado;
	
	mismapalabra = true; 
	
	if (longitud1 != longitud2)
		mismapalabra = false;
	if (palabra1[0] != palabra2[0])
		mismapalabra = false;
	if (palabra1[longitud1 - 1] != palabra2[longitud2 - 1])
		mismapalabra = false;
		
	for (int i=0; i<longitud1;	i++){
		encontrado = false;
		for (int j=0; j<longitud2; j++)
			if (palabra1[i] == palabra2[j])
				encontrado = true;
		if (encontrado = false)
			mismapalabra = false;
	}
	
	if (mismapalabra)
		cout << "Las palabras son inguales";
	if (!mismapalabra)
		cout << "Las palabras no son inguales";
}

int main (){
	int longitud1, longitud2;
	char palabra1[100];
	char palabra2[100];
	bool mismapalabra, encontrado;
	
	//Se introducen las palabras y sus longitudes 
	cout << "Introduce la cantidad de letras de la primera palabra: "; 
	cin >> longitud1;
	cout << "Introduce la cantidad de letras de la segunda palabra: ";
	cin >> longitud2;
	
	cout << "Introduce la primera palabra: ";
	for (int i=0; i< longitud1; i++)
		cin >> palabra1[i];	
	cout << "Introduce la segunda palabra: ";
	for (int j=0; j< longitud2; j++)
		cin >> palabra2[j];
		
	//Se utiliza la funcion
	Palabra(longitud1, longitud2, palabra1, palabra2);
	
}
