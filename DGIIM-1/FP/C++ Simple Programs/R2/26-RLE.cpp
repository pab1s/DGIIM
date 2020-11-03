/* ES MUY IMPORTANTE QUE A LA HORA DE COMPILAR EL PROGRAMA SE AÑADA
   -std=c++0x A LAS OPCIONES DEL COMPILADOR PARA QUE ACEPTE EL to_string()*/

#include <iostream>	
#include <string>

using namespace std;

int main(){
	
	string codigo, espacio = " ";
	int contador = 1, numero = 1, numero_anterior = 1;
	
	//Pide que se introduzca el primer numero de la sucesion
	cout << "Introduzca su sucesion (ponga -1 para finalizarla): ";
	cin >> numero;
	
	//Establece un numero anterior para comparar
	numero_anterior = numero;
	
	while(numero > 0)	{
		
		//Sigue pidiendo numeros de la sucesion hasta introducir un negativo
		cin >> numero;
		
		//Aumenta el contador de numeros iguales si es igual al anterior
		if(numero == numero_anterior)	{
			contador++;
		}
		
		//Si es diferente añade el resultado del contador y el numero
		else	{		
			codigo += to_string(contador) + espacio + to_string(numero_anterior) + espacio;
			numero_anterior = numero;	
			contador = 1;
		}
	}
	
	//Muestra el resultado
	cout << "\nNumero descodificado: " << codigo;
}
