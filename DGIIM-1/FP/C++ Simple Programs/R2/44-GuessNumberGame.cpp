
#include <iostream>
#include <cstdlib>
using namespace std;

int main()	{
	
	int numero, prev_numero, comprobador, fin, aleatorio, limite_inferior, limite_superior;
	
	//Este bucle permite repetir el juego
	do {
			
		cout << "Primero debera introducir el intervalo en el que desea jugar." << endl;
		cout << "introduzca el limite inferior: ";
		cin >> limite_inferior;
		cout << "Introduzca ahora el limite superior: ";
		cin >> limite_superior;
		cout << "Cuando desee acabar la partida, solo escriba el anterior numero que haya introducido." << endl;
		
		aleatorio = limite_inferior + rand() % (limite_superior + 1 - limite_inferior);
		fin = 1;
			
			//Inicia el juego y lo sigue ejecutando mientras no se cambie el valor 'fin'
			do {
				
				cout << "Introduzca un numero: ";
				cin >> numero;
				
				//Finaliza el juego si introduces el anterior numero que has introducido
				if (prev_numero == numero)
					fin = 2;
				
				if (numero < aleatorio)
					cout << "El numero es mayor." << endl;
					
				if (numero > aleatorio)
					cout << "El numero es menor." << endl;
				
				//Tras finalizar, te permite salir o continuar jugando cambiando el valor de 'fin'	
				if (numero == aleatorio)	{
					cout << "Enhorabuena. Has acertado el numero. Si desea volver a jugar, pulse 0. Si desea acabar, pulse 1." << endl;
					cin >> comprobador;
		
						if (comprobador == 1)
							fin = 2;
					
						if (comprobador == 0)
							fin = 0;
				}
				
				prev_numero = numero;
				
			} while (fin == 1);
		
		
	} while (fin == 0);
	
}
