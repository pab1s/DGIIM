#include<iostream>

using namespace std;

int main(){
	
	const int LONGITUD = 1000;
	int vector[LONGITUD], i, secuencia;
	bool noterminador = true;
	
	cout << "Escriba el vector con un máximo de 1000 y si quiere terminar escriba -1" << endl;
	
	//Pide la entrada del vector
	for(i=0; i<LONGITUD && noterminador; i++){
		cin >> vector[i];
		noterminador = vector[i] != -1;
	}
	
	secuencia = 0;
	
	//Comprueba su ascendencia y aumenta la secuencia si en algun momento deja de crecer
	for(int j=1; j<i; j++){
		if(vector[j-1] > vector[j])
			secuencia++;
	}
	
	cout << "Se han encontrado " << secuencia << " secuencias ascendentes." << endl;
}
