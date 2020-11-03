#include <iostream>
#include <vector>
using namespace std;

struct ParejaCaracterEntero{
	char caracter;
	int numero;
};

class VectorParejasCaracterEntero{
	private:		
		vector<ParejaCaracterEntero> elementos;
		
	public:
		
		
		//Constructores
		VectorParejasCaracterEntero(){}
		
		VectorParejasCaracterEntero(vector<ParejaCaracterEntero> parejas){
			elementos = parejas;
		}
		
		//Get
		int GetLength(){
			int longitud = elementos.size();		
			return longitud;
		}
		
		char GetCaracter(int posicion){
			char caracter = elementos[posicion].caracter;			
			return caracter;
		}
		
		int GetVeces(int posicion){
			int veces = elementos[posicion].numero;
			return veces;
		}
		
		//Introducir datos
		void IntroducirDatos(){
			char respuesta, continuar;
			int veces;
			ParejaCaracterEntero pareja;
			
			do{
				
				cout << "\n\nIntroduzca el caracter que desea eliminar: ";
				cin >> respuesta;
				cout << "Introduzca el numero de veces que desea eliminarlo: ";
				cin >> veces;
				
				pareja.caracter = respuesta;
				pareja.numero = veces;
				
				elementos.push_back(pareja);
				
				cout << "Desea introducir otra pareja (s:continuar / otro:no): ";
				cin >> continuar;			
			}while(continuar == 's');
		
		}
		
		//Mostrar
		void MostrarParejas(){
			cout << "[";
			cout << "(" << elementos[0].caracter << "," << elementos[0].numero << ")";
			
			for (int i=1; i<elementos.size()-1; i++){
				cout << ",(" << elementos[i].caracter << "," << elementos[i].numero << ")";
			}
			
			if(elementos.size() > 1){
				cout << ",(" << elementos[elementos.size()-1].caracter << "," << elementos[elementos.size()-1].numero << ")";
			}
			cout << "]";
		}
};

class Frase{
	private:
		vector<char> caracteres;
	
	public:

		//Constructores	
		Frase(){}
		
		Frase(vector<char> frase){
			caracteres = frase;
		}
		
		//Localiza las letras que se desean eliminar
		Borrar(VectorParejasCaracterEntero parejas){
			int contador = 0;
			
			for(int i=0; i<parejas.GetLength(); i++){
				for (int j=0; j<caracteres.size() && contador<parejas.GetVeces(i); j++){
					if(caracteres[j] == parejas.GetCaracter(i)){
						EliminarLetra(j);
						contador++;
					}
				}
				contador = 0;
			}
		}
		
		//Elimina una letra dada su posicion
		void EliminarLetra(int posicion){
			for (int i=posicion; i<caracteres.size(); i++){
				caracteres[i] = caracteres[i+1];				
			}
			caracteres.pop_back();
		}
		

		
		//Pedir frase
		void PedirFrase(){
			char respuesta;
			
			cout << "Introduce una frase acabando con #: ";
			cin.get(respuesta);
			
			while(respuesta != '#'){
				caracteres.push_back(respuesta);
				cin.get(respuesta);
			}
		}
		
		//MostrarFrase
		void Mostrar(){
			cout << "\nLa frase es: ";
			for (int i=0; i<caracteres.size(); i++){
				cout << caracteres[i];
			}
		}
};

int main(){
	vector<char> vector1 = {'H', 'o', 'l', 'a', ' ', 'm', 'u', 'n', 'd', 'o', ' ', 'c', 'r', 'u', 'e', 'l'};
	Frase frase1(vector1);
	VectorParejasCaracterEntero parejas;
	
	//DATOS
	frase1.Mostrar();
	//Se puede definir al declarar variable
	parejas.IntroducirDatos();
	parejas.MostrarParejas();
	
	//CALCULO
	frase1.Borrar(parejas);
	
	//SALIDA
	frase1.Mostrar();
}

