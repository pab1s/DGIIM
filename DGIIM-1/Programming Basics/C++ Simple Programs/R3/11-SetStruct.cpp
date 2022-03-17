#include <iostream>

using namespace std;

struct TipoConjunto	{
	
	int num_elem;
	int elementos[1000];
};

int main()	{
	
	TipoConjunto conjunto1, conjunto2, conjuntoUnion, conjunto_interseccion;
	int option = 0, elemento = 0;
	int i = 0, j = 0, contador1 = 0, contador2 = 0;
	bool elemento_conjunto = false,
		 elemento_menor_todos = false,
		 elemento_entre_componentes = false,
		 encontrado = false;
	int posicion_new_elemento = 0;
	
	cout << "Inserte cardinal del conjunto: ";
	cin >> conjunto1.num_elem;
	
	cout << "\nInserta elementos del conjunto: \n";
	for(int i=0; i < conjunto1.num_elem; i++)	{
		
		cout << ">>> ";
		cin >> conjunto1.elementos[i];
	}
	
	cout << "Introduzca la opcion que desea realizar(1, 2, 3 o 4): ";
	cin >> option;
	
	//OPCION 1: BUSQUEDA DE ELEMENTO
	if(option == 1)	{
		
		cout << "\n\nInserte elemento a buscar: ";
		cin >> elemento;
		
		//MIENTRAS NO SE ENCUENTRE EL ELEMENTO PEDIDO, RECORRE EL VECTOR
		while(!elemento_conjunto && i < conjunto1.num_elem)	{
			
			elemento_conjunto = elemento == conjunto1.elementos[i];	
			i++;
		}
		
		//SI ENCUENTRA ELEMENTO PEDIDO: MUESTRA SI
		if(elemento_conjunto)	{
			
			cout << "El elemento " << elemento << " esta en el conjunto";
			return 0;
		}
		
		//SI NO ENCUENTRA ELEMENTO PEDIDO: MUESTRA NO
		else
			cout << "El elemento " << elemento << " NO esta en el conjunto";
	}
	
	//OPCION2: AÑADIR UN NUEVO ELEMENTO Y ORDENAR EL VECTOR
	if(option == 2)	{
		
		cout << "\nInserte elemento a aniadir: ";
		cin >> elemento;
		
		//CASO EN QUE ELEMENTO NUEVO ESTÉ ENTRE OTRAS COMPONENTES DEL VECTOR DADO Ó ES MAYOR QUE TODOS
		while(i < conjunto1.num_elem)	{
			
			elemento_entre_componentes = elemento > conjunto1.elementos[i] && elemento < conjunto1.elementos[i+1];
			
			if(elemento_entre_componentes)	{
				
				posicion_new_elemento = i;
				i = conjunto1.num_elem;
			}

			i++;
		}
		
		//SI SE CUMPLE LAS CONDICIONES DEL WHILE
		if(elemento_entre_componentes)	{
			
			for(int c=0; c < conjunto1.num_elem; c++)	{
				cout << conjunto1.elementos[c];
				
				if(c == posicion_new_elemento)
					cout << elemento;
			}
			
			return 0;
		}
		
		//COMPRUEBA SI ELEMENTO DADO ES MENOR QUE TODOS LOS DEL CONJUNTO
		for(int a = 0; a < conjunto1.num_elem; a++)	{
			
			if(elemento < conjunto1.elementos[a])
				elemento_menor_todos = true;
		}
		
		//SI SE CUMPLE FOR ANTERIOR: MUESTRA
		if(elemento_menor_todos) {
			
			cout << elemento;
			for(int b=0; b < conjunto1.num_elem; b++)
				cout << conjunto1.elementos[b];

			return 0;
		}
		else{
			
			for(int b=0; b < conjunto1.num_elem; b++)
				cout << conjunto1.elementos[b];
				
			cout << elemento;
		}
	}
	
	//OPCION3: UNION DE CONJUNTOS
	if(option == 3)	{
		
		//INTRODUCCION DE DATOS DEL SEGUNDO CONJUNTO
		cout << "Inserte cardinal del conjunto 2: ";
		cin >> conjunto2.num_elem;
		cout << "\nInserta elementos del conjunto 2: \n";
		
		for(int i=0; i < conjunto2.num_elem; i++)	{
			
			cout << ">>> ";
			cin >> conjunto2.elementos[i];
		}
		
		contador1 = 0;
		encontrado = false;
		conjuntoUnion.num_elem = 0;
   
		while(contador1 < conjunto1.num_elem || contador2 < conjunto2.num_elem)	{
			
	        if((contador1 < conjunto1.num_elem) && conjunto1.elementos[contador1] < conjunto2.elementos[contador2])  {
	            conjuntoUnion.elementos[contador1+contador2] = conjunto1.elementos[contador1];
	            conjuntoUnion.num_elem++;
	            contador1++;
	        }
	        
	        else if(contador2 < conjunto2.num_elem)  {
	            conjuntoUnion.elementos[contador1+contador2] = conjunto2.elementos[contador2];
	            conjuntoUnion.num_elem++;
	            contador2++;
			}
		}
   
    	cout << "\nEl conjunto union tiene " << conjuntoUnion.num_elem << " elementos: ";
    	
    	for(int i=0; i<conjuntoUnion.num_elem; i++)
      		cout << conjuntoUnion.elementos[i] << " ";
	}
	
	if(option == 4)	{
		
		//INTRODUCCION DE DATOS DEL SEGUNDO CONJUNTO
		cout << "Inserte cardinal del conjunto 2: ";
		cin >> conjunto2.num_elem;	
		cout << "\nInserta elementos del conjunto 2: \n";
		
		for(int i=0; i < conjunto2.num_elem; i++)	{
			
			cout << ">>> ";
			cin >> conjunto2.elementos[i];
		}
		
		cout << "\nINTERSECCION DE CONJUNTOS: ";
		
		for(int a=0; a<conjunto1.num_elem;a++)
			for(int b=0; b<conjunto2.num_elem;b++)
				if(conjunto1.elementos[a] == conjunto2.elementos[b])
					cout << conjunto1.elementos[a];
	}
}
