
#include <iostream>

using namespace std;

int main () {
	
	char letra;			//Caracter a introducir en mayusculas
	int conversor;		//Entero que usaremos para convertirlo a  minusculas
	
	cout << "Introduzca una letra mayuscula: ";		//Entrada de datos
	cin >> letra;
	
	conversor = letra;								//Proceso de conversión
	conversor = conversor + 32;
	letra = conversor;
	
	cout << "La letra minuscula es " << letra << ".";		//Salida del resultado
}
