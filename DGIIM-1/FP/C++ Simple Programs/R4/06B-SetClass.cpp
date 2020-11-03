#include <iostream>
#include <vector>

using namespace std;

int BuscarPosicion(vector<int> elementos, int n){
	int posicion = -1;
    int extremo_inf = 0;
    int extremo_sup = elementos.size() - 1;
    int i = extremo_inf + (extremo_sup - extremo_inf)/2;
    
    while (extremo_sup >= extremo_inf && posicion == -1){
        if (elementos[i] > n){
            extremo_sup = i - 1;
        } else if (elementos[i] < n){
            extremo_inf = i + 1;
        } else {
            posicion = i;
        }
        i = extremo_inf + (extremo_sup - extremo_inf)/2;
    }
    return posicion;
}

class Conjunto{
    private:
        vector<int> elementos;
  
    public:
    	//Constructores
        Conjunto(){}
        Conjunto(vector<int> v){
        	elementos = v;
		    EliminarRepetidos();
		    Ordenar();
		}
		
		//Pedir
		void Pedir(){
			int n;

		    cout << "\nIntrdouzca el numero de elementos para el conjunto: ";
		    cin >> n;
		    
		    vector<int> v(n);
		    
		    cout << "\nIntroduzca los elementos del conjunto: ";
		    for (int i = 0; i < n; i++){
		        cin >> v[i];
		    }
		    
		    elementos = v;	    
		}
		
		//Obtener
        vector<int> ObtenerVector(){
        	return elementos;
		}
		     
        //Organizacion
        bool Existe(int n){
        	int posicion = BuscarPosicion(elementos, n);
   			return (posicion != -1);
		}
        void EliminarRepetidos(){
        	vector<int> elementos_unicos;
		    bool encontrado_anteriormente = false;
		    
		    int i = 0;
		    while (i < elementos.size()){
		        encontrado_anteriormente = false;
		        for (int j = 0; j < elementos_unicos.size() && !encontrado_anteriormente; j++){
		            if (elementos[i] == elementos_unicos[j]){
		                encontrado_anteriormente = true;
		            }
		        }
		        
		        if (encontrado_anteriormente){
		            elementos.erase(elementos.begin() + i);
		        } else {
		            elementos_unicos.push_back(elementos[i]);
		            i++;
		        }
		    }
		}
        void Anadir(int n){
        	bool introducido = false, elemento_repetido = false;
		    
		    elemento_repetido = (BuscarPosicion(elementos, n) != -1);
		    
		    for (int i = 0; i < elementos.size() && !introducido && !elemento_repetido; i++){
		        if (elementos[i] > n){
		            elementos.insert(elementos.begin() + i, n);
		            introducido = true;
		        }
		    }
		    
		    if (!introducido && !elemento_repetido){
		        elementos.push_back(n);
		    }
		}
        void Remove(int n){
        	int pos = BuscarPosicion(elementos, n);
		    
		    if (pos != -1){
		        elementos.erase(elementos.begin() + pos);
		    }
		    else{
		    	cout << "\nEl elemento no existe.";
			}
		}
        void Ordenar(){
        	int elemento;
		    bool ordenado = false;
		    
		    for (int i = 1; i < elementos.size(); i++){
		        ordenado = false;
		        elemento = elementos[i];
		        elementos.erase(elementos.begin() + i);
		        
		        for (int j = i - 1; j >= 0 && !ordenado; j--){
		            if (elemento > elementos[j]){
		                elementos.insert(elementos.begin() + j + 1, elemento);
		                ordenado = true;
		            }
		        }	        
		        if (!ordenado){
		            elementos.insert(elementos.begin(), elemento);
		        }
		    }
		};
		
		//Union e Interseccion
        Conjunto Union(Conjunto c){
        	vector<int> v_result;
		    int i = 0, j = 0;
		    vector<int> elementos2 = c.ObtenerVector();
		    
		    while (i < elementos.size() && j < elementos2.size()){
		        if (elementos[i] < elementos2[j]){
		            v_result.push_back(elementos[i]);
		            i++;
		        } else {
		            v_result.push_back(elementos2[j]);
		            j++;
		        }
		    }		    
		    while (i < elementos.size()){
		        v_result.push_back(elementos[i]);
		        i++;
		    }	    
		    while (j < elementos2.size()){
		        v_result.push_back(elementos2[j]);
		        j++;
		    }
		    
		    Conjunto result(v_result);
		    return result;
		}		
        Conjunto Interseccion(Conjunto c){
        	vector<int> v_result;
		    vector<int> elementos2 = c.ObtenerVector();
		    vector<int> elementos2_copy(elementos2);
		    
		    int pos;
		    for (int i = 0; i < elementos.size(); i++){
		        pos = BuscarPosicion(elementos2_copy, elementos[i]);
		        if (pos != -1){
		            v_result.push_back(elementos[i]);
		            elementos2_copy.erase(elementos2_copy.begin() + pos);
		        }
		    }
		    
		    Conjunto resultado(v_result);
		    return resultado;
		}
		
		//Mostrar
        void Imprimir(const char nombre[]){
        	cout << "\nLos elementos del conjunto " << nombre << " son: ";
		    for (int i = 0; i < elementos.size(); i++){
		        cout << elementos[i] << " ";
		    }
		}
};

Conjunto PedirConjunto(){
	
}

int main(){
    int n;
    bool existe;
    Conjunto conjunto;
    
    conjunto.Pedir();
    conjunto.Imprimir("introducido");

	// Datos
    cout << "\nIntroduzca un numero para aniadirlo al conjunto: ";
    cin >> n;
    conjunto.Anadir(n);
    
    // Calculos-Salida
    cout << "\nIntroduzca un numero para eliminarlo del conjunto: ";
    cin >> n;
    conjunto.Remove(n);

    conjunto.Imprimir("resultante");

    cout << "\nIntroduce un numero para saber si esta en el conjunto: ";
    cin >> n;
    existe = conjunto.Existe(n);
    cout << "El numero " << n << (existe ? " si" : " no") << " se encuentra en el conjunto." << endl;

    Conjunto conjunto2;
    conjunto2.Pedir();
    
    Conjunto union_ = conjunto.Union(conjunto2);
    Conjunto interseccion = conjunto.Interseccion(conjunto2);
    
    union_.Imprimir("union");
    interseccion.Imprimir("interseccion");
}
