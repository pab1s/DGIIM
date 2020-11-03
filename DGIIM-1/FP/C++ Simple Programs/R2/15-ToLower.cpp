
#include <iostream>

using namespace std;

int main () {
	
	char letra;
	int conversor;
	bool check;
	
	//Pide que se introduzca una mayúscula hasta que sea introducido un carácter válido
	do {
		cout << "Introduzca una letra mayuscula: ";
		cin >> letra;
		check = (letra >= 'A' && letra <= 'Z');
		
	} while (check == 0);
	
	//Proceso de conversión
	conversor = letra;
	conversor = conversor + 32;
	letra = conversor;
	
	cout << "La letra minuscula es " << letra << ".";
}
