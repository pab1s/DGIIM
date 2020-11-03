
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
	int chico, chico1, chico2;				//Variables a emplear en los distintos apartados según se necesiten
	long grande;					
	
	double resultado, real1, real2;
	
	double real, otro_real;
	
	float chicoG; 
	double grandeG;
	
	char opcion;							//Introduzco un caracter para seleccionar la opción
	
	cout << "Introduzca el apartado que desea comprobar (a, b, c, d, e, f o g): ";
	cin >> opcion;		
	
	if(opcion == 'a')						//Opción A
	{
		chico1 = 123456789;
		chico2 = 123456780;
		chico = chico1 * chico2;
		
		cout << "\nEl valor de chico1 es " << chico1 << " y el valor de chico2 es " << chico2;		
		cout << "\nEl resultado de la operacion es: " << chico;
		cout << "\nHa habido un desbordamiento de memoria.\n";	

		return 0;
	}
	
	if(opcion == 'b')						//Opción B
	{
		chico1 = 123456789;
		chico2 = 123456780;
		grande = chico1 * chico2;
		
		cout << "\nEl valor de chico1 es " << chico1 << " y el valor de chico2 es " << chico2;
		cout << "\nEl resultado de la operacion es: " << grande;
		cout << "\nHa habido un desbordamiento de memoria.\n";	

		return 0;
	}
	
	if(opcion == 'c')						//Opción C
	{
		real1 = 123.1;
		real2 = 124.2;
		resultado = real1 * real2;
		
		cout << "\nEl valor del real1 es " << real1 << " y el valor del real2 es " << real2;	
		cout << "\nEl resultado de la operacion es: " << resultado;	
		cout << "\nHa habido un error de precision.\n";	

		return 0;
	}
	
	if(opcion == 'd')						//Opción D
	{
		real1 = 123456789.1;
		real2 = 123456789.2;
		resultado = real1 * real2;
		
		cout << "\nEl valor del real1 es " << real1 << " y el valor del real2 es " << real2;	
		cout << "\nEl resultado de la operacion es: " << resultado;	
		cout << "\nHa habido un error de precision.\n";	

		return 0;
	}
	
	if(opcion == 'e')						//Opción E
	{
		real = 2e34;
		otro_real = real + 1; 
		
		cout << "\nValor de la variable real es " << real << " y el de otro_real es " << otro_real << "\n";
		
		otro_real = otro_real - real;
		
		cout << "\nEl resultado de la operacion es: " << otro_real;	
		cout << "\nSe ha producido un error de precision.\n";	


		return 0;
	}
	
	if(opcion == 'f')						//Opción F
	{
		real = 1e+300; 
		otro_real = 1e+200;
		
		cout << "\nValor de la variable real es " << real << " y el de otro_real es " << otro_real << "\n";
		
		otro_real = otro_real * real;
		
		cout << "\nEl resultado de la operacion es: " << otro_real;
		cout << "\nSe ha producido un error de precision.\n";
		
		return 0;	
	}	
	
	if(opcion == 'g')						//Opción G
	{
		grandeG = 2e+150; 
		chicoG = grandeG;
		
		cout << "\nValor de la variable grandeG: " << grandeG;		
		cout << "\nResultado de la operacion: " << chicoG;
		cout << "\nSe ha producido un error de precision.\n";
		
		return 0;
	}
	
	else
	{
		cout << "El caracter introducido no es una opcion.\n";

		return 0;
	}
}
