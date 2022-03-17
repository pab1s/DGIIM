#include <iostream>
using namespace std;

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

int main(){
	
	int un_entero, otro_entero, minimo_comun_multiplo;
	
	cout << "Calcular el MCM de dos enteros.\n\n";
	cout << "Introduzca dos enteros: ";
	cin >> un_entero;
	cin >> otro_entero;
	
	minimo_comun_multiplo = MCM(un_entero, otro_entero);
	
	cout << "\nEl minimo comun multiplo de " << un_entero
	<< " y " << otro_entero << " es: " << minimo_comun_multiplo;
}
