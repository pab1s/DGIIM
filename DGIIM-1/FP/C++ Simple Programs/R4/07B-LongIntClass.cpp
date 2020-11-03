#include <iostream>
#include <cmath>
using namespace std;


int NumCifras(int num){
	int contador = 1;
	bool negativo;
	
	negativo = (num<0);
	if (negativo){
		num *= -1;
	}
	
	while(num/10>0)
    {
        num=num/10;
        contador++;
    }
    
    return contador;
}

class EnteroLargo{
	private:	
		static const int MAXELEM = 100;
		int num_elem;
		int elementos[MAXELEM];	
		bool positivo;
		
	public:

		//Constructor
		EnteroLargo(){
			num_elem = 0;
		}
		
		EnteroLargo(int array[MAXELEM], int longitud){
			num_elem = longitud;
			
			positivo = array[0];
			
			for (int i=1; i<num_elem; i++){
				elementos[i] = array[i];
			}
		}
	
		//Mostrar vector
		void MostrarVector(string nombre){	
		
			positivo ? cout << "\nEl vector " << nombre << " es: (" : cout << "\nEl vector " << nombre << " es: -(";	
			
			cout << elementos[1];
			for (int i=2; i<num_elem-1; i++){
				cout << ", " << elementos[i];
			}
			if(num_elem>1){
				cout << ", " << elementos[num_elem-1];	
			}
			cout << ")";		
		}
		
		void MostrarNumero(string nombre){

			cout << "\nEl numero " << nombre << " es: ";
			
			if(!positivo){
				cout << "-";
			}

			for (int i=1; i<num_elem; i++){
				cout << elementos[i];
			}
		}

		bool operator < (EnteroLargo n2){
			bool resultado;
			bool iguales = Iguales(n2);
			bool lonIguales = (num_elem == n2.num_elem);
			bool acabar = false;
			int contador = 1;
			
			if(iguales){
				resultado = false;
			}
			
			else if (positivo && n2.positivo){
				if(lonIguales){
					while(!acabar && contador < num_elem){
						if(elementos[contador] < n2.elementos[contador]){
							resultado = true;
							acabar = true;
						}
						else if(elementos[contador] == n2.elementos[contador]){
							contador++;
						}
						else{
							resultado = false;
							acabar = true;
						}
					}
				}
				else if(num_elem < n2.num_elem){
					resultado = true;
				}
				else{
					resultado = false;
				}
			}
			else if(!positivo && n2.positivo){
				resultado = true;
			}
			else if(!positivo && !n2.positivo){
				if(lonIguales){
					while(!acabar && contador < num_elem){
						if(elementos[contador] > n2.elementos[contador]){
							resultado = true;
							acabar = true;
						}
						else if(elementos[contador] == n2.elementos[contador]){
							contador++;
						}
						else{
							resultado = false;
							acabar = true;
						}
					}
				}
				else if(num_elem > n2.num_elem){
					resultado = true;
				}
				else{
					resultado = false;
				}
			}
			else{//positivo y n2!positivo
				resultado = false;
			}
			
			return resultado;
		}
		
		bool operator > (EnteroLargo n2){
			bool resultado;
			bool iguales = Iguales(n2);
			bool lonIguales = (num_elem == n2.num_elem);
			bool acabar = false;
			int contador = 1;
			
			if (iguales){
				resultado = false;
			}
			
			else if (positivo && n2.positivo){
				if(lonIguales){
					while(!acabar && contador < num_elem){
						if(elementos[contador] > n2.elementos[contador]){
							resultado = true;
							acabar = true;
						}
						else if(elementos[contador] == n2.elementos[contador]){
							contador++;
						}
						else{
							resultado = false;
							acabar = true;
						}
					}
				}
				else if(num_elem > n2.num_elem){
					resultado = true;
				}
				else{
					resultado = false;
				}
			}
			else if(!positivo && n2.positivo){
				resultado = false;
			}
			else if(!positivo && !n2.positivo){
				if(lonIguales){
					while(!acabar && contador < num_elem){
						if(elementos[contador] < n2.elementos[contador]){
							resultado = true;
							acabar = true;
						}
						else if(elementos[contador] == n2.elementos[contador]){
							contador++;
						}
						else{
							resultado = false;
							acabar = true;
						}
					}
				}
				else if(num_elem < n2.num_elem){
					resultado = true;
				}
				else{
					resultado = false;
				}
			}
			else{//positivo y n2!positivo
				resultado = true;
			}
			
			return resultado;
		}
		
		
		bool Iguales(EnteroLargo n2){
			bool lonIguales = (num_elem == n2.num_elem);
			bool resultado = true;
			
			if(lonIguales){
				for (int i=0; i<num_elem && resultado == true; i++){
					if(elementos[i] != n2.elementos[i]){
						resultado = false;
					}
				}
			}
			else{
				resultado = false;
			}		
			return resultado;
		}
		
		EnteroLargo operator + (EnteroLargo n2){
			EnteroLargo resultado;
			int contador = 1;
			bool acabar = false;
			
			if(num_elem == n2.num_elem){
				resultado.num_elem = num_elem;
				
				if(positivo && n2.positivo){
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(elementos[i] + n2.elementos[i]);
					}
					resultado.elementos[0] = 1;
					resultado.positivo = true;
				}
				else if(!positivo && n2.positivo){
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(-elementos[i] + n2.elementos[i]);
					}
					
					if(Iguales(n2)){
						resultado.elementos[0] = 1;
						resultado.positivo = true;
					}
					else{
						while(!acabar && contador<num_elem){
							if (elementos[contador] > n2.elementos[contador]){
								resultado.elementos[0] = 0;
								resultado.positivo = false;
								acabar = true;
							}
							else if(elementos[contador] < n2.elementos[contador]){
								resultado.elementos[0] = 1;
								resultado.positivo = true;
								acabar = true;
							}
							else{
								contador++;
							}
						}				
					}

				}
				else if(positivo && !n2.positivo){
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(elementos[i] - n2.elementos[i]);
					}
					
					if(Iguales(n2)){
						resultado.elementos[0] = 1;
						resultado.positivo = true;
					}
					
					else{
						while(!acabar && contador<num_elem){
							if (elementos[contador] > n2.elementos[contador]){
								resultado.elementos[0] = 1;
								resultado.positivo = true;
								acabar = true;
							}
							else if(elementos[contador] < n2.elementos[contador]){
								resultado.elementos[0] = 0;
								resultado.positivo = false;
								acabar = true;
							}
							else{
								contador++;
							}
						}				
					}
				}
				else{//ambos negativos
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(-elementos[i] - n2.elementos[i]);
					}
					resultado.elementos[0] = 0;
					resultado.positivo = false;
				}		
			}
		return resultado;				
		}
		
		bool operator == (EnteroLargo n2){
			bool resultado = Iguales(n2);
			return resultado;
		}
				
		EnteroLargo operator - (EnteroLargo n2){
			EnteroLargo resultado;
			int contador = 1;
			bool acabar = false;
			
			if(num_elem == n2.num_elem){
				resultado.num_elem = num_elem;
				
				if(positivo && n2.positivo){
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(elementos[i] - n2.elementos[i]);
					}
					
					if(Iguales(n2)){
						resultado.elementos[0] = 1;
						resultado.positivo = true;
					}
					
					else{
						while(!acabar && contador<num_elem){
							if (elementos[contador] > n2.elementos[contador]){
								resultado.elementos[0] = 1;
								resultado.positivo = true;
								acabar = true;
							}
							else if(elementos[contador] < n2.elementos[contador]){
								resultado.elementos[0] = 0;
								resultado.positivo = false;
								acabar = true;
							}
							else{
								contador++;
							}
						}				
					}
				}
				else if(!positivo && n2.positivo){
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(-elementos[i] - n2.elementos[i]);
					}
					resultado.elementos[0] = 0;
					resultado.positivo = false;			
				}
				else if(positivo && !n2.positivo){
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(elementos[i] - n2.elementos[i]);
					}
						resultado.elementos[0] = 1;
						resultado.positivo = true;			
				}
				else{//ambos negativos
					for (int i=0; i<resultado.num_elem; i++){
						resultado.elementos[i] = abs(-elementos[i] - n2.elementos[i]);
					}
					
					if(Iguales(n2)){
						resultado.elementos[0] = 1;
						resultado.positivo = true;
					}
					
					else{
						while(!acabar && contador<num_elem){
							if (elementos[contador] < n2.elementos[contador]){
								resultado.elementos[0] = 1;
								resultado.positivo = true;
								acabar = true;
							}
							else if(elementos[contador] > n2.elementos[contador]){
								resultado.elementos[0] = 0;
								resultado.positivo = false;
								acabar = true;
							}
							else{
								contador++;
							}
						}				
					}
					
				}		
			}
		return resultado;				
		}
};

int main(){
	//Primer valor del vector --> 0:negativo, 1:positivo
	int array1[100]={1,5,3,5};
	int array2[100]={1,2,2,4};
	bool menor, mayor, igual;
	
	EnteroLargo num1{array1, 4};
	EnteroLargo num2{array2, 4};
	EnteroLargo suma;
	EnteroLargo resta;
	
	// Datos
	num1.MostrarVector("1");
	num2.MostrarVector("2");
	num1.MostrarNumero("1");
	num2.MostrarNumero("2");
	
	// Cálculo
	menor = (num1<num2);
	mayor = (num1>num2);
	igual = (num1==num2);
	suma = (num1+num2);
	resta = (num1-num2);
	
	//Salida
	menor ? cout << "\n\nEl primer numero es menor al segundo" : cout << "\n\nEl primer numero no es menor al segundo";
	mayor ? cout << "\nEl primer numero es mayor al segundo" : cout << "\nEl primer numero no es mayor al segundo";
	igual ? cout << "\nEl primer numero es igual al segundo\n" : cout << "\nEl primer numero no es igual al segundo\n";

	suma.MostrarVector("suma");
	suma.MostrarNumero("suma");
	resta.MostrarVector("resta");
	resta.MostrarNumero("resta");
}

