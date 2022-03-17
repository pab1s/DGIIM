
#include<iostream>

using namespace std;

int main(){
	
	int mayus, iteraciones, i,j;
	const int LONGITUD = 100;
	char vector[LONGITUD];
	bool noterminador = true;	
	
	cout << "Introduzca las componentes del vector con un maximo de 100 y termine con #." << endl;
	
	//Introduce los componentes del vector
	for(i=0; i < (LONGITUD -1) && noterminador; i++){
		
		cin >> vector[i];
		noterminador = vector[i] != '#';
	}
	
	if(i==500)
		i++;
		
	iteraciones = j = 0;
	
	//Comprueba si el vector es una letra mayuscula, y de ser asi la cambia
	while(j < (i-1)){
		
		mayus = vector[j];
		
		if(mayus < 91 && mayus > 64){
			
			for(int k=j; k<((i-1) - iteraciones); k++)
				vector[k] = vector[k+1];
				
			iteraciones++;
			j--;
		}
		
		j++;
	}
	
	cout << "El vector sin mayúsculas es:" << endl;
	
	//Imprime el nuevo vector
	for(int k=0; k<((i-1) - iteraciones); k++)
		cout << vector[k] << endl;
		
}

