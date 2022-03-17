
#include <iostream>

using namespace std;

int main ()											//Función principal
{
	bool a, b, d, e, f, g;							//Las funciones booleanas se usarán para comprobar la veracidad de las afirmaciones de los apartados
	double c;
	
	string verdadero = "verdadero.";				//Los strings los usaremos para ahorrar memoria
	string falso = "falso.";
	
	int x, y, z;
	
	char letra;
	
	
	a = 2 + 3 < 5 + 8;											//Apartado a
	
	if(a == 1)	{
		cout << "El apartado a es " << verdadero << "\n";	
	}
	
	else	{
		cout << "El apartado a es " << falso << "\n";
	}
	
	
	b = 2 < 3 < 4;												//Apartado b
	
	if(b == 1)	{
		cout << "El apartado b es " << verdadero << "\n";
	}
	
	else	{
		cout << "El apartado b es " << falso << "\n";
	}
	
	
	c = 7/3 + 4.0;												//Apartado c (al ser una operación normal no necesita boolean)
	cout << "La solucion de c es " << c << "." << "\n";
	
	
	x = 4;
	y = 4;
	z = 4;
	
	d = x == 4 && y == 3 || z!= 2 == 1!= 2;						//Apartado d
	
	if(d == 1)	{
		cout << "El apartado d es " << verdadero << "\n";
	}
	
	else	{
		cout << "El apartado d es " << falso << "\n";
	}
	
	
	e = x <= 4 || x >= 4;										//Apartado e
	
	if(e == 1)
	{
		cout << "El apartado e es " << verdadero << "\n";
	}
	
	else	{
		cout << "El apartado e es " << falso << "\n";
	}
	
	
	f = x < 4 && x > 4;											//Apartado f
	
	if(f == 1)	{
		cout << "El apartado f es " << verdadero << "\n";
	}
	
	else	{
		cout << "El apartado f es " << falso << "\n";
	}

	
	g = (z > 6 || letra < 'z') && (letra > 'a' || z < 6);		//Apartado g
	
	if(g == 1)	{
		cout << "El apartado g es " << verdadero << "\n";
	}
	
	else	{
		cout << "El apartado g es " << falso << "\n";
	}
}
	
	
	
