
#include <iostream>
#include <cstring>

using namespace std;

int main (){
	string sugerencia, nombre;
	int n, contador, caracter, siguiente, longitud;
	bool espacio;
	
	//Se intoducen las palabras y K
	cout << "Introduzca el nombre:";
	getline(cin, nombre);
	cout << "Introduzca N: ";
	cin >> n;

	contador=0;
	while(nombre[contador] != '\0'){
		longitud++;
		contador++;
	}
	
	//Se cogen las K letras de cada palabra que esta separada por espacios de las demas
	contador = caracter = 0;
	espacio = false;
	while(nombre[caracter] != '\0'){
		if(!espacio){
			while(contador < n){
				if(nombre[contador] != ' '){
					sugerencia+= tolower(nombre[contador]);
				}
				contador++;
			}
		}
		
		if(nombre[caracter] == ' '){
			espacio = true;
			siguiente = caracter+1;
			contador=0;
			do{	
				sugerencia += tolower(nombre[siguiente]);
				contador++;
				siguiente++;
				if(nombre[siguiente] == ' ' || nombre[siguiente] == '\0'){
					siguiente++;
					contador = n;
				}
			}while(contador<n);
		}
		caracter++;
	}

	cout << "El nombre sugerido para el usuario es: " << sugerencia ;
}
