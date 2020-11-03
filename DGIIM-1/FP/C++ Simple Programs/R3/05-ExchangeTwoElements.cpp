
#include<iostream>

using namespace std;

int main(){
	
	int intercambio, intercambio2, guardar, i;
	const int LONGITUD = 500;
	int vector[LONGITUD];
	bool noterminador = true;	
	
	cout << "Escriba las componentes del vector con un máximo de 500 y termine con -1." << endl;
	
	//Introduce los componentes del vector
	for(i=0; i < (LONGITUD -1) && noterminador; i++){
		cin >> vector[i];
		noterminador = vector[i] != -1;
	}
	
	if(i==500)
		i++;
	
	//Pide dos posiciones correctas para intercambiar	
	do{
		cout << "Escriba la primera componente que desea intercambiar." << endl;
		cin >> intercambio;
	}while(intercambio < 1 || intercambio > (i - 1));
	
	do{
		cout << "Escriba la segunda componente que desea intercambiar." << endl;
		cin >> intercambio2;
	}while(intercambio2 < 1 || intercambio2 > (i - 1));
	
	//Realiza el intercambio
	intercambio--;
	intercambio2--;
	
	guardar = vector[intercambio];
	vector[intercambio] = vector[intercambio2];
	vector[intercambio2] = guardar;
	
	cout << "El vector que ha escrito es:" << endl;
	
	for(int j=0; j<(i-1); j++)
		cout << vector[j] << endl;
}

