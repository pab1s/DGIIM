#include <iostream>
#include <cstring>

using namespace std;

int main () {
	
	int longitud = 0, a = 0;
	string cadena;
	char caracter;
	bool comprobador = false;
	
	cout << "Introduzca la cadena: ";
	cin >> cadena;
	
	//Lee la longitud de la cadena
	while(cadena[a] != '\0'){
		longitud++;
		a++;
	}
	
	cout << "Introduzca ahora el caracter a identificar: ";
	cin >> caracter;
	
	//Busca el caracter y comprueba si está
	for (int i = 0; i < longitud; i++)	{
		if (cadena[i] == caracter)
			comprobador = true;
	}
	
	if (comprobador == true)
		cout << "El caracter esta en la cadena.";
	else
		cout << "El caracter no esta en la cadena.";
}
