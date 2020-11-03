#include <iostream>

using namespace std;

int main () {
	
	int numero = 1, primo = 0;
	
	//Realiza el producto hasta que llegamos al uno
	while (primo != 1){
		cin >> primo;
		numero = numero * primo;
	}

	cout << "El numero alienigena es: " << numero;
}  
