
#include<iostream>

using namespace std;

int main(){
	
	int contador, minimo, j, i, primero;
	const int LONGITUD = 500;
	int vector[LONGITUD], vector2[LONGITUD];
	bool noterminador = true, noterminador2 = true;	
	
	cout << "Introduzca las componentes del vector con un máximo de 500 y termine con -1." << endl;
	
	for(i=0; i < (LONGITUD -1) && noterminador; i++){
		cin >> vector[i];
		noterminador = vector[i] != -1;
	}
	
	if(i==500)
		i++;
		
	cout << "Introduzca las componentes del vector 2 con un máximo de 500 y termine con -1." << endl;
	
	for(j=0; j < (LONGITUD -1) && noterminador2; j++){
		cin >> vector2[j];
		noterminador2 = vector2[j] != -1;
	}
	
	if(j==500)
		j++;
		
	primero = contador = minimo = 0;
	
	for(int k=0; k<(j-1); k++){
		
		for(int t=0; t<(i-1); t++){
			
			if(vector2[k] == vector[t]){
				
				contador++;
				
				if(primero == 0)
					primero = t + 1;
					
				if(t < primero)
					primero = t + 1;
			}
		}
		
		if(k==0)
			minimo = contador;
		
		if(contador < minimo)
			minimo = contador;
			
		contador = 0;
	}
	
	if(primero == 0 || minimo == 0)
		cout << "No se repite el vector" << endl;
		
	else{
		cout << "El vector 2 se repite " << minimo << " veces en el 1." << endl;
		cout << "Las coincidencias aparecen en el primer vector a partir de la posición " << primero << endl;
	}
}

