
#include <iostream>

using namespace std;

int main () {
	
	char letra;
	int conversor;
	bool check;
	
	//Pide que se introduzca una may�scula hasta que sea introducido un car�cter v�lido
	do {
		cout << "Introduzca una letra mayuscula: ";
		cin >> letra;
		check = (letra >= 'A' && letra <= 'Z');
		
	} while (check == 0);
	
	//Proceso de conversi�n
	conversor = letra;
	conversor = conversor + 32;
	letra = conversor;
	
	cout << "La letra minuscula es " << letra << ".";
}
