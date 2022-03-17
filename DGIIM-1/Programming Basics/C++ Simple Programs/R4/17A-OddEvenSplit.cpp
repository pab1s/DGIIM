#include <iostream>
using namespace std;

//Separa en pares e impares e imprime el resultado por separado
void Separar(int vector[1000], int longitud, int pares[500], int impares[500]){

	int contadorPares = 0;
	int contadorImpares = 0;
	
	//Añade al par y al impar en su respectivo vector
	for (int i=0; i<longitud; i++){
		if(vector[i]%2 == 0){
			pares[contadorPares] = vector[i];
			contadorPares++;
		}
		
		else{
			impares[contadorImpares] = vector[i];
			contadorImpares++;
		}
	}
	
	//Salida
	cout << "El vector de los pares es:\n";
	for (int i=0; i<contadorPares; i++){
		cout << pares[i] << " ";
	}
	cout << "\nEl vector de los impares es:\n";
	for (int i=0; i<contadorImpares; i++){
		cout << impares[i] << " ";
	}
}
	
int main(){
	int original[1000], longitud;
	int pares[500];
	int impares[500];
	
	cout << "Introduce la longitud del vector: ";
	cin >> longitud;
	cout << "Introduce el vector separado por espacios: ";
	for (int i=0; i<longitud; i++){
		cin >> original[i];
	}
	
	Separar(original, longitud, pares, impares);	
}

