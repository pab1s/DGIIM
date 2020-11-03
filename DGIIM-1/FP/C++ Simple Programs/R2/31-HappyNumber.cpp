#include <iostream>

using namespace std;

int main ()	{
	
	int numero, nuevo_numero, suma = 0, cifra, cuadrado;
	bool feliz = 0;
	
	cout << "Introduzca un numero: ";
	cin >> numero;
	
	nuevo_numero = numero;
	
	//Realiza la comprobación de si es feliz hasta que es un dígito
	do	{
		
		suma = 0;
		
		//Realiza la operación para saber si es feliz
		for (int i = nuevo_numero; i > 0; i = i / 10)	{
			
			cifra = i % 10;
			cuadrado = cifra * cifra;
			suma = suma + cuadrado;	
		}
		
		//Muestra el resultado si es feliz
		if (suma == 1)	{
			
			cout << numero << " es un numero feliz.";
			feliz = 1;
		}
		
		//Sirve para realizar lo operación 'feliz' si el número tiene dos digitos o mas
		nuevo_numero = suma;
		
		//Si solo tiene un digito, sale del bucle
		if (suma > 0 && suma < 10)
			suma = suma / 10;
			
	} while (suma > 1);
	
	//Indica que no es feliz
	if (feliz == 0)
		cout << numero << " no es un numero feliz.";
}
