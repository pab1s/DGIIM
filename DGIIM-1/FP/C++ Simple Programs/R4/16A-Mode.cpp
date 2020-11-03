#include <iostream>
#include <cstring>
using namespace std;


struct FrecuenciaCaracter{
    char caracter;
    int frecuencia;
};

//Calcula las repeticiones de cada caracter
int AumentarContador(char caracter, int contadores[][2], int tamano, FrecuenciaCaracter& moda){
	
    int tamano_final = tamano;
    bool anadido = false;
      
	//Si el caracter ya está añadido, aumenta el contador  
    for (int i = 0; i < tamano && !anadido; i++){
        if (contadores[i][0] == caracter){
            contadores[i][1]++;
            if (moda.frecuencia < contadores[i][1]){
                moda.caracter = contadores[i][0];
                moda.frecuencia = contadores[i][1];
            }
            
            anadido = true;
        }
    }
    
    //En caso de no estar, lo añade al contador
    if (!anadido){
        contadores[tamano][0] = caracter;
        contadores[tamano][1] = 1;
        tamano_final++;
    }
    
    return tamano_final;
}

//Calcula la moda y devuelve el struct correspondiente
FrecuenciaCaracter Moda(char cadena[]){
    FrecuenciaCaracter moda = {cadena[0], 1};

    int tamano_cadena = strlen(cadena);
    int contadores[1000][2] = {{cadena[0], 1}};
    int tamano_contadores = 1;
    
    for (int i = 1; i < tamano_cadena; i++){
        tamano_contadores = AumentarContador(cadena[i], contadores, tamano_contadores, moda);
    }
    
    return moda;
}

int main(){
    char cadena[1000];
    FrecuenciaCaracter resultado;
    
    cout << "Introduce una cadena de caracteres: ";
    cin.getline(cadena, 1000);
    
    resultado = Moda(cadena);
    
    cout << "El caracter que mas se repite es '" << resultado.caracter << "', y se repite " << resultado.frecuencia << " veces.";
    
}

