#include <iostream>
#include <string>
using namespace std;

struct Especie{
	string nombre;
	string ADN;
};

//Permite añadir nuevas especies a la base de datos
void AniadirDatos(Especie baseDatos[1000], int& longitud){
	
	char respuesta;
	
	cout << "Actualmente hay " << longitud << " entradas en la base de datos:\n";
	for (int i=0; i<longitud; i++){
		cout << i+1 << "- " << baseDatos[i].nombre << "\n" ;
	}
	
	cout << "\nDeseas aniadir alguna entrada? (s:aceptar / otra tecla:cancelar): ";
	cin >> respuesta;
		
	while(respuesta == 's'){
		longitud++;
		cout << "Introduce el nombre de la especie: ";
		cin.ignore();
		getline(cin, baseDatos[longitud-1].nombre);
		cout << "Introduce su secuencia de ADN: ";
		cin >> baseDatos[longitud-1].ADN;
		cout << "Deseas aniadir alguna entrada? (s:aceptar / otra tecla:cancelar): ";
		cin >> respuesta;
	}
	
	cout << "\nAhora hay " << longitud << " entradas en la base de datos:\n";
	for (int i=0; i<longitud; i++){
		cout << i+1 << "- " << baseDatos[i].nombre << "\n" ;
	}	
}

// Comprueba si una cadena esta contenida en otra
bool CompararSecuencia(string adn, string secuencia){
	
	bool encontrada = false;
	int longitudADN, longitudSecuencia;
	int contadorIzquierda, contadorDerecha;
	string nuevaSecuencia;
	
	longitudADN = adn.length();
	longitudSecuencia = secuencia.length();
	
	if(longitudADN == longitudSecuencia){
		
		for(int i=0; i<longitudADN && encontrada == false; i++){
			contadorIzquierda = i;
			contadorDerecha = longitudADN - contadorIzquierda;
			nuevaSecuencia = "";
			
			for (int k=contadorIzquierda; k<longitudADN; k++){
				nuevaSecuencia += secuencia[k];
			}
			
			for(int j=0; j<contadorIzquierda; j++){
				nuevaSecuencia += secuencia[j];
			}
			
			if(nuevaSecuencia == adn){
				encontrada = true;
			}
		}
	}
	
	return encontrada;	
}


int main(){
	Especie mosca = {"Mosca del vinagre", "ATAATGGACAAT"};
	Especie lombriz = {"Lombriz de tierra", "GGATACT"};
	Especie ameba = {"Ameba verde", "AGAGAT"};
	
	Especie baseDatos[1000] = {mosca, lombriz, ameba};	
	int longitud = 3;	
	
	string secuencia;
	string especieEncontrada;
	
	bool encontrado = false;
	
	//Entrada datos
	AniadirDatos(baseDatos, longitud);
	
	cout << "\nIntroduce la secuencia a buscar: ";
	cin >> secuencia;
	
	//Calculo
	
	//Compara todas las especies con la secuencia de ADN introducida
	for(int i=0; i<longitud && encontrado == false; i++){
		encontrado = CompararSecuencia(baseDatos[i].ADN, secuencia);
		if (encontrado){
			especieEncontrada = baseDatos[i].nombre;
		} 
	}
	
	//Salida
	encontrado ? cout << "\nSE HA ENCONTRADO COINCIDENCIA: " << especieEncontrada : cout << "\nNO SE HA ENCONTRADO NINGUNA COINCIDENCIA";
}

