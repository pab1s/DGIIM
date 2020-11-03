#include <iostream>

using namespace std;

int main ()	{
	
	int numero = 0, minimo = 101, maximo = -1, contador = 0, anterior = -1, orden, inicial, posicion = 0, posicion_inicial = 0, posicion_minimo;
	
	cout << "Introduzca la sucesion: ";
	
	//Se asegura de que los numeros de la sucesion se encuentran en la cota
	while (numero >= 0 && numero <= 100)	{
		
		cin >> numero;
		
		posicion++;
		
		//Establece el menor numero de los introducidos y resetea el contador
		if (numero < minimo)	{
			
			posicion_minimo = posicion;		
			minimo = numero;
			contador = 1;
			maximo = -1;
		}
		
		if (numero >= anterior)	{
			contador++;
			
			//Establece el maximo numero de los introducidos
			if (numero > maximo)
				maximo = numero;

			/*Comprueba qué sucesión es más grande de entre las que se
			 encuentran en los numeros introducidos y lo establece*/
			if (contador > orden)	{
				posicion_inicial = posicion_minimo;
				inicial = minimo;
				orden = contador;
			}
		}
		
		//Establece el anterior numero
		anterior = numero;
	}
	
	cout << "La longitud de la subfrecuencia es de " << orden << " digitos." << endl;
	cout << "El primer numero es el " << inicial << endl;
	cout << posicion_inicial << " es la posicion del primer numero.";
}
