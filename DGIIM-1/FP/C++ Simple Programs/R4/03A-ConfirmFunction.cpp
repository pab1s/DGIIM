#include <iostream>
using namespace std;

int Confirmar(char entrada){

	bool confirmacion;
	
	if (entrada == 's' || entrada == 'S')
		confirmacion = true;
		
	if (entrada == 'n' || entrada == 'N')
		confirmacion = false;
		
	return confirmacion;
}

int main () {
	
	char entrada;
	bool valido = false;
	
	do{
	cout << "¿Confirmar S/N?";
	cin >> entrada;
	if (entrada == 's' || entrada == 'S' || entrada == 'n' || entrada == 'N')
		valido = true;
	}while (valido == false);
	
	cout << Confirmar(entrada);
}
