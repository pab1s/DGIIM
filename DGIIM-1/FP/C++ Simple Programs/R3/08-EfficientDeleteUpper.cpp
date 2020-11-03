#include<iostream>

using namespace std;

int main(){
	
    const int LONGITUD_MAXIMA = 10;
    char vector[LONGITUD_MAXIMA];
    
    int componentes_utiles;
    
    cout << "Introducir numero de componentes del vector: ";
    cin >> componentes_utiles;
    
    cout << "Introducir vector: ";
    for (int i = 0 ; i < componentes_utiles ; i++)
        cin >> vector[i];
	
    int posicion_escritura = 0;
    
    //Comprueba si el componente es una mayuscula y la convierte a minuscula, cogiendo solo los componentes validos
    for (int posicion_lectura = 0; posicion_lectura < componentes_utiles; posicion_lectura++)	{
        if ( vector[posicion_lectura] < 'A' || vector[posicion_lectura] > 'Z'){
        	
            vector[posicion_escritura] = vector[posicion_lectura];
            posicion_escritura++;
            
        }
	}
	
    componentes_utiles = posicion_escritura;
    
    cout << "\nEl vector queda: ";
    
    //Muestra el resultado
    for (int i = 0; i < componentes_utiles; i++)
        cout << vector[i] << " ";
        
    cout << "\n";
}
