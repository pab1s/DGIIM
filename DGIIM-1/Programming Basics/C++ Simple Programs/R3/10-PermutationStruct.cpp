
#include <iostream>
using namespace std;

struct Permutacion{
	int n;
	int elementos[1000];
};

int main (){
	Permutacion permutacion1, permutacion2, kesima, auxiliar;
	bool correcto, encontrado;
	int i, j, k, l, m, n, o, p, q, potencia, numero;

//A
	//Se introduce la permutacion 	
	cout << "Introduce una cantidad de elementos para el vector: ";
   cin >> permutacion1.n;
   cout << "\nIntroduce los elementos de la permutacion: "; 
   for(i=0; i<permutacion1.n; i++)
      cin >> permutacion1.elementos[i];
   
//B	
	correcto = true;
	encontrado = true;
	numero = 1;
	//Se mira que este cada numero y que no se repita
	while (numero <= permutacion1.n && encontrado && correcto){
		encontrado = false;
		for (i=0; i<permutacion1.n; i++){
			if (permutacion1.elementos[i] == numero)
				encontrado = true;
			if (encontrado)
				for (j=i+1; j<permutacion1.n; j++)
					if (permutacion1.elementos[j] == numero)
						correcto = false;
		}
		numero++;
	}
	if (correcto && encontrado)
		cout << "\nLa permutacion es correcta";
	else
		cout << "\La permutacion no es correcta";
		
//C1
	//Para cada lugar del elemento k, se copia en la nueva permutacion 
	permutacion2.n = permutacion1.n;
	for (k=0; k<permutacion1.n; k++){
		numero = permutacion1.elementos[k];
		permutacion2.elementos[k] = permutacion1.elementos[numero - 1];
	}	
	cout << "\n\nLa permutacion al cuadrado es: ";
	for (l=0; l<permutacion2.n; l++)
		cout << permutacion2.elementos[l] << "  "; 
		
//C2
	//Se copia la permutacion inicial y se introduce la k
	auxiliar.n = permutacion1.n;
	kesima.n = permutacion1.n;
	cout << "\n\nIntroduce el numero al que quiere hacer la potencia: ";
	cin >> potencia; 
	for (m=0; m< kesima.n; m++)
		kesima.elementos[m] = permutacion1.elementos[m];
	
	//Se hace el cambio 'k' veces
	for (n=1; n < potencia; n++){
		for (p=0; p<auxiliar.n; p++){
			auxiliar.elementos[p] = kesima.elementos[p];
		}
		for (o=0; o<kesima.n; o++){
			numero = auxiliar.elementos[o];
			kesima.elementos[o] = permutacion1.elementos[numero - 1];
		}
	}
	
	//Salida resultado
	cout << "\nLa permutacion k esima es: ";
	for (q= 0; q<kesima.n; q++)
		cout << kesima.elementos[q] << "  ";
	}
