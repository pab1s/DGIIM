#include <iostream>
using namespace std;

void Menu(void)	{
	
	cout << "\nAhora elija la operacion que desea realizar:\n\n";
	cout << "---> " << "Minimo comun multiplo (m).\n";
	cout << "---> " << "Maximo comun divisor (d).\n";
	cout << "---> " << "Suma (+).\n";
	cout << "---> " << "Resta (-).\n";
	cout << "---> " << "Multiplicacion (*).\n";
	cout << "---> " << "Division (/).\n\n";
}

int MCD(int primero, int segundo){

	bool mcd_encontrado = false;
	
	int divisor, mcd;
	
	if (primero == 0 || segundo == 0)
		mcd = 0;
		
	else{
		if (primero > segundo)
			divisor = segundo;
			
		else
			divisor = primero;
			
		mcd_encontrado = false;
		
		while (!mcd_encontrado){
			
			if (primero % divisor == 0 && segundo % divisor == 0)
				mcd_encontrado = true;
				
			else
				divisor--;
			
		}
		
		mcd = divisor;
	}
	
	return mcd;
}

int MCM(int num1, int num2) {
	
    int mcm = 0;
    int a = max(num1, num2);
    int b = min(num1, num2);
    mcm = (a/MCD(a,b))*b;
    return mcm;
}

int Suma(int num1, int num2) {
	
	int suma = num1 + num2;
	return suma;
}

int Resta(int num1, int num2) {
	
	int resta = num1 - num2;
	return resta;
}

int Producto(int num1, int num2) {
	
	int producto = num1 * num2;
	return producto;
}

double Division(double num1, double num2) {
	
	double division = num1 / num2;
	return division;
}

int main(){
	
	int un_entero, otro_entero;
	double solucion;
	char opcion;
	
	cout << "Introduzca dos enteros:\n";
	cin >> un_entero;
	cin >> otro_entero;
	
	Menu();
	cin >> opcion;
	
	switch (opcion)	{
		
		case 'm':

			solucion = MCM(un_entero, otro_entero);
			
			cout << "\nEl minimo comun multiplo de " << un_entero
			<< " y " << otro_entero << " es: " << solucion;
			
			break;
			
		case 'd':

			solucion = MCD(un_entero, otro_entero);
			
			cout << "\nEl maximo comun divisor de " << un_entero
			<< " y " << otro_entero << " es: " << solucion;
			
			break;
			
		case '+':

			solucion = Suma(un_entero, otro_entero);
			
			cout << "\nLa suma de " << un_entero
			<< " y " << otro_entero << " es: " << solucion;
			
			break;
			
		case '-':

			solucion = Resta(un_entero, otro_entero);
			
			cout << "\nLa resta de " << un_entero
			<< " y " << otro_entero << " es: " << solucion;
			
			break;
			
		case '*':

			solucion = Producto(un_entero, otro_entero);
			
			cout << "\nEl producto de " << un_entero
			<< " y " << otro_entero << " es: " << solucion;
			
			break;
			
		case '/':

			solucion = Division(un_entero, otro_entero);
			
			cout << "\nEl cociente resultante de dividir " << un_entero
			<< " entre " << otro_entero << " es: " << solucion;
			
			break;
	}
}
