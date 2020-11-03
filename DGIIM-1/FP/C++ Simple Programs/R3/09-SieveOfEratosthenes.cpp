
#include<iostream>

using namespace std;

int main(){
	
	int i, j, numero;
	const int LONGITUD = 1000;
	int vector[LONGITUD];	
	
	do{
		
		cout << "Introduzca el máximo número que quiera comprobar menor que 1000." << endl;
		cin >> numero;
		
	}while(numero < 2 || numero > 1000);
	
	j = 0;
	
	//Añade los numeros anteriores al introducido al vector
	for(i=2; i < (numero - 1); i++){
		
		vector[j] = i;
		j++;
	}
	
	//Comprueba si el numero es primo
	for(int k=2; k<numero; k++){
		
		for(j=0; j<numero; j++){
			
			if(vector[j]!=k){
				
				if((vector[j] % k) == 0)
					vector[j] = 0;
			}
		}
	}
	
	cout << "Los primos son:" << endl;
	
	//Imprime solo los numeros primos
	for(int j=0; j<numero; j++)
		if (vector[j] > 1)
		cout << vector[j] << endl;
		
}

